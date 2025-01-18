#include <iostream>
#include<string.h>
using namespace std;
class Emp{
    int id;
    char *name;
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
   void setName(char*_name){
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
    Emp *ptr=&e1;
    int sizee;
    cout<<"Enter the size " ;
    cin>>sizee;

    char *ptr_name=new char[sizee];
    if(ptr_name!=NULL){
        cout<<"Enter Name: ";
        for(int i=0;i<sizee;i++)
            cin>>ptr_name[i];
        ptr_name[sizee]='\0';
    }
    ptr->setName(ptr_name);
    delete []ptr_name;
    cout<<"The name is "<<ptr->getName()<<endl;
     ptr->setId(20);
     cout<<"The id is "<<ptr->getId();

    return 0;
}
