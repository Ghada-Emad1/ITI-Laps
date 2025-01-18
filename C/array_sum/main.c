#include <stdio.h>
#include <stdlib.h>
#define size 5
int sum_arr(int arr[],int n);
void scan(int arr[],int n);
void print(int arr[],int n);
int main()
{
    int arr[20];

    scan(arr,size);
    printf("\n");
    print(arr,size);
    printf("\n");
    int res=sum_arr(arr,size);
    printf("sum is %d",res);

    return 0;
}
int sum_arr(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
void scan(int arr[],int n){
   for(int i=0;i<n;i++){
        printf("Enter element No.%d :",i+1);
        scanf("%d",arr+i);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("element NO.%d is %d\n",i+1,*(arr+i));
    }
}
