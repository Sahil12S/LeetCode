/**
 * Given an array nums and a value val,
 * remove all instances of that value in-place and return the new length.
 */

#include <iostream>
#include <vector>

int removeElement(std::vector<int> &nums, int val);
void swap(std::vector<int> &nums, int i, int j);

int main()
{
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    std::cout << removeElement(nums, val) << std::endl;
    return 0;
}

int removeElement(std::vector<int> &nums, int val)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int end = nums.size() - 1;
    for (int start = 0; start < nums.size(); start++)
    {
        if (nums[start] == val)
        {
            while (end >= 0 && end >= start && nums[end] == val)
            {
                end--;
            }

            if (start > end)
            {
                break;
            }
            swap(nums, start, end);
            end--;
        }
    }

    return end + 1;
}

void swap(std::vector<int> &nums, int i, int j)
{
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}