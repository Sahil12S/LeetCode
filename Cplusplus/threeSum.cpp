/*
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the sum
 * of zero.
 */

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums);

int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};

    auto res = threeSum(nums);
    for (auto vec : res)
    {
        for (int val : vec)
        {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }
    return 0;
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    // Sort it all
    std::sort(nums.begin(), nums.end());

    int arr_size = nums.size();

    std::vector<std::vector<int>> retval;

    for (int i = 0; i < arr_size; i++)
    {
        int left = i + 1;
        int right = arr_size - 1;
        int target = -nums[i];

        while (left < right)
        {
            int sum = nums[left] + nums[right];

            if (sum < target)
            {
                ++left;
            }
            else if (sum > target)
            {
                --right;
            }
            else
            {
                std::vector<int> temp_vec = {nums[i], nums[left], nums[right]};
                retval.emplace_back(temp_vec);

                // Now lets get rid of duplicates
                while (left < right && nums[left] == temp_vec[1])
                {
                    ++left;
                }
                while (left < right && nums[right] == temp_vec[2])
                {
                    --right;
                }
            }
        }
        while (i + 1 < arr_size && nums[i] == nums[i + 1])
        {
            ++i;
        }
    }
    return retval;
}