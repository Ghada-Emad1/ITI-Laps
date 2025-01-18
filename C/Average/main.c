#include <stdio.h>
#include <stdlib.h>
#define row 3
#define column 4
int main()
{
     int arr[row][column];
    int Avg[column]={0};
    for (int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("Enter element of arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
        printf("\n");
    }
    for (int i=0;i<column;i++){
        for(int j=0;j<row;j++){
                Avg[i]+=arr[j][i];
        }
        Avg[i]/=row;

    }
    for(int i=0;i<column;i++){
        printf("The summation grade of student No.%d  is:   %d\n",i+1,Avg[i]);
    }

    return 0;
}
