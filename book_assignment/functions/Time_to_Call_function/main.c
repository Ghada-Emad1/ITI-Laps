#include <stdio.h>
#include <stdlib.h>

int Calling_You2();

int main()
{

   for(int i=1;i<=10;i++){
    printf("I have been called %d times\n",Calling_You2());
   }
    return 0;
}

int Calling_You2(){
    static cnt=0;
    return ++cnt;
}
