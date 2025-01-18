#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while(left<right){
            int mid=(left+right)/2;
            int  cnt=0;
            for(auto x:nums){
                cnt+=(x-1)/mid;
            }
            if(cnt<=maxOperations){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
}
int main()
{
    vector<int>nums={9};
    int maxOperations=2;
    cout<<minimumSize(nums,maxOperations);

    return 0;
}
