/**
 * Find the number that appears once.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singleNumber(vector<int>& A_ptr);

int main() {
    vector<int> nums1 = {2, 1, 2, 0, 1};
    vector<int> nums2 = {};
    cout << singleNumber(nums2) << endl;

    return 0;
}


int singleNumber(vector<int>& nums) {
    int appearedOnce = nums[0];
    // bool isOnce = true;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size()-1; i++) {
        if(nums[i] == nums[i+1]) {
            i++;
            continue;
        } else {
            appearedOnce = nums[i];
        }
    }
    return appearedOnce;
}


// 168.4 from 8/6 - 9/6
// 101 from 8/6 - 8/24 divide 5 ways = 20.2 * 5
// 67.4 from 8/25 - 9/6 divide 6 ways = 11.23 * 6 
