#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Enter The X and Y :");
    scanf("%d %d",&a,&b);
    int res=swapping(&a,&b);
    printf("x= %d , y=%d",a,b);

    return 0;
}
void swapping(int* x,int* y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}
