#include <stdio.h>
#include <stdlib.h>
void hms_to_secs(int hours,int minutes,int seconds);
int main()
{
    char ch;
    int hours,minutes,seconds;
    printf("Enter the Hour , Minutes and Seconds : ");
    scanf("%d%c%d%c%d",&hours,&ch,&minutes,&ch,&seconds);
    hms_to_secs(hours,minutes,seconds);
    return 0;
}
void hms_to_secs(int hours,int minutes,int seconds){
    char ch;
    do{
        long Total_second=hours*3600+minutes*60+seconds;
        printf("The Total seconds is %d\n",Total_second);
        printf("Do you to Enter New Values (y,n) ?");
        scanf(" %c",&ch);
    }while(ch!='n');
}
