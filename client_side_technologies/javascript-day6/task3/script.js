/**Task3: Display the date with time on the document title (which 
changed every second to show time with date). 
Note: use .toLocalString() method of the Date Object.*/
let intervalId=setInterval(() => {
    
    let newDate=new Date();
    //console.log(newDate)
    document.title=newDate.toLocaleString();
}, 1000);
