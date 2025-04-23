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
    Node *SearchByIdPriv(int id){
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
    Node*SearchByNamePriv(char*Name){
        Node*temp=head;
        while(temp!=NULL){
            if(strcmp(temp->Name,Name)==0){
                return temp;
            }else{
            temp=temp->next;
            }
        }
        return NULL;
    }

public:
    EmpList() {
        head=tail=NULL;
    }
    EmpList(EmpList&e){
        head=tail=NULL;
        Node*temp=e.head;
        while(temp!=NULL){
            AddEmp(temp->id,temp->Name);
            temp=temp->next;
        }
        cout<<"deep copy constructor"<<endl;
    }

    void AddEmp(int id, char *Name) {
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
        Node *temp = head;
        if(temp==NULL){
            cout<<"There are No Employees "<<endl;
            return;
        }
        while (temp != NULL) {
            cout << "Employee Id: " << temp->id << ", Employee Name: " << temp->Name << endl;
            temp = temp->next;
        }
    }

    int CountEmp(){
        int cnt=0;
        Node*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    Node SearchById(int id){
        Node *resAddr=SearchByIdPriv(id);
        Node res;
        if(resAddr!=NULL){
            res.id=resAddr->id;
            strcpy(res.Name,resAddr->Name);
            res.next=NULL;
            res.prev=NULL;

        }else{
            res.id=-1;
        }
        return res;

    }
    Node SearchByName(char*Name){
        Node*resAddr=SearchByNamePriv(Name);
        Node res;
        if(resAddr!=NULL){
            res.id=resAddr->id;
            strcpy(res.Name,resAddr->Name);
            res.next=NULL;
            res.prev=NULL;
        }else{
            res.id=-1;
        }
        return res;
    }
    void DeleteById(int id){
        Node*res=SearchByIdPriv(id);
        if(res==NULL){
            return;
        }
        if(head==tail){
            head=tail=NULL;
        }
        else if(res==head){
            head=res->next;
            res->prev=NULL;
        }else if(res==tail){
            tail=tail->prev;
            tail->next=NULL;
        }else{
            res->prev->next=res->next;
            res->next->prev=res->prev;
        }
    }
    void DeleteByName(char *Name){
        Node *res=SearchByNamePriv(Name);
        if(res==NULL){
            return;
        }
        if(head==tail){
            head=tail=NULL;
        }
        else if(res==head){
            head=res->next;
            res->prev=NULL;
        }else if(res==tail){
            tail=tail->prev;
            tail->next=NULL;
        }else{
            res->prev->next=res->next;
            res->next->prev=res->prev;
        }

    }
    void insertById(int id,char*Name,int ExistingId){
        if(head==NULL){
            AddEmp(id,Name);
            return;
        }
        Node*res=SearchByIdPriv(ExistingId);
        if(res==tail){
            AddEmp(id,Name);
        }else{
            Node*temp=new Node();
            temp->id=id;
            strcpy(temp->Name,Name);
            temp->prev=res->prev;
            temp->next=res;
            if(res->prev!=NULL){
                res->prev->next=temp;
            }else{
                head=temp;
            }
            res->prev=temp;
        }
    }
    void UpDate(int id,char*Name,int ExistingId){
        Node*res=SearchByIdPriv(ExistingId);
        if(res==NULL){
            cout<<"Employee with Id "<<ExistingId<<" Not Found"<<endl;
            return;
        }
        else{
            res->id=id;
            strcpy(res->Name,Name);
        }

    }
    EmpList& operator=(const EmpList& e){
        Node*temp=head;
        while(temp!=NULL){
            head=temp->next;
            delete temp;
            temp=head;
        }
        head=tail=NULL;
        Node*current=e.head;
        while(current!=NULL){
            AddEmp(current->id,current->Name);
            current=current->next;
        }
        return *this;
    }
    ~EmpList() {
        Node *temp = head;
        while (temp!=NULL) {
           head=temp->next;
           delete temp;
           temp=head;

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
    char menu[11][40] = {"New", "Display","Number_of_Employee" ,"Search By Id","Search By Name", "InsertById", "DeleteById","DeleteByName","Updating","Display_Another_One","Exit"};
    int n = 0, flag = 0;
    EmpList Emp;
    EmpList Emp2;

    Node res;
    char ch;

    do {
        system("cls");
        for (int i = 0; i < 11; i++) {
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
                    if (n < 0) n = 10;
                    break;
                case 80:
                    n++;
                    if (n > 10) n = 0;
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
                        cin>>empName;
                        Emp.AddEmp(empId, empName);
                    }
                    break;

                case 1:
                    Emp.Display();
                    break;
                case 2 :
                    cout<<"Number of Employees is : "<<Emp.CountEmp();
                    break;
                case 3:
                    int id;
                    cout<<"Enter Id of Employee you are looking for : ";
                    cin>>id;
                    res=Emp.SearchById(id);
                    if(res.id!=-1){
                         cout << "Employee Id: " << res.id << ", Employee Name: " <<res.Name << endl;

                    }
                    break;
                case 4:
                    char Name[30];
                    cout<<"Enter Name of Employee you are Looking for : ";
                    cin>>Name;
                    res=Emp.SearchByName(Name);
                    if (res.id!=-1){
                        cout << "Employee Id: " << res.id << ", Employee Name: " <<res.Name << endl;

                    }
                    break;
                case 5:

                    int New_Id,ExistingId;
                    char New_Name[30];
                    cout<<"Enter Existing Id : ";
                    cin>>ExistingId;
                    cout<<"Enter New Id : ";
                    cin>>New_Id;
                    cout<<"Enter New Name : ";
                    cin>>New_Name;
                    Emp.insertById(New_Id,New_Name,ExistingId);
                    break;
                case 6:
                    int Deleted_id;
                    cout<<"Enter ID of Employee You want to Delete : ";
                    cin>>Deleted_id;
                    Emp.DeleteById(Deleted_id);
                    break;
                case 7:
                    char Deleted_Name[30];
                    cout<<"Enter Name of Employee You want to Delete : ";
                    cin>>Deleted_Name;
                    Emp.DeleteByName(Deleted_Name);
                    break;
                case 8:
                    int Update_id;
                    char Update_Name[30];
                    int ExistingId1;
                    cout<<"Enter Id of Employee You Want to Update : ";
                    cin>>ExistingId1;
                    cout<<"Enter New Id : ";
                    cin>>Update_id;
                    cout<<"Enter New Name : ";
                    cin>>Update_Name;
                    Emp.UpDate(Update_id,Update_Name,ExistingId1);
                    break;
                case 9:
                    EmpList Emp2;
                    Emp2=Emp;
                    Emp2.Display();
                    break;

                /*case 5:
                    cout << "You selected: Exit\n";
                    flag = 1;
                    break;*/
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




