#include <iostream>

using namespace std;
void swapping(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int x,y;
    cout<<"Enter x : ";
    cin>>x;
    cout<<"Enter y : ";
    cin>>y;
    swapping(x,y);
    cout<<"the value of x is "<<x<<" and the value of y is "<<y<<endl;
    return 0;
}
