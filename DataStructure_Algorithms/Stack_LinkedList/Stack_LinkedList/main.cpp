#include <iostream>
#include<string.h>
using namespace std;
struct Node{
    int id;
    char Name[30];
    Node*prev;
    Node*next;

};
class Stack{
   Node*head;
   Node*tail;
public:
    Stack(){
        head=tail=NULL;
    }
    int isEmpty(){
        if(head==NULL)return 1;
        else{
            return 0;
        }
    }
    void Push(int id,char*Name){
        Node*temp=new Node();
        temp->id=id;
        strcpy(temp->Name,Name);
        if(isEmpty()){

            temp->prev=temp->next=NULL;
            head=tail=temp;

        }else{
            temp->prev=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
        }


    }
    void Pop(){
        Node*temp=head;
        if(isEmpty()){
            cout<<"stack is Empty"<<endl;
        }else{
            head=temp->next;
            head->prev=NULL;
            delete temp;
        }

    }
    void Display(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->id<< " "<<temp->Name<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
    Stack s;
    cout<<"Before Delete Elements from stack : "<<endl;
    s.Push(1,"ghada");
    s.Push(2,"omar");
    s.Push(3,"gehad");
    s.Display();
    cout<<"After Delete Elements from Stack : "<<endl;
    s.Pop();
    s.Display();
    return 0;
}
