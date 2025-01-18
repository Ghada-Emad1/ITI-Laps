#include <iostream>

using namespace std;
int Iterative_BinarySearch(int *arr,int size,int key){
    int low=0;
    int high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(key==arr[mid]){
            return mid;
        }else if(key<arr[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int arr[20]={1,2,3,4,5,6};
    int num;
    cout<<"Enter Number You Want to Search : ";
    cin>>num;
    if(Iterative_BinarySearch(arr,6,num)!=-1){
        cout<<"Number "<<num<<" Found at index : "<<Iterative_BinarySearch(arr,6,num);

    }
    return 0;
}
