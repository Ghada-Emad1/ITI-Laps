import { data } from "./data.js";

let bottom = document.querySelector("#bottom");
let topEl = document.querySelector("#top");
let noPrice=document.querySelector("#noPrice");
let totalPrice=0;



data.forEach((element) => {
    const createImage = document.createElement("img");
    createImage.src = element.img;
    createImage.setAttribute('price',element.price);
    createImage.draggable = true;
    createImage.id=element.quantity;
    
    createImage.addEventListener("dragstart", startDrag);
    createImage.addEventListener("dragend", endDrag);
    
    topEl.appendChild(createImage);
});


bottom.addEventListener("drop", dropped);
bottom.addEventListener("dragenter", enterDrag);
bottom.addEventListener("dragover", overDrag);

topEl.addEventListener("drop", dropped);
topEl.addEventListener("dragenter", enterDrag);
topEl.addEventListener("dragover", overDrag);

let droppedSucess=false;
function startDrag(e) {
    console.log(e.target)
    e.dataTransfer.setData("src", e.target.src);
    console.log("start drag");
    droppedSucess=false;
}
let currentPrice=0;
function endDrag(e) {
    e.preventDefault();
    
    if(droppedSucess && parseInt(e.target.id)===1){
        e.target.remove();
    }else{
        let currentQuantity=parseInt(e.target.id);
        currentQuantity-=1;
        currentPrice=parseInt(e.target.getAttribute('price')); 
   
        console.log(totalPrice);
        e.target.id=currentQuantity;
    }
    
    totalPrice+=currentPrice;
    
    console.log("end drag");
}

function dropped(e) {
    e.preventDefault();
    console.log("drop");
    const dropTarget = e.currentTarget; 
    const draggedImageSrc = e.dataTransfer.getData("src"); 
    if (dropTarget.id === "bottom") {
        console.log("in dropep",draggedImageSrc)
        addImageToContainer(bottom, draggedImageSrc);
    } else if (dropTarget.id === "top") {
        addImageToContainer(topEl, draggedImageSrc);
    }
    droppedSucess=true;
}

function addImageToContainer(container, src) {
    const newImage = document.createElement("img");
    newImage.src = src;
    newImage.draggable = true;
    newImage.addEventListener("dragstart", startDrag);
    newImage.addEventListener("dragend", endDrag);
    container.appendChild(newImage);
}

function enterDrag(e) {
    e.preventDefault();
    console.log("enter drag");
}

function overDrag(e) {
    e.preventDefault();
    console.log("over drag",e.currentTarget);
}
