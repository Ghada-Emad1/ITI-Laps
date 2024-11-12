#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
using namespace std;

struct Node {
    int id;
    char Name[30];
    Node *next;
    Node *prev;
};

class EmpList {
    Node *head;
    Node *tail;

public:
    EmpList() : head(NULL), tail(NULL) {}

    void AddEmp(int id, const char *Name) {
        Node *temp = new Node();
        temp->id = id;
        strcpy(temp->Name, Name);


        if (head == NULL) {
            head = tail = temp;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void Display() {
        if (head == NULL) {
            cout << "No Employees Data to display\n";
            return;
        }

        Node *temp = head;
        while (temp != NULL) {
            cout << "Employee Id: " << temp->id << ", Employee Name: " << temp->Name << endl;
            temp = temp->next;
        }
    }

    ~EmpList() { // Destructor to free memory
        Node *current = head;
        while (current) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

void textattr(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    char menu[6][40] = {"New", "Display", "Display_id", "Display_Name", "Update", "Exit"};
    int n = 0, flag = 0;
    EmpList Emp;
    char ch;

    do {
        system("cls");
        for (int i = 0; i < 6; i++) {
            gotoxy(10, 10 + i);
            if (i == n) {
                textattr(0x02);
                cout << menu[i] << endl;
            } else {
                textattr(0x07);
                cout << menu[i] << endl;
            }
        }

        ch = _getch();
        if (ch == -32) {
            ch = _getch();
            switch (ch) {
               case 72:
                    n--;
                    if (n < 0) n =5 ;
                    break;
                case 80:
                    n++;
                    if (n > 5) n = 0;
                    break;
            }
        }

        if (ch == 13) {
            system("cls");
            int empId;
            char empName[30];
            int size;

            switch (n) {
                case 0:
                    cout << "Enter Number of Employees: ";
                    cin >> size;
                    for (int i = 0; i < size; i++) {
                        cout << "Enter Employee Id: ";
                        cin >> empId;
                        cout << "Enter Employee Name: ";
                        cin.ignore();
                        cin.getline(empName, 30);
                        Emp.AddEmp(empId, empName);
                    }
                    break;

                case 1:
                    Emp.Display();
                    break;

                case 5:
                    cout << "You selected: Exit\n";
                    flag = 1;
                    break;
            }
            _getch();
        }

        if (ch == 27) {
            system("cls");
            cout << "Exit\n";
            flag = 1;
        }
    } while (flag != 1);

    return 0;
}




