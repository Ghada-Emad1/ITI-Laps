let box1=document.querySelector(".box1");
let box2=document.querySelector(".box2");
let box3=document.querySelector(".box3");

window.addEventListener("load",function(){
    let clickable=true;
    function handleClick(){
    if(clickable){
        let newBox=document.createElement("div");
        if(this.className==='box1'){
            newBox.classList.add("box1");
           
        }
        if(this.className==='box2'){
            newBox.classList.add("box2");
        }
        if(this.className==='box3'){
            newBox.classList.add("box3");
        }
        
        console.log(this.className)
        this.removeEventListener("click",handleClick);
        document.body.appendChild(newBox);
        newBox.addEventListener("click",handleClick); 
    }
 }
   box1.addEventListener("click",handleClick);
   box2.addEventListener("click",handleClick);
   box3.addEventListener("click",handleClick);
      
})

