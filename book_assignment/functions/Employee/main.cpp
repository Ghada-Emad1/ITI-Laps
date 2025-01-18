#include <iostream>
#include<string.h>
using namespace std;
class Emp{
    int age;
    char Name[40];
    int salary;
public:
    Emp(){
        age=0;
        strcpy(Name,"There is No Name");
        salary=0;
    }
    Emp(int _age,char*_Name){
        age=_age;
        strcpy(Name,_Name);
        salary=0;
    }
    Emp(int _age,char* _Name,int _salary){
        age=_age;
        strcpy(Name,_Name);
        salary=_salary;
    }
    void setAge(int _age){
        age=_age;
    }
    int getAge(){
        return age;
    }
    void setName(char*_Name){
        strcpy(Name,_Name);
    }
    char* getName(){
        return Name;
    }
    void Print(){
        cout<<"The Employee Age is "<<age<<" and Name is "<<Name<<"The Salary"<<salary<<endl;
    }
    ~Emp(){
        cout<<"Object is deleted successfully";
    }
};
int main()
{
    Emp e1(22,"Ghada");
    Emp e2(22,"Omar",120000);
    e2.Print();
    e1.Print();
    return 0;
}
