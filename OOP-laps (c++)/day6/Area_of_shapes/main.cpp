#include <iostream>

using namespace std;
class Shape{
protected:
    int dim1;
    int dim2;
public:
    Shape(){
        dim1=dim2=1;
    }
    Shape(int _dim1){
        dim1=dim2=_dim1;
    }
    Shape(int _dim1,int _dim2){
        dim1=_dim1;
        dim2=_dim2;
    }
    void setDim1(int _dim1){
        dim1=_dim1;
    }
    int getDim1(){
        return dim1;
    }
    void setDim2(int _dim2){
        dim2=_dim2;
    }
    int getDim2(){
        return dim2;
    }
    virtual int calcArea()=0;

};
class Rect:public Shape{
public:
    Rect(int _dim1,int _dim2):Shape(_dim1,_dim2){
    }
    Rect(int _dim1):Shape(_dim1){}
    int calcArea(){
        return dim1*dim2;
    }

};
class Square:public Rect{
public:
    Square(int _dim1):Rect(_dim1){}
    int calcArea(){
        return dim1*dim1;
    }
};
class Triangle:public Shape{
public:
    Triangle(int _dim1,int _dim2):Shape(_dim1,_dim2){}
    int calcArea(){
        return 0.5*dim1*dim2;
    }
};
class Circle:public Shape{
public:
    Circle(int _dim1):Shape(_dim1){
    }
    int calcArea(){
        return 22/7*dim1*dim2;
    }
};
int myfun(Shape *arr[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i]->calcArea();
    }
    return sum;
}
void myfun1(Shape *s){
    cout<<s->calcArea()<<endl;
}
int main()
{
    Rect r(10,20);
    Shape *ptr=&r;
    cout<<"Area of Rectangle : "<<ptr->calcArea()<<endl;

    Square s(2);
    Rect *ptrs=&s;
    cout<<"Area of Square : ";
    myfun1(&s);
    cout<<"Area of Square : "<<ptrs->calcArea()<<endl;

    Triangle t(10,20);
    Shape *ptrt=&t;
    cout<<"Area of Triangle : "<<ptrt->calcArea()<<endl;

    Circle c(2);
    Shape *ptrc=&c;
    cout<<"Area of Circle : "<<ptrc->calcArea()<<endl;

    Shape*Arr[4]={&r,&s,&t,&c};
    int sum=myfun(Arr,4);
    cout<<"Summation of Areas is : "<<sum<<endl;

    return 0;
}
