#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("Enter Value of X = ");
    scanf("%d",&x);
    printf("Enter Value of y = ");
    scanf("%d",&y);
    swapping(&x,&y);
    printf("Value of x = %d , Value of y = %d",x,y);
    return 0;
}
void swapping(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
