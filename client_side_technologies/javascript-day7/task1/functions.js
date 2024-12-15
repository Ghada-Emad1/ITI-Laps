let getErrorName=document.querySelector("span");
let img="../images/delete.png";


const addStudent=function(student){
    
    let trObject=document.createElement("tr");
    let tdObject=null;

    for(let proprty in student)
    {

        tdObject=document.createElement("td");
        tdObject.innerText=student[proprty];
        trObject.appendChild(tdObject);
    }
    let deleteTd=document.createElement("td");
    let createImg=document.createElement("img");
    createImg.src=img;
    createImg.classList.add("deleteImg");
    createImg.alt="Delete";
    
    createImg.addEventListener("click",function(){
       
        let studentIndex = studentsArray.length - 1;
        console.log(studentIndex)
        trObject.remove();

        studentsArray.splice(studentIndex, 1);
        console.log("Updated students array:", studentsArray);
    })
    deleteTd.appendChild(createImg);
    trObject.appendChild(deleteTd);
   
    
    return trObject;


}