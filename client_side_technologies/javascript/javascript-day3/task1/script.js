//task1
let grades=[85,92,78,90,87,61,73];
const AverageGrade=(input)=>{
    return input.reduce((acc,cur)=>(acc+cur))/input.length;
}
console.log("Average of grades using reduce function : ",AverageGrade(grades));
/** task2 */
let avg;
let sum=0;
for(let i=0;i<grades.length;i++){
   
    sum+=grades[i];
    avg=sum/grades.length;
    
}
console.log(avg)

/** task3 */
const GetMax=(input)=>{
    let max=input[0];
    for(let i=0;i<grades.length;i++){
        if(grades[i]>max){
           max=grades[i];
        }
        
    }
    return max;
}
console.log("Maximum Value in Grades is : ",GetMax(grades));

/** task4 */
const GetMin=(input)=>{
    let min=input[0];
    for(let i=0;i<grades.length;i++){
        if(grades[i]<min){
           min=grades[i];
        } 
    }
    return min;
}
console.log("Minimum Value in Grades is : ",GetMin(grades));

/**Task5 : Replace Grades*/
[1,2,3,4,5]
const Replace=(grades,searchItem,findItem)=>{
    let search=grades.indexOf(searchItem);
    grades.splice(search,0,findItem); 
    return grades;
}

console.log("Replace Number : ",Replace(grades,92,90))

/**Task6 : Sort grades Array in ascending order */
grades.sort((a,b)=>a-b);
console.log("Sorting Array :",grades);

/**Task7: find students grades grater than or equal 60 */
const FilterSecessStudents=grades.filter(item=>item>=60);

console.log("Filter Secess Student",FilterSecessStudents);
const successStudents=(grades,condition)=>{
    let res=[];
    for(let index in grades){
        if(condition(grades[index],index)){
            res.push(grades[index]);
            
        }
    }  
    return res;

}
console.log("Student that lower than 60",successStudents(grades,grade=>grade>=60));


/**Task8: Convert Grades to percentage array */
const PercentageGrades=(input)=>{
    let res=[];
    for(let i=0;i<input.length;i++){
        res.push(input[i] +"%");
    }
    return res;
}

console.log("Percentage of Grades",PercentageGrades(grades));

/**Task9: convert grades array to a sperated by comma and print it */
let commaGrades=grades.join(",");
console.log("Sperate grades by comma and print it as string",commaGrades)

/**Task10: create Array */
let names=["Elina","ahmed","Mona","eman","Ali","maha","zayed"];
/**Task11 : sort Names */
const SortNames=names.sort((s1,s2)=>{
    let firstName=s1.toLowerCase();
    let secondName=s2.toLowerCase();
    if(firstName>secondName){
        return 1
    }else if(firstName<secondName){
        return -1;
    }else{
        return 0;
    }
    
});
console.log("Sort Names : ",SortNames)

/**Task12: function that return pascal case*/
const PascalCase=(input)=>{
    let stringArray=input.split(" ");
    let res="";
    for(let i=0;i<stringArray.length;i++){
        res+=stringArray[i][0].toUpperCase()+stringArray[i].slice(1).toLowerCase();
    }
    return res;
}
console.log("Pascal Name is : ",PascalCase("ghada emad")) ;
/** Task13: Pascal case using map */
const MapPascalCase=(input)=>{
    return input.split(" ").map((word)=>word[0].toUpperCase()+word.slice(1).toLowerCase()).join("");
}
console.log("Map Pascal Case : ",MapPascalCase("ghada emad"))


/** Task14: find student with 4 or more letters */
let findStudent=names.find((student)=>{
    return student.length>=4
})
console.log("Student found : ",findStudent)

/**Task15: Combine Student with grades */
const MapNamesGrade=(names,grades)=>{
    return names.map((item,index)=>`${item} ${grades[index]}`)
}
console.log("combine names and grades using map",MapNamesGrade(names,grades));
const CombineGradeNames=(names,grades)=>{
    let res=[];
    for(let i=0;i<grades.length;i++){ 
        res.push(names[i]+" "+grades[i]);
    }
    return res;
}
console.log("Combine names with grades : ",CombineGradeNames(names,grades));

/** insert CombineGradeNames inside arr */
const ArrayCombineGradeNames=(names,grades)=>{
   let res=[];
   for(let i=0;i<grades.length;i++){
       res.push([names[i],grades[i]]);
   }
   return res;
}
console.log("Combine Names with Grade : ",ArrayCombineGradeNames(names,grades))
const MapArrayCombineGradeNames=(names,grades)=>{
    return names.map((item,index)=>[item,grades[index]])
}

console.log("Combine Names with Grades using map",MapArrayCombineGradeNames(names,grades))
