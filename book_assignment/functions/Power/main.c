#include <stdio.h>
#include <stdlib.h>
double Power(double n,int p);
int main()
{
    double n;
    printf("Enter Your Number : ");
    scanf("%lf",&n);
    double res=Power(n,2);
    printf("The result is %.2lf ",res);

    return 0;
}
double Power(double n,int p){
    double res=1;
    while(p!=0){
        res*=n;
        p--;
    }
    return res;
}
