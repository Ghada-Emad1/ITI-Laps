#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter Size of Array : ");
    scanf("%d",&size);
    int *ptr=(int *) malloc(sizeof(int)*size);
    if (ptr !=NULL){
        for(int i=0;i<size;i++){
            printf("Enter Element No. %d ",i+1);
            scanf("%d",ptr+i);
        }
        for (int i=0;i<size;i++){
            printf("Element No. %d is %d\n",i+1,ptr[i]);
        }
    }
    free(ptr);
}
