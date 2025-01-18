#include <stdio.h>
#include <stdlib.h>

int main()
{
   char another;
   char ch;
    int pound1,shill1,pence1;
    int pound2,shill2,pence2;

    do{

      printf("Enter the first amount : ");
      scanf("%d %d %d",&pound1,&shill1,&pence1);
      printf("Enter the second amount : ");
      scanf("%d %d %d",&pound2,&shill2,&pence2);
      printf("Enter the operator : \n");
      ch=_getch();
      switch(ch){
      case '+':
           pound1+=pound2;
           shill1+=shill2;
           pence1+=pence2;
           break;
      case '-':
        pound1-=pound2;
        shill1-=shill2;
        pence1-=pence2;
        break;
      case '*':
        pound1*=pound2;
        shill1*=shill2;
        pence1*=pence2;
      }


      if(pence1>11){
        shill1+=pence1/12;
        pence1%=12;
      }
      if(shill1>19){
        pound1+=shill1/20;
        shill1%=20;
      }
      printf("The Answer is %d.%d.%d \n",pound1,shill1,pence1);
      printf("Do you wish to continue (y/n)?");
      scanf(" %c",&another);
    }while(another!='n');
    return 0;
}
