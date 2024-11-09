#include <stdio.h>
#include <stdlib.h>
struct fraction{
    int num,den;
};
struct fraction fadd(struct fraction f1,struct fraction f2);
struct fraction fsub(struct fraction f1,struct fraction f2);
struct fraction fmult(struct fraction f1,struct fraction f2);
int main()
{
    struct fraction f1,f2,res;
    char ch;
    printf("Enter First fraction : ");
    scanf("%d%c%d",&f1.num,&ch,&f1.den);
    printf("Enter Second fraction : ");
    scanf("%d%c%d",&f2.num,&ch,&f2.den);
    res=fadd(f1,f2);
    printf("The Summation is %d/%d \n",res.num,res.den);
    res=fsub(f1,f2);
    printf("The Subtraction is %d/%d\n",res.num,res.den);
    res=fmult(f1,f2);
    printf("The Multiplication is %d/%d",res.num,res.den);
    return 0;
}
struct fraction fadd(struct fraction f1,struct fraction f2){
    struct fraction res;
    res.num=f1.num*f2.den+f2.num*f1.den;
    res.den=f1.den*f2.den;
    return res;

}
struct fraction fsub(struct fraction f1,struct fraction f2){
    struct fraction res;
    res.num=f1.num*f2.den-f2.num*f1.den;
    res.den=f1.den*f2.den;
    return res;

}
struct fraction fmult(struct fraction f1,struct fraction f2){
    struct fraction res;
    res.num=f1.num*f2.num;
    res.den=f1.den*f2.den;
    return res;

}
