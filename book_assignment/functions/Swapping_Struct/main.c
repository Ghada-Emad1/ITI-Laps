#include <stdio.h>
#include <stdlib.h>
struct Time{
    int hours,minutes,seconds;
};
void Swapping_struct(struct Time *t1,struct Time *t2);
int main()
{
    struct Time t1,t2;
    char ch;
    printf("Enter First Format Time : ");
    scanf("%d%c%d%c%d",&t1.hours,&ch,&t1.minutes,&ch,&t1.seconds);
    printf("Enter Second Format Time : ");
    scanf("%d%c%d%c%d",&t2.hours,&ch,&t2.minutes,&ch,&t2.seconds);
    Swapping_struct(&t1,&t2);
    printf("The first Time is Now %d:%d:%d\n",t1.hours,t1.minutes,t1.seconds);
     printf("The Second Time is Now %d:%d:%d",t2.hours,t2.minutes,t2.seconds);

    return 0;
}
void Swapping_struct(struct Time *t1,struct Time *t2){
    int temp=t1->hours;
    t1->hours=t2->hours;
    t2->hours=temp;

    int temp2=t1->minutes;
    t1->minutes=t2->minutes;
    t2->minutes=temp2;

    int temp3=t1->seconds;
    t1->seconds=t2->seconds;
    t2->seconds=temp3;
}
