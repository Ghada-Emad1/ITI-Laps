#include <iostream>
#include<string.h>
using namespace std;
class Emp{
    int id;
    char *name;
    int age;
public:
    void setId(int _id){
        if(_id<=0){
            cout<<"Enter Valid Id"<<endl;

        }else{
            id=_id;
        }
    }
    int getId(){
        return id;
    }
    void setName(char *_name){
      delete []name;
      name=new char[strlen(_name)+1];
      strcpy(name,_name);
    }
    char *getName(){
        return name;
    }
};
int main()
{
    Emp e1;
    int id;
    int sizee;
    cout<<"enter size of name : ";
    cin>>sizee;
    char *ptr=new char[sizee+1];
    if(ptr!=NULL){
        cout<<"Enter Name: ";
        for(int i=0;i<sizee;i++)
            cin>>ptr[i];
        ptr[sizee]='\0';
    }

    e1.setName(ptr);
    delete []ptr;
    cout<<"Name is : "<<e1.getName()<<endl;
    cout<<"Enter the id : ";
    cin>>id;
    e1.setId(id);
    cout<<"The id is "<<e1.getId();
    return 0;
}
