// connection is opened
const web_socket = new WebSocket("ws://localhost:8080");

// handle events
// onopen
web_socket.onopen = () => {
  console.log("Connection opened");
};
// , onmessage , onclose
web_socket.onmessage = (event) => {
  try {
    const message = JSON.parse(event.data);
    console.log("Parsed message:", message);
    if (message.type === "user_list") {
      const userListDiv = document.getElementById("user-list");

      const users = message.users;
      console.log("Users:", users);
      userListDiv.innerHTML =
        "<h5>Online Users :</h5>" +
        users.map((user) => `<div class="user">${user}</div>`).join("");
    } else if (message.user === "History") {
      showMessage(message.text, "server");
    }
    else if (message.user && message.text) {
      const fullMessage = `${message.user}: ${message.text}`;

      showMessage(fullMessage, "server");
    }
  } catch (error) {
    console.error("Failed to parse message:", error);
  }
};
web_socket.onclose = () => {
  console.log("Connection closed");
};

function sendMessage() {
  const messageBox = document.getElementById("messageBox");
  const nicknameInput = document.getElementById("nickname");
  const messageText = messageBox.value;
  const nickName = nicknameInput.value;
  const message = {
    user: nickName,
    text: messageText,
  };
  if (messageText === "") {
    alert("Please enter a message");
    return;
  }

  const fullMessage = `${nickName}: ${messageText}`;
  showMessage(fullMessage, "user");
  messageBox.value = "";
  web_socket.send(JSON.stringify(message));
}
function showMessage(message, type) {
  console.log("Message type:", type);
  const messagesDiv = document.getElementById("messages");
  const messageDiv = document.createElement("div");
  if (message.startsWith("Server:")) {
    messageDiv.classList.add("system-message");
    messageDiv.textContent = message.replace("Server: ", "");
  } else {
    messageDiv.classList.add(`${type}-message`);
    messageDiv.textContent = message;
  }
 
  messagesDiv.appendChild(messageDiv);
}

let users = [];
function goToRoom() {
  const nicknameContainer = document.querySelector(".nickname-container");
  const nickName = document.querySelector("#nickname").value;
  if (!nickName) {
    alert("Please enter a nickname");
    return;
  }
  nicknameContainer.style.display = "none";
  const chat = document.getElementById("chat-container");
  chat.style.display = "flex";

  const joinUser = {
    type: "join",
    user: nickName,
  };

  window.nickName = nickName;
  web_socket.send(JSON.stringify(joinUser));
}
window.addEventListener("beforeunload", () => {
  const leaveMsg = {
    user: "Server",
    text: `${window.nickName} has left the chat.`,
  };
  
});
