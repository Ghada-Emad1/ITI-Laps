#include <stdio.h>
#include <stdlib.h>
struct sterling{
    int pound,shilling,pence;
};
void Scan_Sterling(struct sterling *s1,struct sterling *s2);
struct sterling Summation_Sterling(struct sterling s1,struct sterling s2);
void print_Result(struct sterling s3);
int main()
{
    struct sterling s1,s2,s3;
    Scan_Sterling(&s1,&s2);
    s3=Summation_Sterling(s1,s2);
    print_Result(s3);

    return 0;
}
void Scan_Sterling(struct sterling *s1,struct sterling *s2){
    char ch;
    printf("Enter pound1 , shilling1 and pence1 : ");
    scanf("%d%c%d%c%d",&s1->pound,&ch,&s1->shilling,&ch,&s1->pence);

    printf("Enter pound2 , shilling2 and pence2 : ");
    scanf("%d%c%d%c%d",&s2->pound,&ch,&s2->shilling,&ch,&s2->pence);

}
struct sterling Summation_Sterling(struct sterling s1,struct sterling s2){
    struct sterling res;
    res.pound=s1.pound+s2.pound;
    res.shilling=s1.shilling+s2.shilling;
    res.pence=s1.pence+s2.pence;

    if(res.shilling>19){
        res.pound+=res.shilling/20;
        res.shilling=res.shilling%20;
    }
    if(res.pence>11){
        res.shilling+=res.pence/12;
        res.pence=res.pence%12;
    }
    return res;
}
void print_Result(struct sterling s3){
     printf("The Summation is %d.%d.%d",s3.pound,s3.shilling,s3.pence);

}
