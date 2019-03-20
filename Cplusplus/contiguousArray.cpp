// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,1,0,0,1,1,0};
    cout << findMaxLength(nums) << endl;
    return 0;
}

int findMaxLength(vector<int>& nums)
{
    int count = 0;
    int maxL = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        count = count + nums[i] == 0 ? -1 : 1;

        if (map.find(count) == map.end())
        {
            map[count] = i;
        }
        else
        {
            maxL = max(maxL, i - map[count]);
        }
    }
    return maxL;
}