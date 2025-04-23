#include <iostream>

using namespace std;
class Queue{
    int *arr;
    int size;
    int top;
public:
    Queue(int _size=5){
        size=_size;
        arr=new int[size];
        top=-1;
    }
    void Enqueue(int d){
        if(top<size-1){
            top++;
            arr[top]=d;
        }else{
            cout<<"Queue is Full"<<endl;
        }
    }
    int Dequeue(int &d){
        if(top==-1){
            cout<<"Queue is Empty"<<endl;
        }
        if(top!=-1){
            d=arr[0];
             for(int i=0;i<top;i++){
            arr[i]=arr[i+1];
        }
        top--;
        return 1;
        }
        else{
            return 0;
        }

    }
    ~Queue(){
        delete []arr;
    }

};
int main()
{

   Queue q1;
   q1.Enqueue(2);
   q1.Enqueue(3);
   q1.Enqueue(4);
   int x;
   if(q1.Dequeue(x)){
    cout<<x<<endl;
   }
   if(q1.Dequeue(x)){
    cout<<x<<endl;
   }
   if(q1.Dequeue(x)){
    cout<<x<<endl;
   }
   if(q1.Dequeue(x)){
    cout<<x<<endl;
   }
    return 0;
}
