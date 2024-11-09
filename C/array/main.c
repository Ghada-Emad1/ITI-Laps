#include <stdio.h>
#include <stdlib.h>
#define size 4
int main()
{
   double radius;
   scanf("%lf",&radius);
   double area;
    area=3.141592653*radius*radius;
   printf("%.9f",area);

   return 0;
}
