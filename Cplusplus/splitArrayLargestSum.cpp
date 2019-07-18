/**
 * Given an array which consists of non-negative integers and an integer m,
 * you can split the array into m non-empty continuous subarrays.
 * Write an algorithm to minimize the largest sum among these m subarrays.
 * 
 * Note:
 * If n is the length of array, assume the following constraints are satisfied:
 * 
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 */

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)

using VI = std::vector<int>;

int splitArray(VI &nums, int m);

int main()
{
    VI nums = {35, 25, 10, 8, 15, 4, 1, 25, 53};
    int m = 3;
    std::cout << splitArray(nums, m) << '\n';
    return 0;
}

int splitArray(VI &nums, int m)
{
    long left = 0;
    long right = 0;
    int n = nums.size();

    // We find sum of array
    // and max number in array
    // Intuition: Result will be between max number of array and its sum
    for (auto n : nums)
    {
        right += n;
        // std::cout << n << ' ' << left << '\n';
        if (left < n)
        {
            left = n;
        }
    }

    long ans = right;

    while (left <= right)
    {
        long mid = left + (right - left) / 2;
        long curr_sum = 0;
        int count = 1;
        FORI(0, n)
        {
            if (curr_sum + nums[i] > mid)
            {
                curr_sum = nums[i];
                count++;
            }
            else
            {
                curr_sum += nums[i];
            }
        }
        // std::cout << "Left: " << left << "\tRight: " << right << "\tMid: " << mid << "  \tCount: " << count << '\n';

        // If count is less than the required number of partitions
        // then it means we have to split it more.
        // So, to split it in more parts, we have to shift our mid towards left,
        // for that we move our right
        // and it ensures maximum sum of subarray will not exceed mid
        if (count <= m)
        {
            // Here we found an answer, but there could be
            // other value smaller than this value
            // so we move towards left
            ans = std::min(ans, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return static_cast<int>(ans);
}