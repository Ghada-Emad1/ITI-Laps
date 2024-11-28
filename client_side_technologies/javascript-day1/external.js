number1=90;
console.log(typeof(number1)); //number
/** when we print number1 in console it will print cause 
 * cause when we declare variable as var it will be global variable 
 * so i can access it from any where
 * 
 */
/**
 * when we remove var keywork it will not affect if i print it 
 * 
 */
console.log("from external number 1 = ",number1);

let number2=9.9;
console.log(typeof(number2)); //number
const number3="ghada";
console.log(typeof(number3)); //string

{
    let number4=12;
    console.log("in scope ",number4);
}
console.log(number4); //make expection canse number4 defined as let datatype only in it's scope , so i can't access it outside of it is scope
var firstName="ghada";
/**
 * f- try to change your firstName character at index 3 
 * it will not affect the original variable and it will be the same
 * change index don't affect the original string.
 */
firstName[3]='e';
console.log(firstName[3]);
console.log(firstName);
var middleName=' emad';
var lastName=` Bhloul`;
var flag=true;
console.log("This is the External Javascript file")
/**
 * e- if we change number1 ,number2 and number3 on developer tool
 * it will only affect the console on the browser
 * but not affect variable on my local device
 * and if i refersh the browser it will return to the original value
 * 
 */