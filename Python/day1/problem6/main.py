import math

radius = int(input("Enter the radius : "))

area = math.pi * radius * radius
print("Area of Circle is ", round(area, 3))

circumference = 2 * math.pi * radius
print("Circumference is ", round(circumference, 3))
