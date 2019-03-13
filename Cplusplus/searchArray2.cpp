// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// You are given a target value to search. If found in the array return true, otherwise return false.

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

bool search(vector<int>& nums, int target);

int main(int argc, char const *argv[])
{
    // vector<int> nums = {2,5,6,0,0,1,2};
    vector<int> nums = {1,1,1,1,1,3,1,1,1};
    // int target = 0;
    // int target = 2;
    int target = 3;

    cout << search(nums, target) << endl;

    return 0;
}


bool search(vector<int>& nums, int target)
{
    int MAX_INT = numeric_limits<int>::max();
    int MIN_INT = numeric_limits<int>::min();

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int n;

        if (left != right && nums[left] == nums[right])
        {
            right--;
            continue;
        }

        if ((nums[mid] < nums[0]) == (target < nums[0]))
        {
            n = nums[mid];
        }
        else
        {
            if (target < nums[0])
            {
                n = MIN_INT;
            }
            else
            {
                n = MAX_INT;
            }
        }

        if (n < target)
        {
            left = mid + 1;
        }
        else if (n > target)
        {
            right = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}