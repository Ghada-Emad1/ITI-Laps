#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int main()
{
   char ch;
   do{
   system("cls");
   printf("New\nExist\nSelected New Item");
   printf("\nEnter the character:");

   scanf("%c",&ch);
    _flushall();

    switch(ch){
      case 'e':
        printf("exist from program\n");
        break;
      case 'n':
        printf("New\n");
        break;
      case 'd':
       printf("Display\n");
       break;
   }

    getch();
    _flushall();

   }while(ch!='e');




    return 0;
}
