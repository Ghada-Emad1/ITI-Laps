#include <iostream>

using namespace std;
void swapping(int &x,int &y);
int main()
{
    int x=9;
    int y=10;
    swapping(x,y);
    cout<<"x is "<<x<<" y is "<<y;
    return 0;
}
void swapping(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
