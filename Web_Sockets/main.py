from websocket_server import WebSocket, Server
import json
import os

clients = []
nicknames = {}


class SimpleWebSocket(WebSocket):
    def handle_message(self):
        try:
            print("Received message:", self.data)
            data = json.loads(self.data)
            user = data.get("user")
            text = data.get("text")
            if data.get("type") == "join":
                nicknames[self] = user
                self.broadcast_user_list()
                join_msg = {"user": "Server", "text": f"{user} has joined the chat."}
                self.broadcast_to_all(join_msg)

            else:
                self.broadcast_to_all(data, exclude_self=True)

        except Exception as e:
            print("Message error:", e)

    def handle_connected(self):
        clients.append(self)
        print("Client connected")

    def handle_close(self):
        clients.remove(self)
        left_user = nicknames.pop(self, "A user")

        leave_msg = {"user": "Server", "text": f"{left_user} has left the chat."}
        self.broadcast_to_all(leave_msg, exclude_self=True)
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


server = Server(host="localhost", port=8080, websocketclass=SimpleWebSocket)
server.serveforever()  # connection always open not closed
print("Simple started on ws://localhost:8080")
# every instance represent connection
