#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int size;
    printf("Enter size of the square : \n");
    scanf("%d", &size);
    int total = size * size;
    int row, col;
    for(int i=1;i<=total;i++){
        if (i==1){
            row=1;
            col=(size+1)/2;
        }else if((i-1)%size==0 ){
           row++;
        }else {
            row--;
            col--;
        }
        if(row==0){
            row=size;
        }
        if(col==0){
            col=size;
        }
        gotoxy(col,row);
        printf("%d",i);

    }

    return 0;
}

