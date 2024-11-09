#include <stdio.h>
#include <stdlib.h>
struct Emp{
    int id;
    char* name;
};
int main()
{
    int size,size_arr;
    printf("Enter size of Struct Array ");
    scanf("%d",&size);
    struct Emp e1;
    struct Emp *ptr=(struct Emp*)malloc(sizeof (struct Emp) * size);
    if(ptr!=NULL){

        for(int i=0;i<size;i++){
            printf("Enter size of Array: ");
            scanf("%d",&size_arr);
            ptr[i].name=(char *)malloc(sizeof(char)*size_arr );
            if(ptr[i].name!=NULL){
                printf("Enter the id of Emp No.%d: ",i+1);
                scanf("%d",&((ptr+i)->id));
                printf("Enter the Name of Emp No.%d: ",i+1);
                scanf("%s",(ptr+i)->name);
            }

        }
        for(int i=0;i<size;i++){
            printf("The id is %d and Name is %s of Emp No.%d \n",ptr[i].id,ptr[i].name,i+1);
        }
        free(ptr);
        for(int i=0;i<size_arr;i++){
            free(ptr[i].name);
        }
    }
    return 0;
}
