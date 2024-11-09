#include <stdio.h>
#include <stdlib.h>
struct date{
    int day;
    int month;
    int year;
};
int main()
{
    struct date D1;
    char ch;
    printf("Enter the Date: ");
    scanf("%d%c%d%c%d",&D1.month,&ch,&D1.day,&ch,&D1.year);
    printf("The Date is %d%c%d%c%d",D1.month,ch,D1.day,ch,D1.year);
    return 0;
}
