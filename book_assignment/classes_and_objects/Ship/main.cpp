#include <iostream>

using namespace std;
class Ship{
    static int cnt_ship;
    int degrees;
    float minutes;
    char direction;
public:
    Ship(){
        cnt_ship++;
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
    static void display_ships_count(){
        cout<<"Ship count is : "<<cnt_ship<<endl;
    }
};
int Ship::cnt_ship=0;
int main()
{

    Ship s1;
    Ship s2;
    Ship s3;
    int degrees;
    float minutes;
    char direction;
    char choise;
    do{
        cout<<"Enter degree : ";
        cin>>degrees;
        cout<<"Enter Minutes : ";
        cin>>minutes;
        cout<<"Enter Direction : ";
        cin>>direction;
        s3.PutAngle(degrees,minutes,direction);
        s3.DisplayAngle();
        s3.display_ships_count();
        cout<<"Do you want to enter another one (y,n) : ";
        cin>>choise;
    }while(choise!='n');

    return 0;
}
