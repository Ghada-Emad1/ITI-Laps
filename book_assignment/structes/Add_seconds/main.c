#include <stdio.h>
#include <stdlib.h>
struct time{
    int hour,minutes,second;
};
int main()
{
    struct time t1,t2,res;
    char ch;
    printf("Enter the first time : ");
    scanf("%d%c%d%c%d",&t1.hour,&ch,&t1.minutes,&ch,&t1.second);

    printf("Enter the Second time : ");
    scanf("%d%c%d%c%d",&t2.hour,&ch,&t2.minutes,&ch,&t2.second);
    res.second=t1.hour*3600+t1.minutes*60+t1.second;
    res.second+=t2.hour*3600+t2.minutes*60+t2.second;

    res.hour=res.second/3600;
    res.minutes=(res.second%3600)/60;
    res.second%=60;
    printf("The sum of t1 and t2 is %d:%d:%d",res.hour,res.minutes,res.second);
    return 0;
}
