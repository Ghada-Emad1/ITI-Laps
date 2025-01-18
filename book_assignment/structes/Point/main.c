#include <stdio.h>
#include <stdlib.h>
struct Point{
    int y;
    int x;

};
int main()
{
    struct Point p1;
    struct Point p2;
    struct Point res;
    printf("Enter coordinates for p1 : ");
    scanf("%d %d",&p1.x,&p1.y);
    printf("Enter coordinates for p2 : ");
    scanf("%d %d",&p2.x,&p2.y);
    res.x=p1.x +p2.x;
    res.y=p1.y +p2.y;
    printf("Coordinates of p1+p2 are %d, %d ",res.x,res.y);
    return 0;
}
