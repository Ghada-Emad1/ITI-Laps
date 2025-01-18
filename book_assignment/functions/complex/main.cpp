#include <iostream>

using namespace std;
class Complex{
    int real;
    int imag;
public:
    void setReal(int _real){
        real=_real;
    }
    int getReal(){
        return real;
    }
    void setImag(int _imag){
        imag=_imag;
    }
    int getImag(){
        return imag;
    }
    void print(){
       if(imag<0){
        cout<<"The complex Number is "<<real<<imag<<"i\n";
       }
       else if(imag>0){
        cout<<"The complex Number is "<<real <<" + "<<imag<<"i\n";
       }else{
           cout<<"The complex Number is"<<real<<endl;
       }
    }
    Complex Add(Complex c){
        Complex res;
        res.real=c.real+real;
        res.imag=c.imag+imag;
        return res;

    }
    Complex(){}
    Complex(int _real,int _imag){
        real=_real;
        imag=_imag;
    }

};
Complex Add(Complex c1,Complex c2);
int main()
{
    Complex cpx1,cpx2,res1,res2,res;
    Complex p1(1,2);
    Complex p2(2,4);
    cpx1.setReal(12);
    cpx1.setImag(1);
    cpx2.setReal(3);
    cpx2.setImag(2);
    res=Add(p1,p2);
    res.print();
    res1=Add(cpx1,cpx2);
    res2=cpx1.Add(cpx2);
    res1.print();
    res2.print();



    return 0;
}
Complex Add(Complex c1,Complex c2){
    Complex res;
    res.setReal(c1.getReal()+c2.getReal());
    res.setImag(c1.getImag()+c2.getImag());
    return res;
}
