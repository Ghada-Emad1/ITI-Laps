#include <iostream>

using namespace std;
class fraction{
    int num;
    int den;
public:
    fraction(){
        num=0;
        den=1;
    }
    fraction(int _num){
        num=_num;
    }
    fraction(int _num,int _den){
        num=_num;
        den=_den;
    }
    void setNum(int _num){
        num=_num;
    }
    void setDen(int _den){
        den=_den;
    }
    int getNum(){
        return num;
    }
    int getDen(){
        return den;
    }
    fraction operator +(fraction c){
        fraction res;
        res.num=c.den*num+c.num*den;
        res.den=c.den*den;
        return res;

    }
    fraction operator -(fraction c){
         fraction res;
         res.num=c.num*den-num*c.den;
         res.den=c.den*den;
         return res;
    }
    fraction operator *(fraction c){
        fraction res;

        res.num=c.num*num;
        res.den=c.den*den;
        return res;
    }
    fraction operator /(fraction c){
        fraction res;
        res.num=c.num*den;
        res.den=c.den*num;
        return res;
    }
    fraction operator++(int){

       fraction temp=*this;
       num+=den;
       return temp;
    }
     fraction operator--(int){

       fraction temp=*this;
       num-=den;
       return temp;
    }
    explicit operator float(){
        return (float)num/den;
    }
    void Print(){
        cout<<num<<"/"<<den<<endl;
    }
    void simplify(){

    int minimum=0;
    if(num>den){
        minimum=den;
    }
    else {
        minimum=num;
    }

    for(int i=minimum;i>=1;i--){
        if(num%i==0 && den%i ==0){
            num/=i;
            den/=i;
            break;
        }
    }

}
};

int main()
{
    fraction f1(1,2);
    fraction f2(1,2);
    fraction f3;
    f3=f1+f2;
    f3.simplify();
    f3.Print();

    fraction f4;
    f4=f1-f2;
    f4.simplify();
    f4.Print();

    fraction f5;
    f5=f1*f2;

    f5.simplify();
    f5.Print();
    fraction f6;
    f6=f1/f2;
    f6.simplify();
    f6.Print();
    f1++;
    f1.Print();

    f2--;
    f2.Print();

    fraction f7(1,3);
    float x=(float)f7;
    cout<<"x = "<<x<<endl;
    return 0;
}
