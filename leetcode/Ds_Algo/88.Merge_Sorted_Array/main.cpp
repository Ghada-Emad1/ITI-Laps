#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int m=3,n=3;
    vector<int>nums1={1,2,3,0,0,0};
    vector<int>nums2={2,5,6};
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(j>=0){
        if(i>=0 && nums1[i]>nums2[j]){
            nums1[k]=nums1[i];
            i--;
        }else{
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }
    for(int i:nums1){
        cout<<i<<" ";
    }
    
    

}