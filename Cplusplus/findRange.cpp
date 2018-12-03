// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target);

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,7,7,8,8,9};

    for (int index : searchRange(nums, 8)) {
        cout << index << endl;
    }

    return 0;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    vector<int> range(2, -1);

    // Finding the start position/index.
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[left] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (nums[left] == target) {
        range[0] = left;
    } else if (nums[right] == target) {
        range[0] = right;
    } else {
        return range;
    }

    // Now that we got starting index, lets find end index from start.
    right = nums.size() - 1;
    while (left + 1 < right) {
        int mid = (left + (right - left) / 2);

        if (nums[mid] > target) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (nums[right] == target) {
        range[1] = right;
    } else if (nums[left] == target) {
        range[1] = left;
    }
    return range;

}
