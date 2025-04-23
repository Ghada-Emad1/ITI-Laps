#include <stdio.h>
#include <stdlib.h>
struct point {
    int x;
    int y;
};
int main()
{
    struct point p;
    printf("Enter x\n");
    scanf("%d",&p.x);
    printf("Enter y\n");
    scanf("%d",&p.y);
    printf("The point is (%d,%d)",p.x,p.y);
    return 0;
}
