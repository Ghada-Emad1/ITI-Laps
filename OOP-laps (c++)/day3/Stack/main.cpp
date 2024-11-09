#include <iostream>

using namespace std;
class Stack{
    int tos;
    int size;
    int arr[10];
public:
    Stack(){
        tos=-1;
        size=5;
    }
    void Push(int data){
        if(tos<size-1){
            tos++;
            arr[tos]=data;
        }
        else{
            cout<<"Stack is full";
        }
    }
    int Pop(){
        if(tos!=-1){
            int d=arr[tos];
            tos--;
            return d;
        }
        else{
            cout<<"Stack is Empty";
        }
    }
    ~Stack(){
        cout<<"Object destoryed sucessfully\n";
        delete []arr;
    }
};
int main()
{
    Stack s1;
    s1.Push(2);
    s1.Push(9);
    s1.Push(5);
    cout<<s1.Pop()<<endl;
    cout<<s1.Pop()<<endl;
    cout<<s1.Pop()<<endl;


    return 0;
}
