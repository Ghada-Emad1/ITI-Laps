#include <stdio.h>
#include <stdlib.h>
void zeroSmaller(int *x,int *y);
int main()
{
    int x,y;
    printf("Enter x ");
    scanf("%d",&x);
    printf("Enter y ");
    scanf("%d",&y);
    zeroSmaller(&x,&y);
    printf("x=%d y=%d",x,y);
    return 0;
}
void zeroSmaller(int *x,int *y){
    if(*x>*y){
        *y=0;
    }else{
        *x=0;
    }
}
