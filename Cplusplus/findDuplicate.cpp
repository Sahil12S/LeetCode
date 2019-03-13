// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
// some elements appear twice and others appear once.
// Find all the elements that appear twice in this array.

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDuplicates(nums);

    for (int n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

/*
    Implementation 2
*/
vector<int> findDuplicates(vector<int>& nums)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] > 0)
        {
            nums[idx] *= -1;
        }
        else
        {
            ans.emplace_back(idx + 1);
        }
    }
    return ans;
}


/*
    Implementation 1

vector<int> findDuplicates(vector<int>& nums)
{
    vector<int> ans;

    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}
*/