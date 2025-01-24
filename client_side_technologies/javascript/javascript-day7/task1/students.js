let studentsTable=document.querySelector("#studentsData");
let addBtn=document.querySelector("input[value=Add]");
let nameTextBox=document.querySelector("input[name=studentName]");
let gradeTextBox=document.querySelector("input[name=studentGrade]");
let nameError=document.querySelector("#nameError");
let gradeError=document.querySelector("#gradeError");
let requiredGrade=document.querySelector("#requiredGrade");
let gradeValue=document.querySelector("#gradeValue");
let captalizeName=document.querySelector("#captializeName");
let select = document.querySelector("select[name=sort]");
let filter=document.querySelector("select[name=filter]");

let studentsArray=[];
const sortStudentNames=(students)=>{
    let sortStudent=students.sort((s1,s2)=>{
        let first1=s1.name.toLowerCase();
        let first2=s2.name.toLowerCase();
        if(first1>first2)return 1;
        else if(first1<first2)return -1;
        else return 0;
    })
    return sortStudent;
}

const sortGrade=(students)=>{
    return students.sort((s1, s2) => parseInt(s2.grade)-parseInt(s1.grade));
}


const RenderTable=(students)=>{
   studentsTable.innerHTML="";
    students.forEach(element => {
      studentsTable.innerHTML+=`<tr>
      <td class="${element.department}">${element.name}</td>
      <td class="${element.department}">${element.grade}</td>
      <td class="${element.department}">${element.department}</td>
      </tr>`
   });
}
const pascalCase=(input)=>{  
    const captalize=input.split(" ").map((word)=>word[0].toUpperCase()+word.slice(1).toLowerCase()).join("");
    return captalize===input;
}

function Validate(name,grade){
    let valid=true;
    if(name===""){
        nameError.classList.add("nameError");
        valid=false;
    }else{
        nameError.classList.remove("nameError");  
    }
   
    if(grade===""){  
        requiredGrade.classList.add("gradeError");
        valid=false;
    }else{  
        requiredGrade.classList.remove("gradeError");
    }
    if(!pascalCase(name)){
    
        captalizeName.classList.add("captializeName");
        valid=false;
     }else{
         captalizeName.classList.remove("captializeName");
     }
    if(parseInt(grade)<0||parseInt(grade)>100){
       
        gradeValue.classList.add("gradeValue");
        valid=false;
    }else{
        gradeValue.classList.remove("gradeValue");  
    }
   
    if(isNaN(Number(grade))){
        
        gradeError.classList.add("gradeError");
        valid=false;
    }else{
        gradeError.classList.remove("gradeError");
    }
    
    return valid;
    
}

window.addEventListener("load",function(){
        addBtn.onclick=function(){        
            let studentObject= {
                name:nameTextBox.value,
                grade: gradeTextBox.value,
                department:document.querySelector("input[name=Department]:checked").value,
               
            };
             if(Validate(studentObject.name,studentObject.grade)){
                studentsArray.push(studentObject);
                let trElement= addStudent(studentObject,studentsArray);
               
                select.addEventListener("change", function () {
   
                    if(select.value==='name'){
                      sortStudentNames(studentsArray);
                      RenderTable(studentsArray)
                     
                    }
                    if(select.value==='success'){
                       sortGrade(studentsArray);
                       RenderTable(studentsArray);
                       
                    }
                });
                filter.addEventListener("change",function(){
                    if(filter.value==="success"){
                        let filteringSucess=studentsArray.filter((item)=>parseInt(item.grade)>50);
                        RenderTable(filteringSucess);
                    }
                    else if(filter.value==="fail"){
                        let filteringFail=studentsArray.filter((item)=>parseInt(item.grade)<=50);
                        RenderTable(filteringFail);
                    }else{
                        RenderTable(studentsArray);
                    }
                })
                if(studentObject.department==='SD'){
                    trElement.classList.add("SD");
                }else if(studentObject.department==='OS'){
                    trElement.classList.add("OS");
                }else{
                    trElement.classList.add("EL");
                }
                studentsTable.append(trElement);
                nameTextBox.value="";
                gradeTextBox.value="";
                
            }
           
            console.log("Student array in function.js",studentsArray)
            
        }
    
        
    
})


