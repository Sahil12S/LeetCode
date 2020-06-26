#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums);

int main()
{
    vector<int> nums = {3, 1, 2, 10, 1};
    vector<int> ans = runningSum(nums);

    for (int i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}

vector<int> runningSum(vector<int>& nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
    }

    return nums;
}