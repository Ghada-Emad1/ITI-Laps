#include <stdio.h>
#include <stdlib.h>
struct time{
    int hours,minutes,seconds;
};
long time_to_secs(struct time);
struct time secs_to_time(long seconds);
int main()
{
    struct time t1;
    char ch;
    long seconds;
    printf("Enter Hour , minutes and seconds To Convert to seconds : ");
    scanf("%d%c%d%c%d",&t1.hours,&ch,&t1.minutes,&ch,&t1.seconds);
    printf("The Seconds is %d \n",time_to_secs(t1));
    printf("Enter Seconds To Covert it To Hours, Minutes and seconds : ");
    scanf("%d",&seconds);
    printf("The Time Format is %d:%d:%d ",secs_to_time(seconds));
    return 0;
}
long time_to_secs(struct time t){
    return t.hours*3600+t.minutes*60+t.seconds;
}
struct time secs_to_time(long seconds){
    struct time t1;
    t1.hours=seconds/3600;
    t1.minutes=(seconds%3600)/60;
    seconds%=60;
    t1.seconds=seconds;
    return t1;
};
