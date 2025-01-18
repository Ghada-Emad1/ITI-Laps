#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    char op;
    printf("Enter the operation \n");
    scanf("%c",&op);
    printf("Enter The first Number \n");
    scanf("%d",&num1);
    printf("Enter the second Number \n");
    scanf("%d",&num2);

    switch(op){
    case '+':
        printf("the summation is :%d",num1+num2);
        break;
    case '-':
        printf("The substration is :%d",num1-num2);
        break;
    case '*':
        printf("The multiplication is :%d",num1*num2);
        break;
    case '/':
        printf("The division is :%d",num1/num2);
        break;
    default:
        printf("Not vaild Operator");
        break;
    }
    return 0;
}
