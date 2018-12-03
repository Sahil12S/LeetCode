#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containsDuplicate(vector<int>& nums);

int main() {
    vector<int> nums1 = {2, 1, 2, 0, 1};
    vector<int> nums2 = {1, 2, 3, 4, 5};

    cout << containsDuplicate(nums2) << endl;

    return 0;
}

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    bool isUnique = false;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] == nums[i] || nums[i] == nums[i + 1]) {
            isUnique = true;
        }
    }
    return isUnique;
}
