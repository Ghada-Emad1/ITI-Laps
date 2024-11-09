#include <stdio.h>
#include <stdlib.h>
int factorial(int num);
int main()
{
    int num;
    printf("Enter the number :");
    scanf("%d",&num);
    int res=factorial(num);
    printf(" the result is %d",res);

    return 0;
}
int factorial(int num){
    int factorial=1;
    while(num!=0){
        factorial*=num;
        num--;
    }

    return factorial;
}
