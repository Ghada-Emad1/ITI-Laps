#include <stdio.h>
#include <stdlib.h>
struct emp{
    int id;
    char name[50];
    float salary;
};
int main()
{
    struct emp e;
    printf("Enter the id\n");
    scanf("%d",&e.id);
    printf("Enter the name\n");
    scanf("%s",&e.name);
    printf("Enter the salary\n");
    scanf("%f",&e.salary);

    printf("Id is %d\n",e.id);
    printf("name is %s\n",e.name);
    printf("salary is %f\n",e.salary);

    return 0;
}
