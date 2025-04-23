#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   printf("enter the number\n");
   scanf("%d",&num);
   int factorial=1;
   while(num!=0){
    factorial*=num;
    num--;
   }
   printf("the factorial is %d",factorial);
    return 0;
}
