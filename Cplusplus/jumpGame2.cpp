/**
 * Given an array of non-negative integers,
 * you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 */

#include <iostream>
#include <vector>
#include <limits>

using VI = std::vector<int>;

int jump(VI &nums);

int main()
{
    VI nums = {2, 0, 1, 3, 1, 1, 4};
    std::cout << jump(nums) << '\n';
    return 0;
}

int jump(VI &nums)
{
    int jumps = 0;
    int currEnd = 0;
    int currFarthest = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        currFarthest = std::max(currFarthest, i + nums[i]);

        if (i == currEnd)
        {
            jumps++;
            currEnd = currFarthest;
        }
    }
    return jumps;
    /**
    VI dp(nums.size(), std::numeric_limits<int>::max());
    VI last_pos;

    last_pos.push_back(nums.size() - 1);
    dp[nums.size() - 1] = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i == last_pos.back())
        {
            continue;
        }

        std::cout << "i: " << i << '\n';
        if (i + nums[i] == last_pos.back())
        {
            dp[i] = std::min(dp[i], dp[last_pos.back()] + 1);
        }
        else if (i + nums[i] > last_pos.back())
        {
            for (int j = last_pos.size() - 1; j >= 0 && last_pos[j] <= (i + nums[i]); j--)
            {
                dp[i] = std::min(dp[i], dp[last_pos[j]] + 1);
            }
        }
        else
        {
            continue;
        }
        last_pos.push_back(i);
    }
    return dp[0] == std::numeric_limits<int>::max() ? -1 : dp[0];
*/
}