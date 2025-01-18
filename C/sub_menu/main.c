#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
int main()
{
    char menu[3][10]={"New","Display","Exit"};
    char sub[2][10]={"sub1","sub2"};
    int n=0;
    int flag=0;
    int subN=0;
    int New=0;
    char ch;
    do{
        system("cls");
        for (int i = 0; i < 3; i++) {
            gotoxy(10, 10 + i);
            if (i == n) {
                textattr(0x02);
                printf("%s", menu[i]);
            } else {
               textattr(0x07);
                printf("%s", menu[i]);
            }
        }
        ch=_getch();
        if (ch == -32) {
            ch =_getch();
            switch (ch) {
                case 72:
                    n--;
                    if (n < 0) n = 2;
                    break;
                case 80:
                    n++;
                    if (n > 2) n = 0;
                    break;
            }
        }
        if (ch == 13) {
            system("cls");
            switch (n) {
                case 0:
                  New=1;

                do{
                  system("cls");
                  if(New==1){
                    textattr(0x03);
                    printf("New");
                  }else{
                      textattr(0x07);
                      printf("New");
                  }

                    for(int i=0;i<2;i++){
                        gotoxy(5,i);
                        if(i==subN && New==0){
                            textattr(0x03);

                        }else{
                            textattr(0x07);
                        }
                     printf(sub[i]);

                    }

                    if(ch==-32){
                        ch=_getch();
                        switch(ch){
                        case 77:
                            New=0;
                            ch=_getch();
                            if (ch == -32) {
                                ch =_getch();
                                switch (ch) {
                                    case 72:
                                        subN--;
                                        if (subN < 0) subN = 1;
                                        break;
                                        case 80:
                                            subN++;
                                            if (subN > 1) subN = 0;
                                            break;
                                            }
                            break;
                        case 75:
                            New=1;
                            break;
                            }
                        }


                    }

                    ch=_getch();
                }while(ch!=13);

                    break;
                case 1:
                    printf("You selected: Display\n");
                    break;
                case 2:
                    printf("You selected: Exit\n");
                    flag=1;
                    break;
            }


        }
        if(ch==27){
            system("cls");
            printf("Exit");
            flag=1;
        }
        _getch();
     }while(flag!=1);

    return 0;
}
