import re
import json


def Registeration():
    while True:
        first_name = input("Enter Your First Name : ")
        if not first_name:
            print("Please Enter Your Name")
            continue
        if any(char.isdigit() for char in first_name):
            print("Please Enter vaild  Name")
            continue
        break

    while True:
        last_name = input("Enter Your Last Name : ")
        if not last_name:
            print("Please Enter Your Name")
            continue
        if any(char.isdigit() for char in last_name):
            print("Please Enter vaild  Name")
            continue
        break

    while True:
        email = input("Enter Your Email: ")
        if not email:
            print("Please Enter Your Email")
            continue
        vaild_email = re.match(
            r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$", email
        )
        if not vaild_email:
            print("Please Enter a Valid Email")
            continue
        break
    while True:
        password = input("Enter Your Password: ")
        if not password:
            print("Please Enter Your Password")
            continue
        if len(password) < 6:
            print("Please Enter password greater than 6")
            continue
        break
    while True:
        confirm_password = input("Confirm Your Password ")
        if password != confirm_password:
            print("The Password Not Match Please Enter Your Password Again ")
            continue
        if password == confirm_password:
            print("The Password is Correct")
        break
    while True:
        mobile = input("Enter Your Mobile Number : ")
        if not mobile:
            print("Please Enter Your Mobile Number")
            continue
        vaild_mobile = re.match(r"^(?:\+20|0020|0)?1[0125]\d{8}$", mobile)
        if not vaild_mobile:
            print("Please Enter a Valid Mobile Number")
            continue
        break
    return {
        "firstname": first_name,
        "lastname": last_name,
        "email": email,
        "password": password,
        "mobile": mobile,
    }


def login():
    while True:
        email = input("Enter Your Email: ")
        if not email:
            print("Please Enter Your Email")
            continue
        break

    while True:
        password = input("Enter Your Password: ")
        if not password:
            print("Please Enter Your Password")
            continue
        break
    try:
        with open("data.json", "r") as file:
            data = json.load(file)
    except FileNotFoundError:
        print("The file 'data.json' does not exist.")
        return False
    except json.JSONDecodeError:
        print("The file 'data.json' contains invalid JSON.")
        return False
    for field in data:
        if field.get("email") == email and field.get("password") == password:
            print("exist email and password")
            print(
                f'user data is firstname {field.get("firstname")}, lastname {field.get("lastname")}, email {field.get("email")}, password {field.get("password")}, mobile {field.get("mobile")}'
            )
            return email
    print("The Email or Password is not Correct")
    return False
