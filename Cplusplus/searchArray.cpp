// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// You are given a target value to search. If found in the array return its index, otherwise return -1.

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int search(vector<int>& nums, int target);

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << search (nums, target) << endl;
    return 0;
}

int search(vector<int>& nums, int target)
{
    int MAX = numeric_limits<int>::max();
    int MIN = numeric_limits<int>::min();

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int n;

        if (nums[mid] < nums[0] == target < nums[0])
        {
            n = nums[mid];
        }
        else
        {
            if (target < nums[0])
            {
                n = MIN;
            }
            else
            {
                n = MAX;
            }
        }

        if (n == target)
        {
            return mid;
        }
        else if (n < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}