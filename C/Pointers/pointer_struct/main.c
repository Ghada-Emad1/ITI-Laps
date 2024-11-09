#include <stdio.h>
#include <stdlib.h>
struct emp{
    int id;
    char name[23];
};
int main()
{
    struct emp e1;
    struct emp *ptremp=&e1;
    printf("Enter Name and id :");
    scanf("%s %d", (ptremp->name),&(ptremp->id));
    printf("%s %d",ptremp->name, ptremp->id);
    return 0;
}
