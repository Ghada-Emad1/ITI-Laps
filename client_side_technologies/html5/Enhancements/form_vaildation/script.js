let form = document.querySelector('form');
let firstName = document.querySelector('input[name=fname]');
let lastName = document.querySelector('input[name=lname]');
let email = document.querySelector('input[name=email]');
let dateValue=document.querySelector('input[type=date]');
let colorVlue=document.querySelector('input[type=color]');
console.log(dateValue.value,colorVlue.value);
let firstNameError = document.querySelector("#fnameError");
let lastNameError = document.querySelector("#lnameError");
let emailError = document.querySelector('#emailError');
form.addEventListener('submit', function (e) {
    e.preventDefault();
    checkInputs();
    firstName.value="";
    lastName.value="";
    email.value="";
})
function checkInputs() {
    const firstNameValue = firstName.value.trim();
    const lastNameValue = lastName.value.trim();
    const emailValue = email.value.trim();
    if (firstNameValue === "") {
        firstNameError.innerHTML = "Please Enter First Name";
        firstNameError.classList.add('error');
    } else {
        firstNameError.remove();
        firstNameError.classList.remove('error');
    }
    if (lastNameValue === "") {
        lastNameError.innerHTML = "Please Enter Last Name";
        lastNameError.classList.add('error');
    } else {
        lastNameError.remove();
        lastNameError.classList.remove('error');
    }
    if (emailValue === "") {
        emailError.innerHTML = "Please Enter Email";
        emailError.classList.add('error');
    } else if (!isEmail(emailValue)) {
        emailError.innerHTML = "Please Enter A vaild Email";
        emailError.classList.add('error');
    }

    else {
        emailError.remove();
        emailError.classList.remove('error');
    }

}

function isEmail(email) {
    return /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(email);
}

