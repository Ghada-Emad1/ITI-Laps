#include <iostream>

using namespace std;
int factorial(int n){
    if (n==1 || n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int main()
{
    int x;
    cout<<"Enter Your Number : ";
    cin>>x;
    cout<<"Your Factorial is : "<<factorial(x);
    return 0;
}
