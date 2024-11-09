#include <stdio.h>
#include <stdlib.h>
struct Distance{
    int feet;
    int inches;
};
struct Distance LargestDistance(struct Distance d1,struct Distance d2);

int main()
{
    struct Distance d1,d2,d3;
    printf("Enter feet : ");
    scanf("%d",&d1.feet);
    printf("Enter Inches : ");
    scanf("%d",&d1.inches);

    printf("Enter feet : ");
    scanf("%d",&d2.feet);
    printf("Enter Inches : ");
    scanf("%d",&d2.inches);
    d3=LargestDistance(d1,d2);
    printf("Largest is %d %d",d3.feet,d3.inches);
    return 0;
}
struct Distance LargestDistance(struct Distance d1,struct Distance d2){
    if(d1.feet>d2.feet){
        return d1;
    }
    if(d1.feet<d2.feet){
        return d2;
    }
    if(d1.inches>d2.inches){
        return d1;
    }else{
        return d2;
    }
}

