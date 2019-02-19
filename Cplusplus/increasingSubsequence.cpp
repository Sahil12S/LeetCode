// Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums);

int main(int argc, char const *argv[])
{
    // vector<int> nums = {1, 3, 5, 4, 7};
    // vector<int> nums = {2, 2, 2, 2, 2};
    vector<int> nums = {7,6,5,4,3,2};

    cout << findLengthOfLCIS(nums) << endl;

    return 0;
}

int findLengthOfLCIS(vector<int>& nums)
{
    // if (nums.size() <= 1)
    // {
    //     return nums.size();
    // }

    int left = 0, iter = 0;
    int maxLength = 0;

    while (iter < nums.size())
    {
        if (iter + 1 < nums.size() && nums[iter + 1] > nums[iter])
        {
            iter++;
        }
        else
        {
            // cout << "nums: " << nums[iter] << endl;
            maxLength = max(maxLength, (iter - left + 1));
            left = ++iter;// + 1;
            // iter++;
        }
        // cout << "left: " << left << ", iter: " << iter << endl;
    }

    return maxLength;
}