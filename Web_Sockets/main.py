from websocket_server import WebSocket, Server
import json
import os
clients = []
nicknames = {}


class SimpleWebSocket(WebSocket):
    def handle_message(self):
        try:
            data = json.loads(self.data)
            user = data.get("user")
            text = data.get("text")

            if data.get("type") == "join":
                nicknames[self] = user
                self.send_chat_history()
                self.broadcast_user_list()
                join_msg = {"user": "Server", "text": f"{user} has joined the chat."}
                self.broadcast_to_all(join_msg)
                self.save_chat(f"Server : {user} has joined the chat.")
            else:
                
                self.broadcast_to_all(data, exclude_self=True)
                self.save_chat(f"{user} : {text}")

        except Exception as e:
            print("Message error:", e)

    def handle_connected(self):
        clients.append(self)
        print("Client connected")

    def handle_close(self):
        clients.remove(self)
        left_user = nicknames.pop(self, "A user")

        leave_msg = {"user": "Server", "text": f"{left_user} has left the chat."}
        self.broadcast_to_all(leave_msg,exclude_self=True)
        self.save_chat(f"Server : {left_user} has left the chat.")
        self.broadcast_user_list()

    def broadcast_to_all(self, message, exclude_self=False):
        if isinstance(message, dict):
            message = json.dumps(message)
        for client in clients:
            if exclude_self and client == self:
                continue
            client.send_message(message)

    def broadcast_user_list(self):
        user_list_msg = {"type": "user_list", "users": list(nicknames.values())}
        self.broadcast_to_all(user_list_msg)

    def send_chat_history(self):
        if not os.path.exists("chat_history.txt"):
            return
        with open("chat_history.txt", "r",encoding='utf-8') as f:
            for line in f:
                msg={
                    "user":"History",
                    "text": line.strip()
                }
                self.send_message(json.dumps(msg))
    def save_chat(self,message):
        with open("chat_history.txt", "a",encoding='utf-8') as f:
            f.write(message+"\n")
            


server = Server(host="localhost", port=8080, websocketclass=SimpleWebSocket)
server.serveforever()  # connection always open not closed
print("Simple started on ws://localhost:8080")
# every instance represent connection
