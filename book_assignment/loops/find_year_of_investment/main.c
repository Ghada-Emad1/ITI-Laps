#include <stdio.h>
#include <stdlib.h>

int main()
{
    float final_amount,rate,amount,temp;
    int year;
    printf("Enter final amount : ");
    scanf("%f",&final_amount);
    printf("Enter the amount : ");
    scanf("%f",&amount);
    printf("Enter the rate of interest : ");
    scanf("%f",&rate);

    temp=amount;
    while(temp<final_amount){
        temp*=(1+(rate/100));
        year++;
    }
    printf("The number of year to reach your amount is %d year",year);
    return 0;
}
