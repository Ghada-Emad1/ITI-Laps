#include <iostream>

using namespace std;

int Power(int num,int pow){
    if(pow==0){
        return 1;
    }
    return num*Power(num,pow-1);
}
int main()
{
    int num;
    cout<<"Enter Number : ";
    cin>>num;
    int pow;
    cout<<"Enter Power of Number : ";
    cin>>pow;
    cout<<"Result is : "<<Power(num,pow);
    return 0;
}
