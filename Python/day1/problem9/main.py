
name=input('Enter Your Name : ')

s=''
res=[]
for i in range(0,len(name)):
    print(name[i])
    if(name[i]<name[i+1]):
        s+=name[i]
        res.append(s)


