#include <stdio.h>
#include <stdlib.h>
struct emp{
    int id;
    char name[12];
    int salary;
};
int main()
{
    struct emp Emp[12];
    for(int i=0;i<2;i++){
        printf("Enter Employee id No.%d ",i+1);
        scanf("%d",&Emp[i].id);
        printf("Enter Employee Name No.%d ",i+1);
        scanf("%s",Emp[i].name);
        printf("Enter Employee salary No.%d ",i+1);
        scanf("%d",&Emp[i].salary);

    }
    for(int i=0;i<2;i++){
        printf("id of Employee No.%d is %d",i+1,Emp[i].id);
        printf("Name of Employee No.%d is %s",i+1,Emp[i].name);
        printf("Salary of Employee No.%d is %d",i+1,Emp[i].salary);

    }
    return 0;
}
