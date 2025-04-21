# # firstname, lastname, email , password, confirm password ,
# # mobile
from Registeration_Login import *
from funding import *
import json


def main():
    print("1. Register")
    print("2. Login")
    choise = int(input("Choose Your Reference : "))
    if choise == 1:
        try:
            with open("data.json", "r") as file:
                data = json.load(file)
        except FileNotFoundError:
            data = []
        if not isinstance(data, list):
            print("Data is not in the expected format.")
            return
        data.append(Registeration())
        with open("data.json", "w") as file:
            json.dump(data, file, indent=4)
            print("You Successfully Registered")
    elif choise == 2:
        user_email = login()
        print(user_email)
        if user_email:
            print("Login Successfully")
            print("1. Create a Funding")
            print('2. Get All Funding')
            print("3. Edit Specific Funding")
            print("4. Delete Specific Funding")
            funding_choise = int(input("Select What You want Do with funding"))
            if funding_choise == 1:
                funding(user_email)
            elif funding_choise == 2:
                getAllFunding(user_email)
            elif funding_choise == 3:
                editFunding(user_email)
            elif funding_choise ==4:
                deleteFunding()
            else:
                print("Invalid Choise")

        else:
            print("Login Failed. Please check your email and password.")
    else:
        print("Invaild Choise")


main()
