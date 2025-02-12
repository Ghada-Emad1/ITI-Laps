#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums={1,1,1,2,2,3};
    int k=2;
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    vector<pair<int,int>>pr;
    for(auto & i :mp){
        pr.push_back({i.second,i.first});
    }
    cout<<"Before sorting ===="<<endl;
    for(auto i: pr){
        cout<<i.first<< " "<<i.second<<" "<<endl;
    }
    sort(pr.rbegin(),pr.rend());
    cout<<"After Sorting ===="<<endl;
    for(auto i: pr){
        cout<<i.first<< " "<<i.second<<" "<<endl;
    }
    vector<int>res;
    for(int i=0;i<k;i++){
        res.push_back(pr[i].second);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    
}