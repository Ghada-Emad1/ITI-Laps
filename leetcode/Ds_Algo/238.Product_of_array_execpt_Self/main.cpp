#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    vector<int> nums = {1,2,3,4};
    int n=nums.size();
    vector<int>res(n,1);
    for(int i=1;i<n;i++){
        res[i]=res[i-1]*nums[i-1];
    }
    int postfix=1;
    for(int i=n-1;i>=0;i--){
       res[i]*=postfix;
       postfix*=nums[i];
    }
    for(int i=0;i<res.size();i++)
{
    cout<<res[i]<<" ";
}    
}