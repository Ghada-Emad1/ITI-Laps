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


};

int main() {
    LinkedList ll;
    ll.append(1, "ghada", 22);
    ll.Display();
    return 0;
}
