// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
// Find all the elements of [1, n] inclusive that do not appear in this array.

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDisappearedNumbers(nums);

    for (int n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] != nums[nums[i] - 1])
        {
            swap (nums[i], nums[nums[i] - 1]);
        }
        else
        {
            i++;
        }
    }
    for (i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}