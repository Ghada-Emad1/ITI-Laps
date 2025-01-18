#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x1,x2,x3,x4,x5;
   int sum=0;
   printf("Enter the first number\n");
   scanf("%d",&x1);
   printf("Enter the second number \n");
   scanf("%d",&x2);
   printf("Enter the third number \n");
   scanf("%d",&x3);
   printf("Enter the fourth number \n");
   scanf("%d",&x4);
   printf("Enter the fifth number\n");
   scanf("%d",&x5);
   sum=x1+x2+x3+x4+x5;
   printf("The summation is %d",sum);
    return 0;
}
