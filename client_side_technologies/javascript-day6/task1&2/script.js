/**Task1.1get images in two ways */
let images=document.images;
let imagesWay2=document.querySelectorAll("img");
console.log(imagesWay2)
console.log(images)

/**Task1.2 find all options for city drop down list */
let options=document.querySelectorAll("option");
console.log(options)

/**Task1.3 find all rows for second table in page */
let rows=document.querySelectorAll(".bPink tr");
console.log(rows);

/**Task1.4 find all elements that contain class name fontBlue and BGrey */
let elementClass=document.querySelectorAll(".bGrey.fontBlue");
console.log(elementClass);

/**Task2.1 - Get first anchor inside the second table then change its href 
property to training.com and it's text to Training   */
let firstAnchor=document.querySelector(".bPink a");
firstAnchor.href="http://www.training.com";
firstAnchor.innerText="Training";
console.log(firstAnchor);

/**Task2.2 Find all images and change its borders to : solid pink 2px  */
let images2=document.querySelectorAll("img");
console.log(images); //return NodeList
for(let i=0;i<images.length;i++){
    images[i].style.border="2px solid pink";
}

/**Task2.3  Find all checkboxes (checked) in userData form and alert 
their values */
let findCheckBox=document.querySelector("input[type=checkbox]:checked").value;
alert(`value of Checked is ${findCheckBox}`)
console.log(findCheckBox)

/**Task2.4 - Find element with id value “example” then change it’s 
background color to pink  */
let exampleId=document.getElementById("example");
exampleId.style.backgroundColor="pink"
console.log(exampleId)