const CountVowels=(input)=>{
    //tolowercase 
    let count=0;

    for(let i=0;i<input.length;i++){
        if(input[i].toLowerCase()==='a'|| input[i].toLowerCase()==='e' ||input[i].toLowerCase()==='i'||input[i].toLowerCase()==='o'||input[i].toLowerCase()==='u'){
            count++;
        }
    }
    
    return count;
}
console.log("Number of vowels in string : ",CountVowels("ghAda"));

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
        if(input[i].toLowerCase()==char.toLowerCase()){
            Number_of_occurences++;
        }
    }
    return Number_of_occurences;
}
console.log("Number of Accourence in string is : ",Count_Character_Occurrences("ghaDa",'d'));


const CountWords=(input)=>{
    if(input.length===0){
        console.log("there is no word")
    }
    let count=1;
    let count_space=0;
    for(let i=0;i<input.length;i++){
        if(input[i]==' '){
            count++;
    
        } 
    }
    
    return count;
}
console.log("Number of Word in string is : ",CountWords("ghada   emad bhloul"));
