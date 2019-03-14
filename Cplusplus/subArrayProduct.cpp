// Your are given an array of positive integers nums.
// Count and print the number of (contiguous) subarrays 
// where the product of all the elements in the subarray is less than k.

#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k);

int main(int argc, char const *argv[])
{
    // vector<int> nums = {10, 5, 2, 6};
    // int k = 100;
    vector<int> nums = {1, 1, 1};
    int k = 1;
    cout << numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    if (k <= 1)
    {
        return 0;
    }
    int count = 0;
    int product = 1;
    int left = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        product *= nums[right];
        while (product >= k)
        {
            product /= nums[left++];
            cout << left << endl;
        }
        count += (right - left + 1);
    }
    return count;
}