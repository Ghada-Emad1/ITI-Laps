#include <stdio.h>
#include <stdlib.h>
struct emp{
    int age;
    char Name[30];
};
int g=10;
int myfun(int z,int x);
int myfun2(int *z,int *x);
void swap(int x,int y);
void swaping(int *x,int *y);
int printNum();
int main()
{

   int z=900;
   int y=100;

   printf("sum with pass by value %d\n" ,myfun(z,y));

   printf("value of z is %d and value of y is %d\n",z,y);
   printf("sum with pass by address %d\n",myfun(&z,&y));
   printf("value of z is %d and value of y is %d\n",z,y);
   swap(z,y);
   printf("swap with pass by value z= %d and y= %d\n",z,y);
   swaping(&z,&y);
   printf("swap with pass by value z= %d and y= %d\n",z,y);

   int arr[12]={1,2,3,4,5};
   int size=5;
   printf("sum of array is %d\n",sum_arr(arr,size));

   struct emp Emp[20]={{12,"ghada"},{13,"emad"}};
   printf("struct elements %d %s\n",Emp[1].age,Emp[1].Name);
   printf("Enter the elements of Array");
   for(int i=0;i<3;i++){
    scanf("%d",&Emp[i].age);
    scanf("%s",Emp[i].Name);
   }
   for(int i=0;i<3;i++){
    printf("The age is %d\n",Emp[i].age);
    printf("The Names is %s\n",Emp[i].Name);
   }
   return 0;
}
int myfun(int z,int x){
    z=100;
    x=200;
    int sum=z+x;
    return sum;
}
int myfun2(int *z,int *x){
    *z=100;
    *x=200;
    int sum=*z+*x;
    return sum;
}
void swap(int x,int y){
    int temp=x;
    x=y;
    y=temp;

}
void swaping(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int sum_arr(int *arr,int size){
     int sum=0;
    for(int i=0;i<size;i++){

        sum+=arr[i];
    }
    return sum;
}
