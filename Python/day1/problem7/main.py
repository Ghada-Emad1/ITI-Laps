import re


while True:
    name=input('Enter Your Name : ')
    if not name:
      print('Please Enter Your Name')
      continue
    if any (char.isdigit() for char in name):
          print('Please Enter vaild  Name')
          continue

    break
while True:
    email = input('Enter Your Email: ')
    if email == '':
        print('Please Enter Your Email')
        continue
    vaild_email = re.match(r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$', email)
    if not vaild_email:
        print('Please Enter a Valid Email')
        continue
    break


print(f'Your Name is {name} and Your Email is {email}')