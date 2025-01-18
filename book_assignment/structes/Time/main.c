#include <stdio.h>
#include <stdlib.h>
struct Time{
    int hours,minutes,second;
};
int main()
{
   struct Time t1;
   char ch;
   printf("Enter Hour , minutes and seconds : ");
   scanf("%d%c%d%c%d",&t1.hours,&ch,&t1.minutes,&ch,&t1.second);
   long totalSecs=t1.hours*3600+t1.minutes*60+t1.second;
   printf("Total Seconds is %d",totalSecs);
    return 0;
}
