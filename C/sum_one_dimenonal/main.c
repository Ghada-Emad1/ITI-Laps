#include <stdio.h>
#include <stdlib.h>
#define size 5
int main()
{
   int arr[size];
   int sum=0;
   for(int i=0;i<size;i++){
    printf("Enter Element No.%d :",i+1);
    scanf("%d",&arr[i]);
   }
   for(int i=0;i<size;i++){
    sum+=arr[i];
   }
   int max=arr[0],min=arr[0];
   for(int i=0;i<size;i++){
    if(max<arr[i]){
        max=arr[i];
    }
    if(min>arr[i]){
        min=arr[i];
    }
   }
   printf("\nThe maximum Number is %d And The minimum Number  is %d",max,min);
   printf("\nsum of element is %d",sum);
    return 0;
}
