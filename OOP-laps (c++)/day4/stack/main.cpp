#include <iostream>

using namespace std;
class Stack{
    int tos;
    int size;
    int *arr;
public:
    Stack(){
        tos=-1;
        size=10;
        arr=new int[size];
    }
    Stack(int _size){
        tos=-1;
        size=_size;
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

     Stack(const Stack &s){
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
    Stack operator=(const Stack &s){
        tos=s.tos;
        size=s.size;
        delete arr;
        arr=new int[size];
        for(int i=0;i<=tos;i++){
            arr[i]=s.arr[i];
        }
        return *this;
    }
    Stack operator +(const Stack &s){

        int x=size+s.size;
        Stack res(x);
        for(int i=0;i<=tos;i++){
            res.Push(arr[i]);
        }
        for(int i=0;i<=s.tos;i++){
            res.Push(s.arr[i]);
        }
        return res;

    }
    friend void viewContent(Stack s);

};

void viewContent(Stack s){
    for(int i=0;i<=s.tos;i++){
        cout<<s.arr[i]<<" ";
    }
}
int main()
{

    Stack s2;
    s2.Push(8);
    s2.Push(9);
    s2.Push(10);
    viewContent(s2);

    cout<<"Assignment to another Stack"<<endl;
    Stack s1;
    s1=s2;
    viewContent(s1);

    cout<<"Add Two Stack ------------------------------"<<endl;
    Stack s3;
    s3=s1+s2;
    viewContent(s3);

    return 0;
}
