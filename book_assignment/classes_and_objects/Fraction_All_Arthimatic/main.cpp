#include <iostream>

using namespace std;
class Fraction{
    int num;
    int den;
public:
    Fraction(){
        num=0;
        den=1;
    }
    Fraction(int _num,int _den){
        num=_num;
        den=_den;
    }
    Fraction operator +(Fraction f){
      Fraction res;
      res.num=(num*f.den)+(den*f.num);
      res.den=den*f.den;
      return res;
    }
     Fraction operator *(Fraction f){
      Fraction res;
      res.num=num*f.num;
      res.den=den*f.den;
      return res;
    }
     Fraction operator -(Fraction f){
      Fraction res;
      res.num=(num*f.den)-(den*f.num);
      res.den=den*f.den;
      return res;
    }
    Fraction operator /(Fraction f){
      Fraction res;
      res.num=num*f.den;
      res.den=den*f.num;
      return res;
    }

    void simplcity(){
        int minum=0;
        if(num>den){
            minum=den;
        }else{
            minum=num;
        }
        for(int i=minum;i>=1;i--){
            if(num%i==0&&den%i==0){
                num/=i;
                den/=i;
                break;
            }
        }
    }
    void Display_fraction(){
        cout<<"fraction result is : "<<num<<"/"<<den<<endl;
    }
};
int main()
{
    Fraction f1(2,3);
    Fraction f2(1,2);
    Fraction f3;
    f3=f1+f2;
    f3.simplcity();
    cout<<"Summation of Two Fraction is : ";
    f3.Display_fraction();

    f3=f1-f2;
    cout<<"Subtraction of Two Fraction is : ";
    f3.simplcity();
    f3.Display_fraction();
    f3=f1*f2;
    cout<<"Multiplication of Two fraction is : ";
    f3.simplcity();
    f3.Display_fraction();

    f3=f1/f2;
    cout<<"Division of Two fraction is : ";
    f3.simplcity();
    f3.Display_fraction();
    return 0;
}
