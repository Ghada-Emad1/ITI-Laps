console.log("function");
const getStudentGrades=()=>{
   let numberStudent=prompt("What is the Number of student");
   let res=0;
   if(parseInt(numberStudent)>=2 && parseInt(numberStudent)<=10){
    
    for(let i=0;i<parseInt(numberStudent);i++){
        //must take prompt in variable so you can print it.
        
        let gradeValue=prompt("Please enter Your Grade");
        if(parseInt(gradeValue)>0 && parseInt(gradeValue)<=100){
            res+=parseInt(gradeValue);
        }
        
            while(isNaN(gradeValue)){
               gradeValue=prompt("Enter the correct value"); 
                res+=0;
            }
            //res+=parseInt(gradeValue);
            console.log(gradeValue);
        // prompt value is string so i must convert it to number so it can work
        //res+=parseInt(gradeValue);
        
    }
    console.log(res);
   }else{
    alert("Error Message");
   }
   
    
       
}
getStudentGrades();
