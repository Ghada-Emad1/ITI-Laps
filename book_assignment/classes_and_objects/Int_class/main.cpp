#include <iostream>

using namespace std;
class Int{
    int i;
public:
    Int(){
        i=0;
    }
    Int(int _I){
        i=_I;
    }
    void Add(Int i1,Int i2){
        i=i1.i+i2.i;
    }
    void Display(){
    cout<<i<<endl;
    }
};
int main()
{
    Int I1(2);
    Int I2(2);
    Int I3;
    I3.Add(I1,I2);
    cout<<"the summation of two object is : ";
    I3.Display();

    return 0;
}
