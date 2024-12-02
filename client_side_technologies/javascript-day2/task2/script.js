const CountVowels=(input)=>{
    let count=0;

    for(let i=0;i<input.length;i++){
        if(input[i]==='a'|| input[i]==='e' ||input[i]==='i'||input[i]==='o'||input[i]==='u'){
            count++;
        }
    }
    
    return count;
}
console.log("Number of vowels in string : ",CountVowels("ghada"));

"ghada emad"
const captializeWords=(input)=>{
    let captializeInput="";
    let check=false;
        for(let i=0;i<input.length;i++){
            if(!check){
                captializeInput+=input[i].toUpperCase();
                check=true;
                continue;
            }
            if(input[i]==" "){
                check=false;
                captializeInput+=input[i].toUpperCase();
            }
            captializeInput+=input[i].toLowerCase();
            
        }
    
    return captializeInput;

}
console.log(captializeWords("ghada emad"));


const Count_Character_Occurrences=(input,char)=>{
    let Number_of_occurences=0;
    for(let i=0;i<input.length;i++){
        if(input[i]==char){
            Number_of_occurences++;
        }
    }
    return Number_of_occurences;
}
console.log("Number of Accourence in string is : ",Count_Character_Occurrences("ghada",'d'));


const CountWords=(input)=>{
    if(input.length===0){
        console.log("there is no word")
    }
    let count=1;
    for(let i=0;i<input.length;i++){
        if(input[i]==' '){
            count++;
        }
    }
    return count;
}
console.log("Number of Word in string is : ",CountWords("ghada emad bhloul"));
