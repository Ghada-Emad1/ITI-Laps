email = input("Enter Your Email: ")
password = input("Enter Your Password: ")

import json

with open("data.json", "r") as file:
    data = json.load(file)

for field in data:
    if field.get('email')==email and field.get('password')==password:
        print('exist email and password')
        print(field)
        break

    





