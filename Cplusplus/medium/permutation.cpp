// Given a collection of distinct integers, return all possible permutations.

#include <iostream>
#include <vector>

using namespace std;

// vector<string> permute(string s, int left, int right);
vector< vector<int>> permute(vector<int>& nums);
void helpPerm(vector<int>& nums, int left, int right);

void swap(string& s, int l, int r);
void print(vector< vector<int>> vals);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
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
    if (left == right)
    {
        perms.push_back(nums);
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(nums[left], nums[i]);
            helpPerm(nums, left + 1, right);
            swap(nums[left], nums[i]);
        }
    }
    
}

/*vector<string> perms;
vector<string> permute(string s, int left, int right)
{
    int i;
    if (left == right)
    {
        perms.push_back(s);
    }
    else
    {
        for (i = left; i <= right; i++)
        {
            swap(s, i, left);
            permute(s, left + 1, right);
            swap(s, left, i);
        }
    }
    return perms;
    
}*/

void swap(string& s, int i, int l)
{
    char temp = s[l];
    s[l] = s[i];
    s[i] = temp;
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
    cout << endl;
}