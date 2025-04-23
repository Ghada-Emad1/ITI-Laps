#include <stdio.h>
#include <stdlib.h>
float circarea(float redius);
int main()
{
    float redius;
    printf("Enter the radius : ");
    scanf("%f",&redius);
    float res=circarea(redius);
    printf("The Area of Circle is %.2f ",res);
    return 0;
}
float circarea(float redius){
    return redius*redius * 3.14;
}
