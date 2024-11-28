#include <iostream>

using namespace std;

class Complex
{
    int real;
    int imag;
public:
    Complex(){
        real=0;
        imag=0;
    }
    Complex (int _real,int _imag){
        real=_real;
        imag=_imag;
    }
    Complex (Complex &c){
        cout<<"copy constructor"<<endl;
        real=c.real;
        imag=c.imag;
    }
    int getReal()
    {
        return real;
    }
    void setReal(int _real){
        real=_real;
    }
    int getImag(){
        return imag;
    }
    void setImag(int _imag){
        imag=_imag;
    }
    void Print(){
        if(imag>0){
            cout<<real<<"+"<<imag<<"i";
        }else if(imag<0){
            cout<<real<<imag<<"i";
        }else{
            cout<<real;
        }
    }
    Complex operator +(Complex c){
        Complex res;
        res.real=real+c.real;
        res.imag=imag+c.imag;
        return res;
    }
    Complex operator +(int x){
        Complex res;
        res.real=real+x;
        res.imag=imag;
        return res;
    }
    int operator ==(Complex c){
        if(real ==c.real && imag ==c.imag){
            return 1;
        }else{
            return 0;
        }
    }
    int operator != (Complex c){
        return !(*this==c);
    }
    explicit operator int(){
        return real;
    }
    void operator ++(){
        real=real+1;
        imag=imag+1;

    }
    Complex operator +=(Complex c){
        real=real+c.real;
        imag=imag+c.imag;
        return *this;
    }
    Complex operator ++(int){
        Complex temp=*this;
        real=real+1;
        imag=imag+1;
        return temp;
    }
    friend Complex operator +(int x,Complex c);

};
Complex operator +(int x,Complex c){
    Complex res;
    res.real=c.real+x;
    res.imag=c.imag;
    return res;
}
int main()
{
    Complex c1(1,2);
    Complex c2(1,2);
    Complex c3;
    c3=c1+c2;
    cout<<"complex +complex  ";
    c3.Print();
    cout<<endl;
    Complex c4;
    cout<<"complex + int  ";
    c4=c1+1;
    c4.Print();


    cout<<endl;
    cout<<"int +Complex  ";
    Complex c5;
    c5=1+c1;
    c5.Print();

    cout<<endl;
    Complex c6(1,2);
    Complex c7(1,2);
    cout<<"Check if Complex is Equal    ";
    if(c6==c7){
        cout<<"Eual ";
    }else{
        cout<<"Not Equal";
    }
    cout<<endl;
    cout<<"Compare if Complex is Not Equal  ";
    if(c6!=c7){
        cout<<"Not Equal";
    }else{
        cout<<"Equal";
    }
    cout<<endl;
    int x=(int)c6;
    cout<<"Casting variable : "<<x;

    cout<<endl;
    Complex c11(1,1);
    ++c11;
    cout<<"PreFix operator ";
    c11.Print();
    cout<<endl;
    Complex c22(2,2),c12;
    cout<<"PostFix operator";
    c12=c22++;
    c12.Print();

    c12+=c11;
    c12.Print();
    return 0;
}
