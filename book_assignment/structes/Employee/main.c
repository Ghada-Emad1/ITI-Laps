#include <stdio.h>
#include <stdlib.h>
struct Emp{
    int Number;
    float compensation;
};
int main()
{
    struct Emp e[3];
    for(int i=0;i<3;i++){
        printf("print Number and compensation of employee No. %d",i+1);
        scanf("%d %f",&e[i].Number,&e[i].compensation);
    }
    for(int i=0;i<3;i++){
        printf("The Employee No.%d data is %d %.2f\n",i+1,e[i].Number,e[i].compensation);
    }
    return 0;
}
