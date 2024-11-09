#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

struct Emp {
    int id;
    char name[60];
};

void New(struct Emp *ptr, int size);
void Display(struct Emp *ptr, int size);
void Display_by_id(struct Emp *ptr, int size, int Emp_id);
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
    char menu[4][20] = {"New", "Display", "Display_id", "Exit"};
    int size;
    int Emp_id;
    int n = 0;
    int flag = 0;
    struct Emp *ptr = NULL;
    char ch;
    do {
        system("cls");
        for (int i = 0; i < 4; i++) {
            gotoxy(10, 10 + i);
            if (i == n) {
                textattr(0x02);
                printf("%s", menu[i]);
            } else {
                textattr(0x07);
                printf("%s", menu[i]);
            }
        }
        ch = _getch();
        if (ch == -32) {
            ch = _getch();
            switch (ch) {
                case 72:
                    n--;
                    if (n < 0) n = 3;
                    break;
                case 80:
                    n++;
                    if (n > 3) n = 0;
                    break;
            }
        }
        if (ch == 13) {
            system("cls");
            switch (n) {
                case 0:
                    printf("Enter Number Of Employees: ");
                    scanf("%d", &size);
                    ptr = (struct Emp *)malloc(sizeof(struct Emp) * size);
                    if (ptr == NULL) {
                        printf("Memory allocation failed\n");
                        return 1;
                    }
                    New(ptr, size);
                    break;
                case 1:
                    if (ptr != NULL) {
                        Display(ptr, size);
                    } else {
                        printf("No Employees Data to display\n");
                    }
                    break;
                case 2:
                    printf("Enter ID of Employee: ");
                    scanf("%d", &Emp_id);
                    if (ptr != NULL) {
                        Display_by_id(ptr, size, Emp_id);
                    } else {
                        printf("No Employees Data to display\n");
                    }
                    break;
                case 3:
                    printf("You selected: Exit\n");
                    flag = 1;
                    break;
            }
            _getch();
        }
        if (ch == 27) {
            system("cls");
            printf("Exit");
            flag = 1;
        }
    } while (flag != 1);

    if (ptr != NULL) {
        free(ptr);
    }

    return 0;
}

void New(struct Emp *ptr, int size) {
    for (int i = 0; i < size; i++) {
        ptr[i].id = -1;
        strcpy(ptr[i].name, "");
    }
    int number_of_Emp;
    for (int i = 0; i < size; i++) {
        printf("Enter Number of Employee from (0 to %d): ", size - 1);
        scanf("%d", &number_of_Emp);
        if (number_of_Emp < 0 || number_of_Emp >= size) {
            printf("Invalid Employee Number. Please try again.\n");
            i--; // Repeat this iteration
            continue;
        }
        printf("Enter ID of Employee No. %d: ", number_of_Emp);
        scanf("%d", &ptr[number_of_Emp].id);
        printf("Enter Name of Employee No. %d: ", number_of_Emp);
        scanf("%s", ptr[number_of_Emp].name);
    }
}

void Display(struct Emp *ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Employee No.%d: ID = %d, Name = %s\n", i, ptr[i].id, ptr[i].name);
    }
}

void Display_by_id(struct Emp *ptr, int size, int Emp_id) {
    if (ptr == NULL) {
        printf("No employee data available.\n");
        return;
    }

    if (Emp_id < 0 || Emp_id >= size) {
        printf("Invalid Employee ID. Please enter a number between 0 and %d.\n", size - 1);
        return;
    }

    printf("Employee No.%d: ID = %d, Name = %s\n", Emp_id, ptr[Emp_id].id, ptr[Emp_id].name);
}
