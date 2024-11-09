#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
struct Emp {
    int id;
    char name[60];
};
void New(struct Emp *ptr,int size);
void Display(struct Emp *ptr,int size);
void Display_by_id(struct Emp*ptr,int size,int Emp_id);
void Display_by_name(struct Emp*ptr,int size,char *name);
void Update(struct Emp*ptr,int size,int Emp_id,char *Emp_name);
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
    char menu[6][40]={"New","Display","Display_id","Display_Name","Update","Exit"};
    int size;
    int Emp_id;
    int n=0;
    int flag=0;
    int size_name;
    char Emp_name[20];
    struct Emp *ptr=NULL;
    char ch;
    do{
        system("cls");
        for (int i = 0; i < 6; i++) {
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

            switch (n) {
                case 0:
                    printf("Enter Number Of Employees : ");
                    scanf("%d",&size);
                    ptr=(struct Emp *)malloc(sizeof(struct Emp)*size);
                    if (ptr == NULL) {
                        printf("Memory allocation failed\n");
                        return 1;
                    }
                    New(ptr, size);

                    break;
                case 1:
                    if(ptr!=NULL){
                        Display(ptr,size);
                    }else{
                        printf("No Employees Data to diplay");
                    }

                    break;
                case 2:

                    printf("Enter id of Employee  :");
                    scanf("%d",&Emp_id);
                    if(ptr!=NULL){
                        Display_by_id(ptr,size,Emp_id);
                    }

                    break;
                case 3:
                    printf("Enter Name of Employee : ");
                    scanf("%s",Emp_name);
                   if(ptr!=NULL){
                    Display_by_name(ptr,size,Emp_name);
                   }

                    break;
                case 4:
                    printf("Enter Employee Id : ");
                    scanf("%d",&Emp_id);
                    if(ptr!=NULL){
                        Update(ptr,size,Emp_id,Emp_name);
                    }
                    break;
                case 5:
                    printf("You selected: Exit\n");
                    flag=1;
                    break;
            }
            _getch();
        }
        if(ch==27){
            system("cls");
            printf("Exit");
            flag=1;
        }
     }while(flag!=1);

     if(ptr!=NULL){
        free(ptr);
     }


    return 0;
}
void New(struct Emp *ptr,int size){

    for(int i=0;i<size;i++){
        ptr[i].id=-1;
        strcpy(ptr[i].name,"Not Found");
    }
    int number_of_Emp;
    for(int i=0;i<size;i++){
         printf("Enter Number of Employee from (0 to %d) :",size-1);
         scanf("%d",&number_of_Emp);
          if (number_of_Emp < 0 || number_of_Emp >= size) {
            printf("Invalid Employee Number. Please try again.\n");
            i--;
            continue;
        }
         printf("Enter id of Employee No. %d: ",number_of_Emp);
         scanf("%d",&ptr[number_of_Emp].id);
         printf("Enter Name of Employee No. %d: ",number_of_Emp);
         scanf("%s",ptr[number_of_Emp].name);
    }


}
void Display(struct Emp *ptr,int size){
        for(int i=0;i<size;i++){
        printf("Employee No.%d: ID = %d, Name = %s\n", i, ptr[i].id, ptr[i].name);
    }

}
void Display_by_id(struct Emp*ptr,int size,int Emp_id){
       int found=0;
       for(int i=0;i<size;i++){
         if(ptr[i].id==Emp_id){
         printf("Employee ID = %d, Name = %s\n", ptr[i].id, ptr[i].name);
         found=1;
         break;
       }
    }
    if(!found){
        printf("This Employee Not Found");
    }
}
void Display_by_name(struct Emp*ptr,int size,char *name){
    int found=0;
    for(int i=0;i<size;i++){
        if(strcmp(ptr[i].name,name)==0){
         printf("Employee ID = %d, Name = %s\n", ptr[i].id, ptr[i].name);
         found=1;
         break;
        }
    }
    if(!found){
        printf("This Employee Not Found");
    }
}
void Update(struct Emp*ptr,int size,int Emp_id,char *Emp_name){
    int found=0;
    for(int i=0;i<size;i++){
      if(ptr[i].id==Emp_id){
         printf("Enter New Id : ");
         scanf("%d",&Emp_id);
         ptr[i].id=Emp_id;
         printf("Enter New Name : ");
         scanf("%s",Emp_name);
         strcpy(ptr[i].name,Emp_name);
        found=1;
        printf("Employee informations updated successfully");
        break;
    }
     if(!found){
        printf("This id Not Found");
     }
   }
}
