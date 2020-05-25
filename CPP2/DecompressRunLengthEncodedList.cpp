// https://leetcode.com/problems/decompress-run-length-encoded-list/

#include <iostream>
#include <vector>

using namespace std;

vector<int> decompressRLElist(vector<int>& nums);

int main()
{
    vector<int> nums = { 1, 1 };
    auto res = decompressRLElist(nums);
    for(auto val : res)
    {
        cout << val << ' ';
    }
    cout << '\n';
    return 0;
}

vector<int> decompressRLElist(vector<int>& nums)
{
    vector<int> res;

    for (int i = 0; (2 * i + 1) < nums.size(); i++)
    {
        int freq = nums[2 * i];
        int val = nums[2 * i + 1];

        while (freq--)
        {
            res.push_back(val);
        }
    }
    return res;
}