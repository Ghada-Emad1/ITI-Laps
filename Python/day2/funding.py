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

    funding_data = {
        "title": title,
        "details": details,
        "target": target,
        "start_time": start_time,
        "end_time": end_time,
    }

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
        if user.get('email') == user_email:
            if 'funding' not in user:
                user['funding'] = []
            user['funding'].append(funding_data)
            break
    else:
        print('User Not Found')
        return

    with open('data.json', 'w') as file:  # Save back to data.json
        json.dump(data, file, indent=4)
        print('Funding data Saved Successfully')