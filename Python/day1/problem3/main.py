current_arr = []

for i in range(5):
    number = int(input(f"Enter the number {i+1}: "))
    current_arr.append(number)

copy_list = current_arr[:]

# sorted built-in 
print("My Current Array", current_arr)

current_arr.sort()
print("Acending Array is : ", current_arr)

current_arr.sort(reverse=True)
print("Descending Array is", current_arr)
