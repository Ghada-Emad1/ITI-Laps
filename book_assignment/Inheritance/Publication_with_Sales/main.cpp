#include <iostream>
#include<string.h>
using namespace std;
class Sales{
    
    float arrSale[3];
public:
    void getSales(){
        cout<<"Enter 3 Month Sales : "<<endl;
        for(int i=0;i<3;i++){
            cout<<" Month "<<i+1<<": ";
            cin>>arrSale[i];
        }
    }
    void PutSales(){
        for(int i=0;i<3;i++){
            cout<< "Month "<<i+1<<": ";
            cout<<arrSale[i]<<endl;
        }
    }
};
class Publication{
protected:
    char title[30];
    float price;
public:
    Publication(){
        price=0.0;
        strcpy(title,"No title");
    }
    Publication(char *_title,float _price){
        price=_price;
        strcpy(title,_title);
    }
    void GetData(){
        cout<<"Enter price : ";
        cin>>price;
        cout<<"Enter Title : ";
        cin>>title;
    }
    void PutData(){
        cout<<"Title = "<<title<<" Price = "<<price<<endl;
    }
};

class Book:public Publication,public Sales{
    int page_cnt;
public:
    void GetData(){
        Publication::GetData();
        cout<<"Enter page count : ";
        cin>>page_cnt;
        Sales::getSales();
    }
    void PutData(){
        Publication::PutData();
        cout<<" Page count = "<<page_cnt<<endl;
        Sales::PutSales();
    }



};
class Tape:public Publication,public Sales{
    float tape;
public:
    void GetData(){
        Publication::GetData();
        cout<<"Enter tape : ";
        cin>>tape;
        Sales::getSales();
    }
    void putData(){
        Publication::PutData();
        cout<<"Tape is "<<tape<<endl;
        Sales::PutSales();
    }
};
int main()
{

    Book b1;
    b1.GetData();
    b1.PutData();
    Tape t1;
    t1.GetData();
    t1.putData();
    return 0;
}
