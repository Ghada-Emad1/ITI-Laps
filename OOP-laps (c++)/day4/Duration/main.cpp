#include <iostream>

using namespace std;
class Duration{
    int hours;
    int minutes;
    int seconds;
public:
    Duration(){
        hours=0;
        seconds=0;
        minutes=0;
    }
    Duration(int _hours,int _minutes,int _seconds){
        hours=_hours;
        minutes=_minutes;
        seconds=_seconds;
    }
    Duration (int _seconds){
       hours=_seconds/3600;
       minutes=(_seconds%3600)/60;
       _seconds%=60;
       seconds=_seconds;
    }
    void setHours(int _hours){
        hours=_hours;
    }
    void setMinutes(int _minutes){
        minutes=_minutes;
    }
    void setSeconds(int _seconds){
        seconds=_seconds;
    }
    int getHours(){
        return hours;
    }
    int getMinutes(){
        return minutes;
    }
    int getSeonds(){
        return seconds;
    }
    Duration operator +(Duration d){
        Duration res;
        res.seconds=hours*3600+minutes*60+seconds;
        res.seconds+=d.hours*3600+d.minutes*60+d.seconds;

        res.hours=res.seconds/3600;
        res.minutes=(res.seconds%3600)/60;
        res.seconds%=60;
        return res;
    }
    Duration operator +(int x){
        Duration res;
        res.seconds=hours*3600+minutes*60+seconds+x;
        res.hours=res.seconds/3600;
        res.minutes=(res.seconds%3600)/60;
        res.seconds%=60;
        return res;

    }
    Duration operator ++(int){
        Duration temp=*this;
        minutes+=1;
        if(minutes>=60){
            minutes-=60;
            hours+=1;
        }
        return temp;
    }
    Duration operator --(int){
        Duration temp=*this;
        minutes-=1;

        return temp;
    }
    int operator > (Duration d){
        if(hours>d.hours &&minutes>d.minutes && seconds>d.seconds){
            return 1;
        }
        else return 0;
    }
    int operator <=(Duration d){
        if(hours<=d.hours && minutes<=d.minutes && seconds<=d.seconds ){
            return 1;
        }else{
            return 0;
        }
    }
    void print(){
       if (hours == 0) {
            cout << "Minutes : " << minutes << ", Seconds : " << seconds << endl;
        } else {
            cout << "Hours : " << hours << ", Minutes : " << minutes << ", Seconds : " << seconds << endl;
        }
    }
    friend Duration operator+(int x,Duration d);

};
Duration operator+(int x,Duration d){
    Duration res;
    res.seconds=d.hours*3600+d.minutes*60+d.seconds+x;
    res.hours=res.seconds/3600;
    res.minutes=(res.seconds%3600)/60;
    res.seconds%=60;
    return res;
}
int main()
{
    Duration d;
    d.setHours(1);
    d.setMinutes(30);
    d.setSeconds(20);
    d.print();
    cout<<"--------------------------------"<<endl;
    Duration *D=new Duration(1,10,15);
    D->print();
    cout<<"--------------------------------"<<endl;
    Duration D1(3600);
    D1.print();
    cout<<"--------------------------------"<<endl;
    Duration D2(7800);
    D2.print();
    cout<<"--------------------------------"<<endl;
    Duration D3(666);
    D3.print();
    cout<<endl;
    cout<<"-------- overload operator -------- "<<endl;
    cout<<endl;
    cout<<"Adding Two Durations ----------------"<<endl;
    Duration D4=D1+D2;
    D4.print();
    cout<<"Add Duration with seconds-----------------"<<endl;
    Duration D5=D1+7800;
    D5.print();

    cout<<"Add seconds with Duration--------------"<<endl;
    Duration D6=666+D1;
    D6.print();
    cout<<"Adding one Minutes ---------------"<<endl;
    D1++;
    D1.print();
    D1--;
    D1.print();
    if(D1>D2){
        cout<<"D1 is greater than D2"<<endl;
    }else{
    cout<<"D2 is greater than D1"<<endl;}

    if(D3<=D2){
        cout<<"D3 is greater than or equal to D2"<<endl;
    }else{
        cout<<"D2 is greater than or equal to D3"<<endl;
    }

    delete D;
    return 0;
}
