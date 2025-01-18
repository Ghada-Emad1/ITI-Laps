#include <iostream>

using namespace std;
class Complex{
    int imag;
    int real;
    static int counter;
public:
    Complex(){
        real=imag=0;
        counter++;
    }
    Complex(int _real){
        real=_real;
        imag=0;
        counter++;
    }
    Complex(int _real,int _imag){
        real=_real;
        imag=_imag;
        ++counter;
    }
    static int getCounter(){
        return counter;
    }
    void print(){
        if(imag>0){
            cout<<real<<" + "<<imag<<" i "<<endl;
        }
        else if (imag <0){
            cout<<real<<" "<<imag<<endl;
        }
        else{
            cout<<real<<endl;
        }
    }
    ~Complex(){
        counter--;
        cout<<"destory Object"<<endl;
    }

};
int Complex::counter=0;
int main()
{
    Complex c;
    Complex c1(9,2);
    Complex c2(2);
    cout<<"Number of Object is "<<Complex::getCounter()<<endl;
    c1.print();


    return 0;
}
