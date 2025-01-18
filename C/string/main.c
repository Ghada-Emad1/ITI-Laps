#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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

    /*int row=3;
    int col=4;
    int arr[row][col];
    int sum[3]={0};
    int avg[4]={0};
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter element of arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            avg[i]+=arr[j][i];

        }
        avg[i]/=3;
    }
    for(int i=0;i<4;i++){
         printf("the average is %d\n",avg[i]);
    }*/
    char name[20]="ahemd";

    printf("%s\n",name);
    printf("%c\n",*name);
    char lname[12]="emad";
    char fname[10]="ghada";
    char fullName[22];
    strcpy(fullName,fname);
    printf("%s\n",fullName);
    strcat(fullName," ");
    strcat(fullName,lname);
    printf("%s \n",fullName);


    char subj[12];
    /*scanf("%s",subj);
    printf("%s",subj);*/ //cut space when i enter it
    /*gets(subj);
    printf("%s\n",subj);*/

    char gender[12]="male";
    char gender2[12]="female";
    for(int i=0;i<12;i++){
        gender2[i]=gender[i];
    }
    printf("%s",gender2);
    gender[5]='n';
    gender[7]='o';
    strcpy(gender,"female");
    //printf("%s",gender);
    for(int i=0;i<12;i++){
        printf("%c,",gender[i]);
    }
    printf("-----------------------\n");
    char names[4][10];
    for(int i=0;i<2;i++){

             gets(names[i]);


    }

    for(int i=0;i<2;i++){

        printf("%s\n",names[i]);
    }

    return 0;
}
