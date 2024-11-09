#include <stdio.h>
#include <stdlib.h>
struct phone{
    int code;
    int exchang;
    int number;
};
int main()
{
    struct phone user1;
    user1.code=212;
    user1.exchang=767;
    user1.number=8900;
    struct phone user2;
    printf("Enter user code : ");
    scanf("%d",&user2.code);
    printf("Enter user exchange : ");
    scanf("%d",&user2.exchang);
    printf("Enter user number : ");
    scanf("%d",&user2.number);

    printf("User 1 number is (%d) %d-%d\n",user1.code,user1.exchang,user1.number);
    printf("User 2 number is (%d) %d-%d\n",user2.code,user2.exchang,user2.number);


    return 0;
}
