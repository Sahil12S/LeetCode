/**
 * Given a sorted array A of unique numbers,
 * find the K-th missing number starting from the leftmost number of the array.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int missingElement(VI &nums, int k);

int main()
{
    VI nums = {4, 7, 9, 10};
    int k = 1;
    std::cout << missingElement(nums, k) << '\n';
    return 0;
}

int missingElement(VI &nums, int k)
{
    VI counts(nums.size(), 0);

    FORI(1, nums.size())
    {
        if (i > 0)
        {
            counts[i] = nums[i] - nums[i - 1] - 1;
        }
    }
    int idx = -1;
    FORI(0, counts.size())
    {
        if (counts[i] >= k)
        {
            idx = i;
            break;
        }
        k -= counts[i];
    }

    return idx > -1 ? (nums[idx] - counts[idx] - 1 + k) : nums[nums.size() - 1] + k;
}

int missingElement2(VI &nums, int k)
{
    int left = 0;
    int right = nums.size() - 1;

    int missing = nums[right] - nums[left] + 1 - nums.size();

    if (missing < k)
    {
        return nums[right] + k - missing;
    }

    while (left < right - 1)
    {
        int mid = left + (right - left) / 2;
        int count = nums[mid] - nums[left] - (mid - left);

        if (count >= k)
        {
            right = mid;
        }
        else
        {
            k -= count;
            left = mid;
        }
    }
    return nums[left] + k;
}