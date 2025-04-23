#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,num,den;
    char ch,div;
    printf("Enter first fraction :");
    scanf("%d %c %d",&a,&div,&b);
    printf("Enter the operand :");
    ch=_getch();
    printf("%c",ch);
    printf("Enter the second fraction : \n");
    scanf("%d %c %d",&c,&div,&d);
    do{
    switch(ch){
    case '+':
        num=(a*d + b*c);
        den=(b*d);
        printf("The summation is %d / %d\n",num,den);
        break;
    case '-':
        num=(a*d - b*c);
        den=(b*d);
        printf("The subtraction is %d / %d\n",num,den);
        break;
    case '*':
        num=(a*c);
        den= (b*d);
        printf("The multiplication is %d / %d\n",num,den);
        break;
    case '/':
        num=(a*d);
        den= (b*c);
        printf("The division is %d / %d\n",num,den);
        break;
    }
     printf("Do You wanna another (y/n)? ");
     scanf("%c",&ch);
    }while(ch!='n');

    return 0;
}
