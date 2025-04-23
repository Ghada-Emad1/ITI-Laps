#include <iostream>

using namespace std;
class Point{
    int x;
    int y;
public:
    Point(){
        cout<<"paramless constructor";
        x=y;
    }
    point (int _x){
        cout<<"constructor with one parameters";
        x=_x;
    }
    Point(int _x,int _y){
        cout<<"Constructor with two parameters ";
        x=_x;
        y=_y;
    }
    void setX(int _x){
        x=_x;
    }
    void setY(int _y){
        y=_y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void Print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    ~Point(){
        cout<<"destroy Point"<<endl;
    }
};
class Rectangle{
    Point upper_left;
    Point lower_right;
public:
    Rectangle(){
        cout<<"Rectangle created"<<endl;
    }
    Point getUl(){
        return upper_left;
    }
    Point getLr(){
        return lower_right;
    }
    void setUl(Point _ul){
        upper_left=_ul;
    }
    void setLR(Point _lr){
        lower_right=_lr;
    }
    void Print(){
        lower_right.Print();
        upper_left.Print();
    }
    ~Rectangle(){
        cout<<"rectangle destroyed"<<endl;
    }
};
class Circle{
    Point p1;
    int radius;
public:
    Circle(){
        cout<<"parameterless constructor"<<endl;
    }

    int getRadius(){
        return radius;
    }
    void setRedius(int _radius){
        radius=_radius;
    }
     Point getP(){
        return p1;
    }
    void setP(Point _p1){
        p1=_p1;
    }
    void Print(){
        p1.Print();
        cout<<"Radius is : "<<radius<<endl;
    }
    ~Circle (){
        cout<<"destroy circle"<<endl;
    }
};
int main()
{
   Point p(1,2);
   Point p2(1,3);
   cout<<"x,y of Point ";
   p.Print();
   Rectangle r1;
   r1.setLR(p);
   r1.setUl(p2);
   cout<<"\nx,y of Rectangle ";
   r1.Print();

   Circle c1;
   c1.setP(p);
   c1.setRedius(2);
   cout<<"\nx,y of Circle";
   c1.Print();

    return 0;
}
