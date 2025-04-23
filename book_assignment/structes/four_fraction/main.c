#include <stdio.h>
#include <stdlib.h>
struct fraction{
    int num,den;
};
int main()
{
    struct fraction f1,f2,res;
    char ch,div;
    printf("Enter the fraction and operators : ");
    scanf("%d%c%d%c%d%c%d",&f1.num,&div,&f1.den,&ch,&f2.num,&div,&f2.den);
    switch(ch){
    case '+':
        res.num=f1.num*f2.den+f2.num*f1.den;
        res.den=f1.den*f2.den;
        break;
    case '-':
        res.num=f1.num*f2.den-f2.num*f1.den;
        res.den=f1.den*f2.den;
        break;
    case '*':
        res.num=f1.num*f2.num;
        res.den=f1.den*f2.den;
        break;
    }
    printf("Result is %d/%d",res.num,res.den);
    return 0;
}
