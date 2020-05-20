// https://leetcode.com/problems/non-decreasing-array/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPossibility(vector<int>& nums);

int main()
{
    vector<int> nums = { 4, 2, 3 };
    cout << checkPossibility(nums) << endl;
    return 0;
}

bool checkPossibility(vector<int>& nums)
{
    int dec_count = 0;

    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i - 2] > nums[i - 1])
        {
            dec_count++;
        }

        if (nums[i - 1] > nums[i])
        {
            dec_count++;
            if (nums[i - 2] > nums[i])
            {
                nums[i] = max(nums[i - 1], nums[i - 2]);
            }
            else
            {
                nums[i - 1] = nums[i];
            }
        }
        if (dec_count >= 2)
        {
            return false;
        }
    }
    return (dec_count < 2);
}