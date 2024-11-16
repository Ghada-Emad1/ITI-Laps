#include <iostream>
#include <conio.h>
using namespace std;
class Tollbooth{
    unsigned int total_cars;
    double total_amount;
public:
    Tollbooth(){
        total_amount=0;
        total_cars=0.0;
    }
    void PayingCar(){
        total_cars++;
        total_amount+=0.5;
    }
    void noPayCar(){
        total_cars++;
    }
    void Display(){
        cout<<" Total Amount is : "<<total_amount<<" Total Cars : "<<total_cars<<endl;
    }
};
int main()
{
    Tollbooth booth1;
    char ch;

    cout<<"press c to count paying car and m to count non paying car";
    cout<<"press e to exit from program"<<endl<<endl;

    do{
        cout<<"Press key : ";
        cin>>ch;

        if(ch=='c'){
            booth1.PayingCar();
        }
        if(ch=='m'){
            booth1.noPayCar();
        }
    }while(ch!='e');
    booth1.Display();

    return 0;
}
