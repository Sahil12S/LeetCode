/**
 * Given an integer array nums,
 * find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 */

#include <iostream>
#include <vector>

using VI = std::vector<int>;

int maxProduct(VI &nums);

int main()
{
    // VI nums = {-2, 0, -1};
    VI nums = {-2, 3, -4};
    // VI nums = {2, 3, -2, 4};

    std::cout << maxProduct(nums) << '\n';
    return 0;
}

int maxProduct(VI &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int maxP = nums[0];
    int minP = nums[0];

    int res = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            std::swap(maxP, minP);
        }
        maxP = std::max(maxP * nums[i], nums[i]);
        minP = std::min(minP * nums[i], nums[i]);
        res = std::max(maxP, res);
    }

    return res;
}