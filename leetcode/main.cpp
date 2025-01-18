#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums={2,3,3,2};
    int val=3;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            nums[ans]=nums[i];
            ans++;
        }
    }
    cout<<ans;

}