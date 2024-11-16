#include <iostream>
#include<string.h>
using namespace std;
class Employee{
    int number;
    float EmpCompen;
    char Name[30];
public:
    Employee(){
        number=0;
        EmpCompen=0.0;
        strcpy(Name,"NO Name");
    }
    Employee(int _number,char *_Name,float _EmpCompen){
        number=_number;
        strcpy(Name,_Name);
        EmpCompen=_EmpCompen;
    }
    void Display(){
        cout<<"Employee Number : "<<number<<" ,Name : "<<Name<<" ,EmpCompen : "<<EmpCompen<<endl;
    }
};
int main()
{
    int number;
    cout<<"Enter Employee Number : ";
    cin>>number;
    char Name[30];
    cout<<"Enter Employee Name : ";
    cin>>Name;
    float EmpCompen;
    cout<<"Enter Employee Compen : ";
    cin>>EmpCompen;
    Employee emp(number,Name,EmpCompen);
    emp.Display();
    return 0;
}
