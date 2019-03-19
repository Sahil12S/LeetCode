// Given a collection of distinct integers, return all possible permutations.

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int>> permute(vector<int>& nums);
void helpPerm(vector<int>& nums, int left, int right);
bool check(vector<int> nums, int l, int r);

void swap(string& s, int l, int r);
void print(vector< vector<int>> vals);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 3};
    print (permute(nums));
    return 0;
}

vector<vector<int>> perms;

vector< vector<int>> permute(vector<int>& nums)
{
    if (nums.size() <= 1)
    {
        perms.push_back(nums);
        return perms;
    }

    helpPerm(nums, 0, nums.size() - 1);
    return perms;
}

void helpPerm(vector<int>& nums, int left, int right)
{
    if (left > right)
    {
        // cout << gigit 
        perms.push_back(nums);
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            if (check(nums, left, i))
            {
                swap(nums[left], nums[i]);
                helpPerm(nums, left + 1, right);
                swap(nums[left], nums[i]);
            }
        }
    }
    
}
/*
1,2,3|1,2,3|
l = 0
i = 0,1
r = 2
*/
bool check(vector<int> nums, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        if (nums[i] == nums[r])
        {
            return false;
        }
    }
    return true;
}

void print(vector< vector<int>> vals)
{
    for (vector<int> num : vals)
    {
        for (auto n : num)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    // cout << endl;
}