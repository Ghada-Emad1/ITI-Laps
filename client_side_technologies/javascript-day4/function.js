const registerStudents=function(){
    /** 1 */
        let firstName=prompt("Enter Your Name");
        let lastName=prompt("Enter last Name");
        let age=parseInt(prompt("Enter Your Age"));
        let email=prompt("Enter Your Email");
        let departement=prompt("Enter Your Department");
        student_data={
            firstName,
            lastName,
            age,
            email,
            departement,
            toString:function(){
                return firstName+" "+lastName;
            }
        };
        return student_data;
}
let students=[];
const studentCollection=()=>{
    for(let i=0;i<2;i++){
        let student=registerStudents();
        students.push(student);
    }
    return students;
}

/**3.find the oldest student fullName */
const oldestStudentFullName=()=>{
    let maxValue=Math.max(...students.map((p)=>p.age));
    let oldestStudent=students.find((item)=>item.age===maxValue);
    let fullName=oldestStudent.firstName+" "+oldestStudent.lastName;  
    return fullName;

}
/**4.convet first and last name into pascal case */
const pascalCase=(input)=>{  
    return input.split(" ").map((word)=>word[0].toUpperCase()+word.slice(1).toLowerCase()).join("");
}
const pascalStudentNames=()=>{
    let student=students.map((item)=>{
        const firstName=pascalCase(item.firstName);
        const lastName=pascalCase(item.lastName);
        return{
            ...item,
                firstName,lastName,
                fullName:firstName+lastName
        }
        
    })
    return student;
}


/**5.Find all student with ages greater than 20 */
const studentAgeGreaterThan20=()=>{
    return students.filter((item)=>item.age>20);
}

/**6. get the average of all students */
const averageStudentAge=()=>{
    return students.reduce((acc,cur)=>acc.age+cur.age)/students.length;

}


/**7.Sort students ascending */
const sortStudentNames=()=>{
    let sortStudent=students.sort((s1,s2)=>{
        let first1=s1.firstName.toLowerCase();
        let first2=s2.firstName.toLowerCase();
    
        let second1=s1.lastName.toLowerCase();
        let second2=s2.lastName.toLowerCase();
        if(first1>first2 ||(first1===first1&&second1>second2))return 1;
        else if(first1<first2 || (first1===first1&&second1<second2))return -1;
        else return 0;
    })
    return sortStudent;
}
/**8.Generate a new array contains fullName and age */
let newStudentCollection=[];
const newStudent=()=>{
    newStudentCollection=students.map((item)=>{
        const firsName=pascalCase(item.firstName);
        const lastName=pascalCase(item.lastName);
        return{
            fullName:firsName+" "+lastName,
            age:item.age
        }
    })
    return newStudentCollection;
    
}

/**11.Convert Array to JSON */
const convertArrayToJson=()=>{
    return JSON.stringify(students);
}