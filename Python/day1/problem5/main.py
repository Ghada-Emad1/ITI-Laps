name=input('Enter Your String :')
res=[]
s=''
for i in range(len(name) - 1, -1, -1):
    s+=name[i]

print(s)

