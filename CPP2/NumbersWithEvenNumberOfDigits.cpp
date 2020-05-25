// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

#include <iostream>
#include <vector>

using namespace std;

int findNumbers(vector<int>& nums);

int main()
{
    vector<int> nums = { 555, 901, 482, 1771 };
    cout << findNumbers(nums) << endl;
    return 0;
}

int findNumbers(vector<int>& nums)
{
    int countEven = 0;
    for(int val : nums)
    {
        int count = 0;
        while (val > 0)
        {
            val /= 10;
            count++;
        }
        countEven += count % 2 == 0;
    }
    return countEven;
}