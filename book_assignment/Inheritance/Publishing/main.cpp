#include <iostream>
#include<string.h>
using namespace std;
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

class Book:public Publication{
    int page_cnt;
public:
    void GetData(){
        Publication::GetData();
        cout<<"Enter page count : ";
        cin>>page_cnt;
    }
    void PutData(){
        Publication::PutData();
        cout<<" Page count = "<<page_cnt<<endl;
    }



};
class Tape:public Publication{
    float tape;
public:
    void GetData(){
        Publication::GetData();
        cout<<"Enter tape : ";
        cin>>tape;
    }
    void putData(){
        Publication::PutData();
        cout<<"Tape is "<<tape<<endl;
    }
};
int main()
{
    Publication p1;
    p1.GetData();
    p1.PutData();
    Book b1;
    b1.GetData();
    b1.PutData();
    Tape t1;
    t1.GetData();
    t1.putData();
    return 0;
}
