#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums);

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
    return 0;
}

int majorityElement(vector<int>& nums)
{
    int n = nums.size();
    int e = nums[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (e == nums[i])
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                count = 1;
                e = nums[i];
            }
        }
    }
    return e;
}