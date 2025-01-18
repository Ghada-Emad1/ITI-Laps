#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[100];
    int* ptrn=nums;

    for(int i=0;i<5;i++){
        printf("Enter the element No.%d: ",i+1);
        scanf("%d",ptrn+i);
    }
    for(int i=0;i<5;i++){
        printf("The element No.%d is :%d\n",i+1,ptrn[i]);
    }
    return 0;
}
