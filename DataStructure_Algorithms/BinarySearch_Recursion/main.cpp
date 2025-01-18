#include <iostream>

using namespace std;
int Rec_BinarySearch(int *arr,int size,int key,int low,int high){

    if(low>high){
        return -1;
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(key==arr[mid]){
            return mid;
        }else if(key<arr[mid]){
            Rec_BinarySearch(arr,size,key,low,mid-1);

        }else{
            Rec_BinarySearch(arr,size,key,mid+1,high);

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

    if(Rec_BinarySearch(arr,6,num,0,5)!=-1){
          cout<<"Number "<<num<<" Found at index : "<<Rec_BinarySearch(arr,6,3,0,5);
    }
    return 0;
}
