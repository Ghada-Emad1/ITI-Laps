#include <stdio.h>
#include <stdlib.h>
struct fraction{
    int num;
    int den;
};
int main()
{
    struct fraction f1,f2,sum;
    char ch;
    printf("Enter first fraction : ");
    scanf("%d %c %d",&f1.num,&ch,&f1.den);

    printf("Enter second fraction : ");
    scanf("%d %ch %d",&f2.num,&ch,&f2.den);

    sum.num=f1.num*f2.den +f1.den * f2.num;
    sum.den=f1.den * f2.den;

    printf("The Result  is %d / %d",sum.num,sum.den);
    return 0;
}
