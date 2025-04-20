number = int(input("Enter Your Number : "))

if number % 3 == 0 and number % 5 == 0:
    print("FizzBuzz")
elif number % 5 == 0:
    print("buzz")
elif number % 3 == 0:
    print("Fizz")
else:
    print("Number is not divided by both three or five")
