// Given an array with n objects colored red, white or blue,
// sort them in-place so that objects of the same color are adjacent,
// with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);
    for (int n : nums)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

void sortColors(vector<int> &nums)
{
    int l = 0, m = 0;
    int r = nums.size() - 1;
    int tmp = 0;

    while (m <= r)
    {
        if (nums[m] == 0)
        {
            tmp = nums[l];
            nums[l] = nums[m];
            nums[m] = tmp;
            l++, m++;
        }

        else if (nums[m] == 2)
        {
            tmp = nums[r];
            nums[r] = nums[m];
            nums[m] = tmp;
            r--;
        }
        else
        {
            m++;
        }
    }
}