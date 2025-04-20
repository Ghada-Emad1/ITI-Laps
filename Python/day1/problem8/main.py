my_str="this is iti occur iti in this iti and we are in iti"
checked_word='iti'
my_split_arr=my_str.split()
cnt=0
for i in my_split_arr:
    if(i==checked_word):
        cnt+=1

if(cnt==0):
    print('There is no word called iti in the sentence')
else:
    print(f'My Count for word {checked_word} is {cnt}')


# we can use count.

