/**
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them is
 * that adjacent houses have security system connected and
 * it will automatically contact the police if two adjacent houses were broken into on the same night.
 */

#include <vector>
#include <iostream>

int rob(std::vector<int> &nums);

int main()
{
    std::vector<int> nums = {2, 1, 3, 9, 1};
    std::cout << rob(nums) << '\n';
    return 0;
}

int rob(std::vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }
    if (nums.size() == 2)
    {
        return std::max(nums[0], nums[1]);
    }

    int N = nums.size();
    std::vector<int> dp(N + 1, 0);

    dp[0] = 0;
    dp[1] = nums[0];
    dp[2] = std::max(nums[1], dp[1]);

    for (int i = 2; i < N; i++)
    {
        dp[i + 1] = std::max(dp[i - 2] + nums[i], dp[i - 1] + nums[i]);
        dp[i + 1] = std::max(dp[i + 1], dp[i]);
    }
    return dp[N];
}