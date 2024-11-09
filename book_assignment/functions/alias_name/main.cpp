#include <iostream>

using namespace std;

int main()
{
    int x=12;
    int &y=x;
    y=20;
    cout<<"y= "<<y<<" , x= "<<x<<endl<<" Address of y "<<&y<<" address of x "<<&x<<endl;
    int z=30;
    int*k=&x;
    *k=90;
    cout<<"k is "<<k<<" z is "<<z<<endl;

    int x1=10;
    int &y1=x1;
    int z1=90;
    y1=z1;
    cout<<"address of x is "<<&x1<<" address of y is "<<&y1<<endl;
    cout<<"After assignment x1= "<<x1<<" y1 is "<<y1<<" z1 is "<<z1;
    return 0;
}
