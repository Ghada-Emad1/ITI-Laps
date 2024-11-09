#include <stdio.h>
#include <stdlib.h>

int main()
{
    float amount;
    int year;
    float percent;
    printf("Enter initial amount : ");
    scanf("%f",&amount);
    printf("Enter number of years : ");
    scanf("%d",&year);
    printf("Enter interest rate (percent per year): ");
    scanf("%f",&percent);

    for(int i=0;i<year;i++){
        amount=amount+(amount*percent/100);

    }
    printf("At the end of %d years , you will have %.2f dollars ",year,amount);
    return 0;
}
