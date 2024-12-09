let collectImages=[
    {img:"images/1.jpg"},
    {img:"images/2.jpg"},
    {img:"images/3.jpg"}
]
let createImg=document.createElement("img");
document.body.appendChild(createImg);
createImg.style.width="500px";
let index=0;
function startSliding(collectImages){
    let intervalId=setInterval(() => {
       
        createImg.src=collectImages[index].img;
        // console.log(createImg)
       index=(index+1)%collectImages.length;
       console.log(index)
    },1000);
    return intervalId;
}
function stopSliding(timerId) {
    clearInterval(timerId); 
}
let slider=startSliding(collectImages)

setTimeout(() => stopSliding(slider), 5000);


