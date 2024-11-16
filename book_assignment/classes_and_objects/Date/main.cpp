#include <iostream>

using namespace std;
class Date{
    int month;
    int day;
    int year;
public:
    Date(){
        month=day=year=0;
    }
    void showDate(){
    cout<<"The Date is : " <<day<<"/"<<month<<"/"<<year;
    }
    friend void GetDate(Date &d);

};
void GetDate(Date &d){
    char ch;
      cout<<"Enter Date : ";
      cin>>d.day>>ch>>d.month>>ch>>d.year;

}
int main()
{

    Date d1;
    GetDate(d1);
    d1.showDate();
    return 0;
}
