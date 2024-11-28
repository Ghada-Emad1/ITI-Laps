#include <iostream>

using namespace std;
class Stack{
    int tos;
    int size;
    int *arr;
public:
    Stack(){
        tos=-1;
        size=5;
        arr=new int[size];
    }
    void Push(int data){
        if(tos<size-1){
            tos++;
            arr[tos]=data;
        }
        else{
            cout<<"Stack is Full";
        }
    }
    int Pop(int &d){
        if(tos!=-1){
            d=arr[tos];
            tos--;
            return 1;
        }
        else{
            cout<<"Stack is Empty";
            return 0;
        }
    }

     Stack(Stack &s){
         cout<<"copy destructor\n";
         tos=s.tos;
         size=s.size;
         arr=new int[size];
         for(int i=0;i<=tos;i++){
            arr[i]=s.arr[i];
         }
     }


    ~Stack(){
        cout<<"\nObject destoryed sucessfully\n";
        delete []arr;
    }

};
 myfun(Stack s){
        int x;
        s.Pop(x);
        cout<<endl<<x;
        s.Pop(x);
        cout<<endl<<x;

    }
int main()
{

    Stack s2;
    s2.Push(8);
    s2.Push(9);
    myfun(s2);
    int x;
    s2.Pop(x);
    cout<<endl<<x;
    return 0;
}
