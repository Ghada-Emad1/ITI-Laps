#include <iostream>

using namespace std;
class Fraction{
    int num;
    int den;
public:
    Fraction(){
        num=den=0;
    }
    Fraction(int _num,int _den){
        num=_num;
        den=_den;
    }
    void getFraction(){
        char ch;
        cout<<"Enter Fraction Number : ";
        cin>>num>>ch>>den;
    }
    void DisplayFraction(){
        cout<<"Fraction Number is "<<num<<"/"<<den<<endl;
    }
    Fraction operator+(Fraction f){
        Fraction res;
        res.num=(num* f.den)+(den*f.num);
        res.den=den*f.den;
        return res;
    }
    void simplicity(){
        int minimum=0;
        if(den>num){
            minimum=num;
        }else{
            minimum=den;
        }
        for(int i=minimum;i>=1;i--){
            if(num%i==0 && den%i==0){
                num/=i;
                den/=i;
                break;
            }

        }
    }
};
int main()
{
    char choise;
    Fraction f1;
    Fraction f2;
    do{
        f1.getFraction();
        f2.getFraction();
        Fraction f3=f1+f2;
        f3.simplicity();
        f3.DisplayFraction();
        cout<<"Do you want another one (y,n) : ";
        cin>>choise;


    }while(choise!='n');
    /*Fraction f1(1,2);

    f1.DisplayFraction();
    Fraction f2(1,2);
    Fraction f3;
    f3=f1+f2;
    f3.simplicity();
    f3.DisplayFraction();*/
    return 0;
}
