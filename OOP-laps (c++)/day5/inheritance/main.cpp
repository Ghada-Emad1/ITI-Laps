#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    int id;
    char name[20];
    int age;

public:
    Person() {
        id = 0;
        age = 30;
        strcpy(name, "no name");
    }

    Person(int _id, char* _name) {
        id = _id;
        strcpy(name, _name);
        age = 30;
    }

    Person(int _id, char* _name, int _age = 30) {
        id = _id;
        strcpy(name, _name);
        age=_age;
    }

    void setName(char* _name) {
        strcpy(name, _name);
    }

    char* getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setAge(int _age) {
        age = _age;
    }

    void setId(int _id) {
        id = _id;
    }

    int getId() {
        return id;
    }

    void Print() {
        cout << "Person data: ID = " << id << ", Name = " << name << ", Age = " << age << endl;
    }

    ~Person() {
        cout << "Person destroyed" << endl;
    }
};

class Emp : public Person {
    int salary;

public:
    Emp(int _id, char* _name,int _age,int _salary):Person(_id,_name,_age) {

        salary=_salary;
    }

    void setSalary(int _salary) {
        salary = _salary;
    }

    int getSalary() {
        return salary;
    }

    void Print() {
         cout << "Employee data: ID = " << id << ", Name = " << name << ", Age = " << age <<", Salary = "<<salary<< endl;

    }

    ~Emp() {
        cout << "Emp destroyed" << endl;
    }
};
class student:public Person{
    int grade;
public:
    student(int _id,char *_name,int _age,int _grade):Person(_id,_name,_age){
        grade=_grade;
    }
    void Print(){
         Person::Print();
         cout << "student data: ID = " << id << ", Name = " << name << ", Age = " << age <<" , Grade = "<<grade<< endl;

    }
    ~student(){
        cout<<"destroy student"<<endl;
    }
};
void myfun1(Person e){
    e.Print();
}
void myfun2(Person s){
    s.Print();
}
int main() {

    Person p(1,"ali",90);
    p.Print();

    Emp e1(2,"ghada",20,9000);
    e1.Print();

    myfun1(e1);
   student s(1,"gehad",24,100);
   myfun2(s);
   s.Print();
    return 0;
}

