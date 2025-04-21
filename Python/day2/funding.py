import datetime
import json


def funding(user_email):
    while True:
        title = input("Enter Your Title: ")
        if not title:
            print("Please Enter a Valid Title")
            continue
        if len(title) <= 2:
            print("Title must be greater than two characters")
            continue
        break

    while True:
        details = input("Enter Your Details: ")
        if not details:
            print("Please Enter Valid Details")
            continue
        break

    while True:
        target = input("Enter The Total Target: ")
        if not target:
            print("Please Enter a Valid Number")
            continue
        if not target.isdigit():
            print("Please Enter a Numeric Value")
            continue
        target = int(target)
        if target < 0:
            print("Please Enter a Positive Number")
            continue
        break

    print("Enter End Time:")
    while True:
        try:
            year = int(input("Enter The Year: "))
            month = int(input("Enter The Month: "))
            day = int(input("Enter The Day: "))
            start_time = datetime.datetime.now().strftime("%Y-%m-%d")
            end_time = datetime.datetime(year, month, day).strftime("%Y-%m-%d")
            print(f"Start Time: {start_time}, End Time: {end_time}")
            break
        except ValueError:
            print("Please Enter Valid Date Values")
            continue

    try:
        with open("data.json", "r") as file:
            data = json.load(file)
    except FileNotFoundError:
        print("File Not Found")
        return
    except json.JSONDecodeError:
        print("Invalid JSON in 'data.json'")
        return

    print("Loaded data:", data)
    print("User email:", user_email)

    for user in data:
        print("Checking user:", user)
        if user.get("email") == user_email:
            if "funding" not in user:
                user["funding"] = []
            funding_data = {
                    "id": len(user["funding"]) + 1,
                    "title": title,
                    "details": details,
                    "target": target,
                    "start_time": start_time,
                    "end_time": end_time,
            }
            user["funding"].append(funding_data)
            break
    else:
        print("User Not Found")
        return

    with open("data.json", "w") as file:  
        json.dump(data, file, indent=4)
        print("Funding data Saved Successfully")


def getAllFunding(user_email):
    try:
        with open('data.json','r') as file:
            data= json.load(file)
    except FileNotFoundError:
        print('Data Not found')
    for user in data:
        if user.get('email')==user_email:
            for funding in user['funding']:
                print(f"Title {funding['id']} is {funding['title']} , Details {funding['details']}, Target : {funding['target']}")


def editFunding(user_email):
    try:
        with open('data.json','r') as file:
            data=json.load(file)
    except FileNotFoundError:
        print('Data is Not found')

    for user in data:
        if(user.get('email')==user_email):
            if 'funding' not in user or not user['funding']:
                print('No Funding Found')
                return
            print('Existing Funding Project')
            for funding in user['funding']:
                print(f"Title {funding['id']} is {funding['title']} , Details {funding['details']}, Target : {funding['target']}")

            break
    else:
        print("User Not Found")
        return

    try:
        funding_id=int(input('Enter The Id of Funding You Want to Edit : '))
    except ValueError:
        print('Please Enter a Valid Number')
        return
    funding_to_edit=None
    for funding in user['funding']:
        if funding['id']==funding_id :
            funding_to_edit=funding
            
        else:
            print('ID Not Found')
    if funding_to_edit is None:
        print('Funding Not Found')
        return

    while True:
        new_title = input("Enter New Tiltle : ")
        if not new_title:
            print('Please Enter a Valid Title')
            continue
        break
    while True:
        new_details = input("Enter New Details : ")
        if not new_details:
            print("Please Enter a Valid Details")
            continue
        break
    while True:
        new_target = input("Enter New Target : ")
        if not new_target:
            print("Please Enter a Valid Target")
            continue
        if not new_target.isdigit():
            print("Please Enter a Numeric Value")
            continue
        new_target = int(new_target)
        break
    print("Enter New End Date : ")

    while True:
        try:
            year = int(input("Enter The Year: "))
            if year<2025:
                print('Please Enter Future Year : ')
            
            month = int(input("Enter The Month: "))
            day = int(input("Enter The Day: "))
            new_start_time = datetime.datetime.now().strftime("%Y-%m-%d")
            new_end_time = datetime.datetime(year, month, day).strftime("%Y-%m-%d")
            print(f"Start Time: {new_start_time}, End Time: {new_end_time}")
            break
        except ValueError:
            print("Please Enter Valid Date Values")
            continue
    funding_to_edit['title']=new_title
    funding_to_edit['details']=new_details
    funding_to_edit['target']=new_target
    funding_to_edit['start_time']=new_start_time
    funding_to_edit['end_time']=new_end_time

    try:
        with open('data.json','w') as file:
            json.dump(data,file,indent=4)
            print('Funding Edited Successfully')
    except FileNotFoundError:
        print('File Not Found')
    print(funding)


def deleteFunding(user_email):
    try: 
        with open('data.json','r') as file:
            data=json.load(file)
    except FileNotFoundError:
        print('File Not Found')
        return
    for user in data:
        if user.get('email')==user_email:
            if 'funding' not in user or not user['funding']:
                print('No Funding Found')
                return
            print('Existing Funding Project')
            for funding in user['funding']:
                print(f"Title {funding['id']} is {funding['title']} , Details {funding['details']}, Target : {funding['target']}")
            break
    else:
        print("User Not Found")
        return
    try:
        funding_id = int(input("Enter The Id of Funding You Want to Delete : "))
    except ValueError:
        print("Please Enter a Valid Number")
        return
    for funding in user['funding']:
        if funding['id']==funding_id:
            user['funding'].remove(funding)
            print(user['funding'])
        else:
            print('ID Not Found')
    try:
        with open("data.json", "w") as file:
            json.dump(data, file, indent=4)
            print("Funding Deleted Successfully")
    except FileNotFoundError:
        print("File Not Found")


