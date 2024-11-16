#include <iostream>

using namespace std;
class Time{
    int Hours;
    int Minutes;
    int Seconds;
public:
    Time(){
        Hours=Minutes=Seconds=0;
    }

    Time(int _Hours,int _minutes,int _seconds){
        Hours=_Hours;
        Minutes=_minutes;
        Seconds=_seconds;
    }
    void Display(){
        cout<<Hours<<":"<<Minutes<<":"<<Seconds<<endl;
    }
    void Add(Time t2){
         Seconds=Seconds+t2.Seconds;
        if(Seconds>60){
            Minutes+=1;
            Seconds-=60;
        }
         Minutes=Minutes+t2.Minutes;
        if(Minutes>60){
            Hours+=1;
            Minutes-=60;
        }
        Hours=Hours+t2.Hours;
    }
};
int main()
{
    Time t1(1,20,30);
    Time t2(2,20,10);

    t1.Add(t2);
    t1.Display();

    return 0;
}
