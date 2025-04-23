#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the Number : ");
    char ch;
    int num=0;
    for(int i=0;i<6;i++){
        scanf("%c",&ch);
        num=num*10+(ch-'0');
    }
    printf("Number is %d",num);
    return 0;
}
