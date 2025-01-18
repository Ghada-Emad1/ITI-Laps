#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter The Number :");
    scanf("%d",&num);
    int multi=1;
    int arr[20][10];
    for(int i=0;i<20;i++){
        for(int j=0;j<10;j++){

            arr[i][j]=num*multi;
            multi++;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
