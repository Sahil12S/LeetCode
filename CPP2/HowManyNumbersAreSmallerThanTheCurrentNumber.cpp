// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums);

int main()
{
    vector<int> nums = { 8, 1, 2, 2, 3 };
    // vector<int> nums = { 6, 5, 4, 8 };
    // vector<int> nums = { 7, 7, 7, 7 };
    vector<int> res = smallerNumbersThanCurrent(nums);
    for (int val : res)
    {
        cout << val << ' ';
    }
    cout << '\n';
    return 0;
}

vector<int> smallerNumbersThanCurrent(vector<int>& nums)
{
/*
    int N = nums.size();
    map<int, vector<int>> num_count;
    for (int i = 0; i < N; i++)
    {
        if (num_count.find(nums[i]) == num_count.end())
        {
            num_count[nums[i]] = vector<int>{i};
        }
        else
        {
            num_count[nums[i]].push_back(i);
        }
    }
    vector<int> counts(N, 0);
    int cumulative_count = N;
    map<int, vector<int>>::iterator it = num_count.begin();
    for (; it != num_count.end(); ++it)
    {
        for (int idx : it->second)
        {
            counts[idx] = N - cumulative_count;
        }
        cumulative_count -= (it->second).size();
    }
    return counts;
*/

    vector<int> counts(101, 0);
    for (int val : nums)
    {
        counts[val]++;
    }

    for (int i = 1; i < counts.size(); i++)
    {
        counts[i] += counts[i - 1];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int idx = nums[i];
        nums[i] = idx == 0 ? 0 : counts[idx - 1];
    }
    return nums;
}