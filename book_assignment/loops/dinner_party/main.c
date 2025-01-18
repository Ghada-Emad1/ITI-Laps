#include <stdio.h>
#include <stdlib.h>

int main()
{
    int guest,chair;
    printf("Enter Number of Guests : ");
    scanf("%d",&guest);
    printf("Enter Number of chairs : ");
    scanf("%d",&chair);
    int res=1;
    while(chair!=0){
        res*=guest;
        guest--;
        chair--;
    }
    printf("The result is %d",res);
    return 0;
}
