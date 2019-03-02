// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k);

int main(int argc, char const *argv[])
{
    // vector<int> nums = {1,1,1};
    // int k = 2;
    // vector<int> nums = {-1,-1,1};
    // int k = 0;
    // vector<int> nums = {2,4,15,6,3,2,1};
    // int k = 6;
    // vector<int> nums = {28,54,7,-70,22,65,-6};
    // vector<int> nums = {-19,-82,-70,-46,-29,7,15,-72,-7,100,303};
    vector<int> nums = {-92,-63,75,-86,-58,22,31,-16,-66,-67,420};
    int k = 100;

    cout << subarraySum(nums, k) << endl;


    return 0;
}

int subarraySum(vector<int>& nums, int k)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    
    return count;
}