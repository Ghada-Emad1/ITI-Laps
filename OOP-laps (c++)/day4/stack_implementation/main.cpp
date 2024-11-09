#include <iostream>

using namespace std;
class Stack{
    int size;
    int tos;
    int *arr;
public:
    Stack(){
        tos=-1;
        size=5;
        arr=new int[size];
    }
    Stack(int _size){
        size=_size;
        tos=-1;
        arr=new int[size];
    }
    void Push(int d){
        if(tos<size-1){
            tos++;
            arr[tos]=d;
        }
        else{
            cout<<"Stack is Full"<<endl;
        }
    }
    int Pop(int &d){
        if(tos!=-1){
            d=arr[tos];
            tos--;
            return 1;
        }else{
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
    }
    //deep constructor
    Stack (const Stack &s){
        tos=s.tos;
        size=s.size;
        arr=new int[size];
        for(int i=0;i<=tos;i++){
            arr[i]=s.arr[i];
        }
        cout<<"copy constructor"<<endl;
    }
    //shallow constructor
    /*Stack(const Stack s){
        tos=s.tos;
        size=s.size;
        arr=s.arr;
    }*/
    ~Stack(){
        cout<<"destroy object"<<endl;
        delete []arr;
    }
    friend void viewContent(Stack s);

};
void viewContent(Stack s){
    for(int i=0;i<=s.tos;i++){
        cout<<s.arr[i]<<endl;
    }
}
int main()
{
    Stack s;
    s.Push(12);
    s.Push(23);
    s.Push(80);
    s.Push(10);
    s.Push(20);
    viewContent(s);
    Stack s1;
    s1=s;
    viewContent(s1);
    /*int x;

    if(s.Pop(x)){
         cout<<x<<endl;
    }
    if(s.Pop(x)){
         cout<<x<<endl;
    }
    if(s.Pop(x)){
         cout<<x<<endl;
    }
    if(s.Pop(x)){
         cout<<x<<endl;
    }
    if(s.Pop(x)){
         cout<<x<<endl;
    }
    if(s.Pop(x)){
         cout<<x<<endl;
    }

    cout<<"assign stack"<<endl;
    if(s1.Pop(x)){
         cout<<x<<endl;
    }
    if(s1.Pop(x)){
         cout<<x<<endl;
    }
    if(s1.Pop(x)){
         cout<<x<<endl;
    }
    if(s1.Pop(x)){
         cout<<x<<endl;
    }
    if(s1.Pop(x)){
         cout<<x<<endl;
    }
    if(s1.Pop(x)){
         cout<<x<<endl;
    }*/
     /*s.Pop(x);
    cout<<x<<endl;
     s.Pop(x);
    cout<<x<<endl;
     s.Pop(x);
    cout<<x<<endl;
     s.Pop(x);
    cout<<x<<endl;
    s.Pop(x);
    cout<<x<<endl;*/

    return 0;
}
