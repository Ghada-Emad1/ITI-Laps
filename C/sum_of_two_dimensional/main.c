#include <stdio.h>
#include <stdlib.h>
#define row 3
#define column 4
int main()
{
    int arr[row][column];
    int sum[row]={0};
    for (int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("Enter element of arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
        printf("\n");
    }
    for (int i=0;i<row;i++){
        for(int j=0;j<column;j++){
                sum[i]+=arr[i][j];
        }
    }
    for(int i=0;i<row;i++){
        printf("The summation grade of student No.%d  is:   %d\n",i+1,sum[i]);
    }

    return 0;
}
