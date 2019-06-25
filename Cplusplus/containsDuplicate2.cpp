/**
 * Given an array of integers and an integer k,
 * find out whether there are two distinct indices i and j in the array
 * such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)
#define FORK(s, n) for (int k = s; k < n; k++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

bool containsNearbyDuplicate(VI &nums, int k);

int main()
{
    // VI nums = {1, 2, 3, 1};
    // int k = 3;
    // VI nums = {1, 0, 1, 1};
    // int k = 1;
    VI nums = {1, 2, 3, 1, 2, 3};
    int k = 3;
    std::cout << containsNearbyDuplicate(nums, k) << '\n';
    return 0;
}

bool containsNearbyDuplicate(VI &nums, int k)
{
    if (nums.empty())
    {
        return false;
    }

    std::unordered_map<int, int> m;

    FORI(0, nums.size())
    {
        if (m.count(nums[i]) > 0 && i - m[nums[i]] <= k)
        {
            return true;
        }
        m[nums[i]] = i;
    }
    return false;
}