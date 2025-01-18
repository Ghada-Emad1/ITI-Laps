#include <iostream>
#include<string.h>
using namespace std;
struct Emp
private:
    int id;
    char name[40];
    int age;
public:
    void setId(int _id){
        if(_id<=0){
            cout<<"Please Enter Valid Id";
        }else{
            id=_id;
        }

    }
    int getId(){
        return id;
    }
    void setName(char *_name){
        if(strlen(_name)>=4){
            strcpy(name,_name);
        }
        else{
            cout<<"Please Enter Valid Name "<<endl;
        }

    }
    char *getName(){
        return name;
    }
    void setAge(int _age){
        if(_age <=18 && _age>=70){
            cout<<"please Enter Valid age";
        }
        age=_age;
    }
    int getAge(){
        return age;
    }
};
int main()
{

    Emp e1;
    int id;
    Emp *ptr=new Emp;

    cout<<"Enter Your id : ";
    cin>>id;
    e1.setId(id);
    ptr->setId(id);
    cout<<"Your id is "<<e1.getId()<<endl;
    cout<<"Your id is "<<ptr->getId();
    char name[20];
    cout<<"\nEnter Your Name : ";
    cin>>name;
    e1.setName(name);
    ptr->setName(name);
    cout<<"Your Name is : "<<e1.getName()<<endl;
    cout<<"Your Name is : "<<ptr->getName();
    int age;
    cout<<"\nEnter Your Age : " ;
    cin>>age;
    e1.setAge(age);
    ptr->setAge(age);
    cout<<"Your Age is "<<e1.getAge()<<endl;
    cout<<"Your Age is "<<ptr->getAge();
    return 0;
}
