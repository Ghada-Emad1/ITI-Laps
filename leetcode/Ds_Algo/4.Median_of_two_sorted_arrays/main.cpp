#include <bits/stdc++.h>
#include <iostream>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;

    for (int i : nums1)
    {
        res.push_back(i);
    }
    for (int j : nums2)
    {
        res.push_back(j);
    }
    sort(res.begin(), res.end());

    int start = 0, end = res.size() - 1;
    int mid = (start + end) / 2;
    double ans;
    if (res.size() % 2 != 0)
    {
        ans = res[mid];
    }
    else
    {
        ans = (res[mid] + res[mid + 1]) / 2.000;
    }
    return ans;
}
int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double ans=findMedianSortedArrays(nums1,nums2);
    cout<<ans;
}