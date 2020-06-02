// https://leetcode.com/problems/remove-element/
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val);

int main()
{
    // vector<int> nums = { 3, 2, 2, 3 };
    // int val = 3;
    // vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    // int val = 2;
    vector<int> nums = { 2, 2, 2, 2 };
    int val = 2;
    int len = removeElement(nums, val);
    cout << len << '\n';
    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << ' ';
    }
    cout << '\n';
    return 0;
}

int removeElement(vector<int>& nums, int val)
{
    int len = nums.size();

    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        nums[j] = nums[i];
        if (nums[i] == val)
        {
            len--;
            continue;
        }
        j++;
    }
    return len;
}