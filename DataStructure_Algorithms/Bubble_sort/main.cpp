#include <iostream>

using namespace std;
void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
void BubbleSort(int *arr,int size){
    int swapped=0;
    int i,j;
    for(int i=1;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[i]<arr[j]){
                swapped=1;
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main()
{
    int arr[20]={2,4,5,3,1};
    BubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
