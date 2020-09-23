#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool helper(vector<int>& nums, int k, int target, int idx);
bool canPartitionKSubsets(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    cout << canPartitionKSubsets(nums, k) << endl;
    return 0;
}

bool helper(vector<int>& nums, int k, int target, int idx)
{
    if (k == 0)
    {
        return true;
    }
    if (target == 0)
    {
        return helper(nums, k - 1, target, 0);
    }

    for (int i = idx; i < nums.size(); i++)
    {
        if (nums[i] != INT32_MAX && target >= nums[i])
        {
            int temp = nums[i];
            nums[i] = INT32_MAX;
            if (helper(nums, k, target - temp, i + 1))
            {
                return true;
            }
            nums[i] = temp;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
    int sum = 0;
    for (int n : nums)
    {
        sum += n;
    }

    if (sum % k != 0)
    {
        return false;
    }

    return helper(nums, k, sum / k, 0);
}