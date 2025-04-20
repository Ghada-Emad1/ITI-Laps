name = input("Enter Your Name : ")
count = 0

for i in name.lower():
    if i in "aeiou":
        count += 1

print("Number of vowels in name is : ", count)
