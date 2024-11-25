#include <iostream>
#include<string.h>
using namespace std;
void SelectionSort(char arr[4][10],int size){
    for(int i=0;i<size-1;i++){
            int minimum=i;
        for(int j=i+1;j<size;j++){
            if(strcmp(arr[minimum],arr[j])==1){
                minimum=j;
            }
        }
        if(minimum!=i){
            char temp[20];
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[minimum]);
            strcpy(arr[minimum],temp);
        }
    }


}
int main()
{
    char arr[4][10]={"ghada","rokaya","alaa"};
    /*cout<<strcmp("ghada","rokaya");
    cout<<strcmp("ghada","alaaa");*/
    SelectionSort(arr,3);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<endl;
    }

    /*SelectionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }*/
    return 0;
}
