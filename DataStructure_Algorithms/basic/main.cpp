#include <iostream>
#include<string.h>
using namespace std;
/*struct Emp{
    int id;
    char name[20];
    int Add(int a,int b){
        return a+b;
    }
};*/
class Emp{
    int id;
    char Name[10];
public:
    int getId(){
    return id;}
    void setId(int _id){
        id=_id;
    }
    void setName(char *_Name){
        strcpy(Name,_Name);
    }
    char*getName(){
        return Name;
    }
};
void myfun(Emp e0){
    cout<<e0.getId()<<" "<<e0.getName()<<endl;
}
void myfun2(int& s){
    s+=10;
    cout<<"s inside funtion is "<<s<<endl;
}
int main()
{
    /*int *ptr=new int[5];
    if(ptr!=NULL){
        for(int i=0;i<5;i++){
            cin>>ptr[i];
        }
    }
     if(ptr!=NULL){
        for(int i=0;i<5;i++){
            cout<<ptr[i]<<" ";
        }
    }
    delete []ptr;

    cin>>ptr[2];
    cout<<ptr[2];*/
    /*int *ptr2=new int(3);
    cout<<ptr2<< " "<<*ptr2<<" "<<ptr2[0]<<" "<<ptr2[1]<<endl;
    delete ptr2;
    Emp e={1,"ghada"};
    //e.id=12;
    int res=e.Add(1,2);
    cout<<e.id<<"  "<<res;*/
    Emp e;
   /* e.setId(12);
    char Name[20];
    gets(Name);
    e.setName(Name);
    cout<<e.getId()<< "  "<<e.getName()<<endl;*/
    Emp *ptr=&e;
    ptr->setId(12);
    ptr->setName("omar");
    cout<<"ptr values create object in stack "<<ptr->getId()<< " "<<e.getId()<<endl;
    cout<<ptr->getName()<<" "<<e.getName()<<endl;
    Emp *ptr2=new Emp;
    ptr2->setId(23);
    ptr2->setName("gehad");
    cout<<"print fun pass ptr as object : ";
    myfun(*ptr2);
    myfun(e);
    cout<<"ptr2 values create object in heap "<<ptr2->getId()<<" "<<ptr2->getName()<<endl;
    int x=12;
    int *y=&x;
    x=13;
    cout<<"With pointer changes in pointer y affect x value "<<x<<" "<<*y<<endl;
    int x1=20;
    int &y1=x1;
    x1=30;
    cout<<"Change in reference y1 affect x1 like pointer"<<x1<<" "<<y1<<" "<<&y1<<" "<<&x1<<endl;


    int s=10;
     int *ptr3=&s;
    cout<<"s before calling function : "<< *ptr3<<endl;
    myfun2(*ptr3);
    cout<<"s outside funtion after call funtion "<<*ptr3;
    return 0;
}
