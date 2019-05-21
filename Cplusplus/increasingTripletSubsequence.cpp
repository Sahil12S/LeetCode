/*
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

 * Formally the function should:

 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 * Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
 */

#include <iostream>
#include <vector>
#include <limits>

bool increasingTriplet(std::vector<int> &nums);

int main()
{
    // std::vector<int> nums = {1, 2, 3, 4, 5};
    // std::vector<int> nums = {5, 4, 3, 2, 1};
    // std::vector<int> nums = {4, 2, 5, 1, 6};
    // std::vector<int> nums = {2, 4, -2, -3};
    std::vector<int> nums = {1, 2, -10, -8, -7};

    std::cout << increasingTriplet(nums) << std::endl;
    return 0;
}

bool increasingTriplet(std::vector<int> &nums)
{
    int num1 = std::numeric_limits<int>::max();
    int num2 = std::numeric_limits<int>::max();

    for (int x : nums)
    {
        if (x <= num1)
        {
            // Its the minimum so far
            num1 = x;
        }
        else if (x <= num2)
        {
            // Its greater than num1 but less than num2
            num2 = x;
        }
        else
        {
            // We found the largest number
            return true;
        }
    }
    return false;
}