#include <iostream>

using namespace std;
class Complex{
    int real;
    float imag;
public:
    void setReal(int _real){
        real=_real;
    }
    int getReal(){
        return real;
    }
    void setImag(float _imag){
        imag=_imag;
    }
    float getImag(){
        return imag;
    }
};
void print_complex(Complex cpx);

int main()
{
    Complex cpx;
    cout<<"Enter the Real Number : ";
    int real;
    cin>>real;
    cpx.setReal(real);
    cout<<"Enter the imag Number : ";
    float imag;
    cin>>imag;
    cpx.setImag(imag);

    cout<<"The complex Number is "<<cpx.getReal()<<" + "<<cpx.getImag()<<endl;
    print_complex(cpx);
    return 0;
}


void print_complex(Complex cpx)
{
    cout<<"The complex Number is "<<cpx.getReal()<<" + "<<cpx.getImag();
}
