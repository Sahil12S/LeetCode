// Find minimum in a rotated sorted array.

#include <iostream>
#include <vector>

using namespace std;

// Without duplicates
int findMin(vector<int>& nums);

// Might contain duplicates
int findMin2(vector<int>& nums);

int main(int argc, char const *argv[])
{
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    // vector<int> nums = {3,4,5,1,2};
    // cout << findMin(nums) << endl;

    vector<int> nums = {2,2,2,0,2};
    cout << findMin2(nums) << endl;

    return 0;
}

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= nums[left] == nums[right] <= nums[left]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

int findMin2(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            --right;
        }
    }
    return nums[left];
}