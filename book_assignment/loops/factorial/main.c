#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    do{
        int factoral=1;
        printf("Enter the Number :");
        scanf("%d",&num);
        for(int i=1;i<=num;++i){
            factoral*=i;
        }
        printf("Factorial is %d\n",factoral);
    }while(num!=0);
    return 0;
}
