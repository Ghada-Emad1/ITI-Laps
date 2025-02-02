import { data } from "./data.js";

let bottom = document.querySelector("#bottom");
let topEl = document.querySelector("#top");
let noPrice = document.querySelector("#noPrice");
let totalPrice = 0;
let draggedItem = null;
let imageStock = {}; // Track stock in store

// Initialize images and store stock
data.forEach((item) => {
    imageStock[item.img] = item.quantity; // Store initial stock

    const img = document.createElement("img");
    img.src = item.img;
    img.setAttribute("data-price", item.price);
    img.setAttribute("data-stock", item.quantity);
    img.draggable = true;

    img.addEventListener("dragstart", startDrag);
    img.addEventListener("dragend", endDrag);

    topEl.appendChild(img);
});

["top", "bottom"].forEach((id) => {
    let section = document.getElementById(id);
    section.addEventListener("dragover", (event) => event.preventDefault());
    section.addEventListener("drop", (event) => drop(event, id));
});

function startDrag(event) {
    draggedItem = event.target;
    event.dataTransfer.setData("src", draggedItem.src);
}

function drop(event, targetId) {
    event.preventDefault();
    if (!draggedItem) return;

    let imgSrc = draggedItem.src;
    let price = parseInt(draggedItem.getAttribute("data-price")) || 0;
    let stock = parseInt(draggedItem.getAttribute("data-stock")) || 1;
    let target = document.getElementById(targetId);
    let isMovingToCart = targetId === "bottom";
    let isMovingToStore = targetId === "top";

    if (isMovingToCart) {
        if (stock > 1) {
            draggedItem.setAttribute("data-stock", stock - 1);

            let clone = draggedItem.cloneNode();
            clone.setAttribute("data-stock", 1);
            clone.setAttribute("data-price", price);
            clone.draggable = true;
            clone.addEventListener("dragstart", startDrag);
            clone.addEventListener("dragend", endDrag);
            target.appendChild(clone);
        } else {
            target.appendChild(draggedItem);
        }
    } else if (isMovingToStore) {
        let original = document.querySelector(`#top img[src="${imgSrc}"]`);
        if (original) {
            let newStock = parseInt(original.getAttribute("data-stock")) + 1;
            original.setAttribute("data-stock", newStock);
        } else {
            let newImg = draggedItem.cloneNode();
            newImg.setAttribute("data-stock", 1);
            newImg.setAttribute("data-price", price);
            newImg.draggable = true;
            newImg.addEventListener("dragstart", startDrag);
            newImg.addEventListener("dragend", endDrag);
            topEl.appendChild(newImg);
        }

        draggedItem.remove();
    }

    updatePrice();
}

function endDrag(event) {
    event.preventDefault();
    draggedItem = null;
}

function updatePrice() {
    let total = 0;
    document.querySelectorAll("#bottom img").forEach((img) => {
        total += parseInt(img.getAttribute("data-price")) || 0;
    });
    noPrice.innerText = `Total Price: $${total}`;
}
