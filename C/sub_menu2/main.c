#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

int main()
{
    char menu[3][10] = { "New", "Display", "Exit" };
    char sub[2][10] = { "sub1", "sub2" };
    int n = 0;
    int flag = 0;
    int subN = 0;
    int inSubMenu = 0;  // Variable to track if we are inside the submenu
    char ch;

    do {
        system("cls");

        if (!inSubMenu) {  // Main menu drawing when not in submenu
            for (int i = 0; i < 3; i++) {
                gotoxy(10, 10 + i);
                if (i == n) {
                    textattr(0x02); // Highlight selected menu item
                    printf("%s", menu[i]);
                } else {
                    textattr(0x07); // Normal color for non-selected items
                    printf("%s", menu[i]);
                }
            }
        } else {  // Submenu drawing
            system("cls");
            if(inSubMenu==1){
                textattr(0x03);
            }else{
                textattr(0x07);
            }
              // Highlight "New" (always active in submenu mode)
            printf("New\n");

            for (int i = 0; i < 2; i++) {
                gotoxy(5, i + 1); // Place submenu items below "New"
                if (i == subN&& inSubMenu==0) {
                    textattr(0x03); // Highlight selected submenu item
                } else {
                    textattr(0x07); // Normal color for non-selected submenu items
                }
                printf("%s", sub[i]);
            }
        }

        ch = _getch();

        if (!inSubMenu) {  // Navigation logic for main menu
            if (ch == -32) {
                ch = _getch();
                switch (ch) {
                    case 72: // Up arrow
                        n--;
                        if (n < 0) n = 2;
                        break;
                    case 80: // Down arrow
                        n++;
                        if (n > 2) n = 0;
                        break;
                }
            }
            if (ch == 13) {  // Enter key
                switch (n) {
                    case 0:  // "New" selected
                        inSubMenu = 1;  // Enter the submenu
                        break;
                    case 1:  // "Display" selected
                        system("cls");
                        printf("You selected: Display\n");
                        _getch();
                        break;
                    case 2:  // "Exit" selected
                        flag = 1;  // Exit program
                        break;
                }
            }
        } else {  // Navigation logic for submenu
            if (ch == -32) {
                ch = _getch();
                switch (ch) {
                    case 72:  // Up arrow in submenu
                        subN--;
                        if (subN < 0) subN = 1;
                        break;
                    case 80:  // Down arrow in submenu
                        subN++;
                        if (subN > 1) subN = 0;
                        break;
                    case 77:
                        inSubMenu=0;
                        break;
                    case 75:  // Left arrow to go back to main menu
                        inSubMenu = 1;
                        break;
                }
            }
        }

        if (ch == 27) {  // Escape key for exit
            system("cls");
            printf("Exit");
            flag = 1;
        }

    } while (flag != 1);

    return 0;
}

