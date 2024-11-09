#include <stdio.h>
#include <stdlib.h>
int get_max(int n1,int n2);
int main()
{
   int x,y;
   scanf("%d %d",&x,&y);
   int res=get_max(x,y);
   printf("Maximum Number is %d",res);
    return 0;
}
int get_max(int n1,int n2){
    if(n1>n2){
        return n1;
    }else{
        return n2;
    }
}
