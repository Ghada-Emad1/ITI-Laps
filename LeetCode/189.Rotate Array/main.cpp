#include <iostream>
#include <vector>
using namespace std;

void Rotate_array(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // Handle cases where k >= n
    vector<int> temp(n);

    // Copy elements to their new positions
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    // Copy back to the original array
    nums = temp;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Rotate_array(nums, k);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

