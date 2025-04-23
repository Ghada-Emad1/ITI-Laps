#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char fname[12]="ghada";
    char lname[12]="emad";
    char fullName[24];
    strcpy(fullName,fname);
    strcat(fullName," ");
    strcat(fullName,lname);
    printf("the full name is %s",fullName);
    return 0;
}
