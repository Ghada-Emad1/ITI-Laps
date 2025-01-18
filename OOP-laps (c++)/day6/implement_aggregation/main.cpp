#include <iostream>

using namespace std;
class Point{
    int x;
    int y;
public:
    Point(){
        x=y=0;
    }
    Point(int _x){
        x=_x;
        y=0;
    }
    Point(int _x,int _y){
        x=_x;
        y=_y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setX(int _x){
        x=_x;
    }
    void setY(int _y){
        y=_y;
    }

    void Print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};
class Rect{
    Point *UL;
    Point *LR;
public:
    Rect(){
        UL=new Point();
        LR=new Point();
    }
    void setUL(Point *_UL){
        *UL=*_UL;
    }
    void setLR(Point *_LR){
        *LR=*_LR;
    }
    Point getUL(){
        return *UL;
    }
    Point getLR(){
        return *LR;
    }
    void Print(){
        LR->Print();
        UL->Print();
    }
    ~Rect(){
        delete UL;
        delete LR;
        cout<<"rectangle destroyed"<<endl;
    }
};
int main()
{
    Point p1(2,3);
    Point p2(3,4);
    Rect r1;
    r1.setLR(&p1);
    r1.setUL(&p2);
    r1.Print();
    return 0;
}
