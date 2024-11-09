#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct emp{
    char name[40];
    float salary;
    int id;
};
int main()
{
    int x=10;
    int*ptrx=&x;

    int y=20;
    int*ptry=&y;

    ptrx=ptry;
    *ptrx=30;
   /* &ptry=9000;*/ //compilation error .
   ptrx=ptrx+2;
    printf("%p %p %p %d %d \n",ptry+6,ptrx,ptry,x,y);

    char ch='s';
    int *ptrch=&ch;
    *ptrch='o';
    printf("%p %p %d %d\n",&ch,ptrch,ch,*ptrch);

    int a=90;
    char *ptra=&a;
    printf("%p %p %d %d\n",ptra,&a,a,*ptra);

    int arr[50];
    int* ptrarr=arr;
    /*for(int i=0;i<5;i++){
        scanf("%d",&(ptrarr[i]));
    }
    printf("%p %p %p %p %d %d\n",ptrarr,arr,&arr[0],&ptrarr,*ptrarr,*arr);
    for(int i=0;i<5;i++){
        printf("%d %d %d\n",*(ptrarr+i),*(arr+i),arr[i]);
    }*/

    struct emp e1={"ghada",123.9,3};
    struct emp e2;
    e2=e1;
    e2.id=9;
    printf("%d %d",e1.id,e2.id);

    return 0;
}
