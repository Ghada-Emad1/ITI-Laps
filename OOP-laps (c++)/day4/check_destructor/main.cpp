#include <iostream>

using namespace std;
class Emp{
    int id;
    int age;
public:
    Emp(){
        cout<<"constructor"<<endl;

    }
    Emp(int _id,int _age){
        cout<<"constructor with two paramenters"<<endl;
        id=_id;
        age=_age;
    }
    Emp(Emp &c){
        id=c.id;
        age=c.age;
        cout<<"Copy constructor"<<endl;
        cout<<"object in copy constructor "<<&c<<endl;
        cout<<" this in copy constructor "<<this<<endl; //this refere to e object in main
        c.setId(1111);
    }
    void setId(int _id){
        id=_id;
    }
    int getId(){
        return id;
    }
    void print(){
        cout<<id <<" "<<age<<endl;
    }
    ~Emp(){
        cout<<"destructor"<<endl;

    }
    void passing(Emp e){
        e.setId(9);
        cout<<"in function when pass by value "<<&e<<endl;
    }
    void passing2(Emp *e){
        e->setId(200);
        cout<<"in function when pass by address "<<e<<" "<<this<<endl;
       // delete e; execute destructor
    }
    Emp passing3(Emp e1,Emp e2){
        Emp res;
        res.setId(e1.getId()+e2.getId());
        Emp &temp=res;
        cout<<"------------------"<<endl;
        cout<<"two object passed by value "<<endl;
        //cout<<"Temp is "<<
        return res;
    }

};
int main()
{
   Emp e(1,20);
   e.print();
   e.passing(e);
   cout<<"in main : "<<&e<<endl;
   e.passing2(&e);
   e.print();
   Emp e4;
   Emp e1(e4);
   cout<<"e4 is  "<<&e4<<" equal to this in copy constructor "<<&e1<<endl;
   Emp e5;
   e5=e;
   e5.passing(e5);
   e5.print();

  Emp res,e11(1,2),e22(1,2);
  res.passing3(e11,e22);
  res.print();
  //cout<<"result from function that i passed two object by value "<<res.getId()<<endl;
    return 0;
}
