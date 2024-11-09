#include <iostream>
#include<string.h>
using namespace std;
class Emp{
    int id;
    int age;
    char Name[90];
public:
    Emp(){
        cout<<"Parameterless constructor"<<endl;
        id=0;
        age=0;
        strcpy(Name,"No Name");
    }
    Emp(int _id,char *_Name){
        cout<<"Constructor with two parameters"<<endl;
        id=_id;
        strcpy(Name,_Name);
        age=0;
    }
    Emp(int _id,char *_Name,int _age){
        cout<<"Constructor with three parameters"<<endl;
        id=_id;
        strcpy(Name,_Name);
        age=_age;
    }
    void Print(){
        cout<<"id is "<<id<<" Name is "<<Name<<" Age is "<<age<<endl;
    }
    void myfun(){
        Emp e;
    }
    ~Emp(){
        cout<<"Destroyed Object successfully"<<endl;
    }
};
int main()
{
    Emp e1;
    e1.Print();
    Emp e2(1,"Ghada");
    e2.Print();
    Emp e3(1,"ghada",80);
    cout<<"Before my function";
    Emp e4;
    e4.Print();
    cout<<"After my function"<<endl;
    //e3.Print();


    Emp *e0=new Emp(10,"Ghada");
    cout<<e0<<endl;
    e0->Print();
    return 0;
}
