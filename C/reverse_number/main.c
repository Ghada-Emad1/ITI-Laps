#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;

   printf("Please Enter the number \n");
   scanf("%d",&num);

   int remainder=0;
   int rev=0;

   while(num!=0){
    remainder=num%10;
    rev=rev*10+remainder;
    num=num/10;
   }
   printf("the reverse number is %d",rev);
    return 0;
}
