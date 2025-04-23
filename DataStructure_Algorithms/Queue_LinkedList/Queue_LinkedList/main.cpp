#include <iostream>
#include<string.h>
using namespace std;
struct Node{
    int id;
    char Name[30];
    Node*next;
    Node*prev;
};
class Queue{
    Node*head;
    Node*tail;
public:
    Queue(){
        head=tail=NULL;
    }
    int isEmpty(){
        if(head==NULL) return 1;
        else return 0;
    }
    void Enqueue(int id,char*Name){
        Node*temp=new Node();
        temp->id=id;
        strcpy(temp->Name,Name);
        if(isEmpty()){
            temp->prev=NULL;
            head=tail=temp;
        }else{
            temp->prev=tail;
            tail->next=temp;
            tail=temp;

        }

    }
    void Dequeue(){
        Node*temp=head;
        if(isEmpty()){
            cout<<"queue is Empty"<<endl;
        }else{

            if(head==tail){
                head=tail=NULL;
            }
            else{
                head=temp->next;
                head->prev=NULL;
            }
        }
        delete temp;
    }
    void Display(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->id<<" "<<temp->Name<<endl;
            temp=temp->next;
        }
    }

};
int main()
{
    Queue q1;
    q1.Enqueue(1,"ghada");
    q1.Enqueue(2,"gehad");
    q1.Display();
    q1.Dequeue();
    q1.Display();
    return 0;
}
