// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
    // vector<int> nums = { 1, 1, 2 };
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    cout << removeDuplicates(nums) << endl;
    for(int val : nums)
    {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }

    int i = 1, j = 0;

    while (i < nums.size())
    {
        if (nums[i] ==  nums[j])
        {
            i++;
        }
        else
        {
            nums[++j] = nums[i++];
        }
    }
    return j + 1;
}
