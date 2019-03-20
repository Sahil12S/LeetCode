// Given an array of n positive integers and a positive integer s,
// find the minimal length of a contiguous subarray of which the sum ≥ s.
// If there isn't one, return 0 instead.

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,3,1,2,4,3};
    int s = 7;
    cout << minSubArrayLen(s, nums) << endl;
    return 0;
}

int minSubArrayLen(int s, vector<int>& nums)
{
    int l = 0;
    int sum = 0;
    int len = __INT_MAX__;

    for (int r = 0; r < nums.size(); r++)
    {
        sum += nums[r];
        while (sum >= s)
        {
            len = min(len, (r - l + 1));
            sum -= nums[l++];
        }
    }

    return len != __INT_MAX__ ? len : 0;
}