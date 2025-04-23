#include <iostream>

using namespace std;
void InsertionSort(int *arr,int size){
    int i,j,value;
    for(int i=1;i<size;i++){
        value=arr[i];
        j=i-1;
        while(j>=0&& arr[j]>value){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=value;

    }
}
int main()
{
     int arr[20]={2,4,5,3,1};
    InsertionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
