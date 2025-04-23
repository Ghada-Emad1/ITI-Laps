#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter the number");
    int cnt=0;
    scanf("%d",&num);
    for(int i=1;i<num;i++){
        cnt=0;
        for(int j=2;j<i;j++){
            if(i%j==0){
                cnt++;
                /*break;*/
            }
        }
        if(cnt<1){
            printf("%d\t",i);
        }
    }


    return 0;
}
