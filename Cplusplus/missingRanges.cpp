/*
 * Given a sorted integer array nums, where the range of elements are in the inclusive range 
 * [lower, upper], return its missing ranges.
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> findMissingRanges(std::vector<int> &nums, int lower, int upper);
void helper(int start, int end, std::vector<std::string> &retvec);

int main()
{
    std::vector<int> nums = {1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    auto res = findMissingRanges(nums, lower, upper);

    for (auto str : res)
    {
        std::cout << str << '\n';
    }
    return 0;
}

std::vector<std::string> findMissingRanges(std::vector<int> &nums, int lower, int upper)
{
    std::vector<std::string> retvec;

    if (nums.size() == 0)
    {
        helper(lower, upper, retvec);
        return retvec;
    }

    if (lower < nums[0])
    {
        helper(lower, nums[0] - 1, retvec);
    }

    for (int i = 1; i < nums.size(); i++)
    {
        // nums[i] > nums[i - 1] + 1 => handles the overflow
        // nums[i] != nums[i - 1] => checks for duplicates
        if (nums[i] != nums[i - 1] && nums[i] > nums[i - 1] + 1)
        {
            helper(nums[i - 1] + 1, nums[i] - 1, retvec);
        }
    }
    if (nums[nums.size() - 1] < upper)
    {
        helper(nums[nums.size() - 1] + 1, upper, retvec);
    }
    return retvec;
}

void helper(int start, int end, std::vector<std::string> &retvec)
{
    std::stringstream ss;

    ss << start;
    if (start != end)
    {
        ss << "->" << end;
    }
    retvec.emplace_back(ss.str());
}