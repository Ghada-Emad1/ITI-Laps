#include <iostream>
#include<iomanip>
using namespace std;
class Fraction_Table{
    int num;
    int den;
    int arr[6][6];
public:
    Fraction_Table(){
        num=0;
        den=1;
    }
    Fraction_Table(int _num,int _den){
        num=_num;
        den=_den;
    }
    void SetFraction(int _num,int _den){
        num=_num;
        den=_den;
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
    void MultFraction(Fraction_Table f1,Fraction_Table f2){
        num=f1.num*f2.num;
        den=f1.den*f2.den;
    }
     void Display(){
            cout << num << "/" << den;
        }

};
int main()
{
    char ch;
    Fraction_Table f(0,0);
    Fraction_Table f1(0,0);
    Fraction_Table f2(0,0);
    int number;
    do{
        cout<<"Enter the Number : ";
        cin>>number;
        cout<<"\t";
        for(int i=1;i<number;i++){
            f.SetFraction(i,number);
            f.simplcity();
            f.Display();
            cout<<"\t";
        }
        for(int j=1;j<number;j++){
            cout<<endl;
            f.SetFraction(j,number);
            f.simplcity();
            f.Display();
            cout<<"\t";
        for(int k=1;k<number;k++){
            f1.SetFraction(k,number);
            f2.SetFraction(j,number);
            f.MultFraction(f1,f2);
            f.simplcity();
            f.Display();
            cout<<"\t";
        }
        }

        cout<<endl<<"Do you want to enter another one (y,n) ";
        cin>>ch;
    }while(ch!='n');
    return 0;
}
