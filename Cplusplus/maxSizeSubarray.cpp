// Given an array nums and a target value k,
// find the maximum length of a subarray that sums to k.
// If there isn't one, return 0 instead.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSubArrayLen(vector<int>& nums, int k);

int main(int argc, char const *argv[])
{
    // vector<int> nums = {1, -1, 5, -2, 3};
    // int k = 3;
    vector<int> nums = {-2, -1, 2, 1};
    int k = 1;
    cout << maxSubArrayLen(nums, k) << endl;
    return 0;
}

int maxSubArrayLen(vector<int>& nums, int k)
{
    int maxL = 0;
    int sum = 0;

    unordered_map<int, int> sumIdxMap;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == k)
        {
            maxL += i + 1;
        }

        if (sumIdxMap.find(sum) == sumIdxMap.end())
        {
            sumIdxMap[sum] = i;
        }

        if (sumIdxMap.find(sum - k) != sumIdxMap.end())
        {
            int idx = sumIdxMap[sum - k];
            if (maxL < i - idx)
            {
                maxL = max(maxL, i - idx);
            }
        }
    }
    return maxL;
}