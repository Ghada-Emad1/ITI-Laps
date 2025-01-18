#include <iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums={1,1,2};
    int ans=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=nums[i+1]){
            nums[ans]=nums[i];
            ans++;
        }
    }
    cout<<ans;
    
}