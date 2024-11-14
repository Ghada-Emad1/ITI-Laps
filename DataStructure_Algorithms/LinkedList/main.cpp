#include <iostream>
#include <cstring>  // for strcpy
using namespace std;

struct Node {
    int id;
    char Name[20];
    int age;
    Node *next;
    Node *prev;

};

class LinkedList {
    Node *head;
    Node *tail;
    Node*SearchByIdPriv(int id){
        Node*temp=head;
        while(temp!=NULL){
            if(temp->id==id){
                return temp;
            }else{
                temp=temp->next;
            }
        }
        return NULL;
    }

public:
    LinkedList() {
        head = tail = NULL;
    }

    void append(int id, char *name, int age) {
        Node *temp = new Node();
        temp->age = age;
        temp->id = id;
         strcpy(temp->Name, name);

        if (head == NULL) {
            head = tail = temp;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void Display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->id << " " << temp->Name << " " << temp->age << endl;
            temp = temp->next;
        }
    }

    int counting(){
        int cnt=0;
        Node*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    Node SearchById(int id){
        Node*resNode=SearchByIdPriv(id);
        Node res;
        if(resNode!=NULL){
            res.age=resNode->age;
            res.id=resNode->id;
            strcpy(res.Name,resNode->Name);
            res.prev=NULL;
            res.next=NULL;
        }else{
            res.id=-1;
        }
        return res;
    }
    ~LinkedList(){
        Node*temp=head;
        while(temp!=NULL){
            head=temp->next;

            delete temp;
            temp=head;
        }
    }


};

int main() {
    LinkedList ll;
    ll.append(1, "ghada", 22);
    ll.append(3,"ali",88);
    ll.Display();

    //cout<<ll.counting();
    Node res=ll.SearchById(1);
    if(res.id!=-1){
        cout<<res.id<<" " <<res.Name<< " "<<res.age;
    }
    return 0;
}
