# # firstname, lastname, email , password, confirm password ,
# # mobile
from Registeration_Login import *
from funding import funding
import json
def main():
    print('1. Register')
    print('2. Login')
    choise=int(input('Choose Your Reference : '))
    if choise==1:
        try:
            with open("data.json", "r") as file:
                data = json.load(file)
        except FileNotFoundError:
            data = []
        if not isinstance(data,list):
            print("Data is not in the expected format.")
            return
        data.append(Registeration())
        with open("data.json", "w") as file:
            json.dump(data, file, indent=4)
            print("You Successfully Registered")
    elif choise==2:
        user_email=login()
        print(user_email)
        if user_email:
            print('Login Successfully')
            funding(user_email)
        else:
            print('Login Failed. Please check your email and password.')
    else:
        print('Invaild Choise')
       


    
     
main()




