#include <iostream>

using namespace std;

int Fibionial(int num){
    if (num == 1|| num==2){
        return 1;
    }

    return Fibionial(num-1)+Fibionial(num-2);

}
int main()
{
    int fib;
    cout<<"Enter Fabionial Number : ";
    cin>>fib;
    cout<<"Result is : "<<Fibionial(fib);
    return 0;
}
