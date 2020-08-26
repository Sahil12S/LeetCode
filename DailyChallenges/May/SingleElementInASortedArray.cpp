#include <iostream>
#include <vector>

using namespace std;


int singleNonDuplicate(vector<int>& nums);

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums) << endl;
    return 0;
}


int singleNonDuplicate(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int low = 0;
    int high = nums.size() - 1;
    
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid - 1] == nums[mid])
        {
            mid++;
        }
        else if (nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        if ((high - mid + 1) % 2 == 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }
        cout << low << " " << mid << " " << high << endl;
    }
    return nums[low];
}