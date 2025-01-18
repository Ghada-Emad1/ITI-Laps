#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=1;i<=20;i++){
        for(int j=20;j>=i;j--){
            printf(" ");
        }
        for(int k=1;k<2*i;k++){
            printf("X");
        }
        for(int z=20;z>=i;z--){
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
