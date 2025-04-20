start = int(input("Enter start : "))
length = int(input("Enter length :"))


# check
if start < length:
    new_Arr = []
    for i in range(start, length + start, 1):
        new_Arr.append(i)
    print("The Correct Array is ", new_Arr)
else:
    print("length must be greater than start")
