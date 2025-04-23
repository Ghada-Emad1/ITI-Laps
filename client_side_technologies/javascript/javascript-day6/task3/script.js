/**Task3: Display the date with time on the document title (which 
changed every second to show time with date). 
Note: use .toLocalString() method of the Date Object.*/
let currentData=new Date().toLocaleString().split(",");
let hours=parseInt(currentData[1].split(":")[0]);
let minutes=parseInt(currentData[1].split(":")[1]);
let seconds=parseInt(currentData[1].split(":")[2].split(" ")[0]);
console.log(currentData)
let intervalId=setInterval(() => {
    let current=currentData[0];
     seconds+=1;
     if(seconds>=60){
        minutes+=1;
        seconds=0;
     }
     if(minutes>=60){
        hours+=1;
        minutes=0;
     }
     if(hours>=60){
        hours=0;
     }

    document.title=`${current} ${hours}:${minutes}:${seconds}`
}, 1000);
