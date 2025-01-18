#include <stdio.h>
#include <stdlib.h>

int main()
{
    int type;
    printf("Enter Type ");
    scanf("%d",&type);
    float fahr=0.0,celsus=0.0;
    float res=0.0;
    if(type == 1){
        printf("Enter Temperature in Fahrenhiet :");
        scanf("%f",&fahr);
        res=(fahr -32)/1.8;
        printf("IN Celsius That is %f",res);
    } else{
        printf("Enter Temperature in Celsius : ");
        scanf("%f",&celsus);
        res=(celsus *1.8)+32;
        printf("IN Fahrenheit %f: ",res);
    }
    return 0;
}
