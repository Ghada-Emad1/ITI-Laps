#include <stdio.h>
#include <stdlib.h>

int main()
{
   int degree;
   printf("Enter Your Degree :");
   scanf("%d",&degree);
   if (degree>=85){
    printf("Exellent");
   }else if(degree >=75){
   printf("very Good");
   }else if(degree >=65){
   printf("Good");
   }else if(degree >=60){
       printf("Accepted");
   }else{
   printf("Fail");
   }
    return 0;
}
