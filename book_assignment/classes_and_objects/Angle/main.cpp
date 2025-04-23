#include <iostream>

using namespace std;
class Angle{
    int degrees;
    float minutes;
    char direction;
public:
    Angle(){
        degrees=0;
        minutes=0;
        direction=0;

    }
    Angle(int _degrees,float _minutes,char _direction){
        degrees=_degrees;
        minutes=_minutes;
        direction=_direction;
    }
    void DisplayAngle(){
        cout<<"angle : "<<degrees<<"\xF8 "<<minutes<<"\'"<<direction;
        switch(direction){
        case 'N':
            cout<<" Latitude";
            break;
        case 'S':
            cout <<" Latitude";
			break;

		case 'E':
			cout <<" Longitude";
			break;

		case 'W':
			cout <<" Longitude";
			break;
        }
    }
    void PutAngle(int _degrees,int _minutes,char _direction){
        degrees=_degrees;
        minutes=_minutes;
        direction=_direction;
    }

};
int main()
{
    int degree;
    float minutes;
    char direction,choise;
    Angle a(164,34.6,'S');
    a.DisplayAngle();
    cout<<endl;1
    Angle a2;
    do{
        cout<<"Enter the degree : ";
        cin>>degree;
        cout<<"Enter the Minutes : ";
        cin>>minutes;
        cout<<"Enter the Directions [N,S,E,W] : ";
        cin>>direction;
        a2.PutAngle(degree,minutes,direction);
        a2.DisplayAngle();
        cout<<endl<<"Do you want to enter another angle (y,n) : ";
        cin>>choise;


    }while(choise!='n');
    return 0;
}
