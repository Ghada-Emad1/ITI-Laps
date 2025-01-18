#include <stdio.h>
#include <stdlib.h>
struct complexing{
    int real;
    int img;
};
int main()
{
    struct complexing cpx1;
    struct complexing cpx2;
    scanf("%d %d",&cpx1.real,&cpx2.img);
    scanf("%d %d",&cpx2.real,&cpx2.img);

    int real_sum =(cpx1.real + cpx2.real);
    int img_sum=(cpx1.img)+(cpx2.img);

    printf("Complex Number is %d + %d ",real_sum,img_sum);

    return 0;
}
