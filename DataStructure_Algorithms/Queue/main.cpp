#include <iostream>

using namespace std;
class Queue{
    int rear;
    int front;
    int *arr;
    int size;
public:
    Queue(int _size=5){
        rear=front=-1;
        size=_size;
        arr=new int[size];
    }
    int IsEmpty(){
        return rear==-1;
    }
    int IsFull(){
        return (rear==size-1 && front==0 || front==rear+1);
    }
    int Enqueue(int data){
        if(IsFull()==1){
            return 0;
        }
        if(rear==size-1){
            rear=0;
        }
        else if(rear==-1){
            front=rear=0;
        }
        else rear++;
        arr[rear]=data;
    }
    int Dequeue(int &data){
        if(IsEmpty()){
            return 0;
        }
        data=arr[front];
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else front++;
        return 1;

    }
};
int main()
{
    Queue q1;
    q1.Enqueue(12);
    q1.Enqueue(13);
    q1.Enqueue(14);
    int x;
    if(q1.Dequeue(x)){
        cout<<x<<" ";
    }
    if(q1.Dequeue(x)){
        cout<<x<<" ";
    }
    if(q1.Dequeue(x)){
        cout<<x;
    }
    return 0;
}
