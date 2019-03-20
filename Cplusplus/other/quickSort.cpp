// Implement quicksort

#include <iostream>
#include <vector>

using namespace std;

void quickSort1(vector<int>& nums, int left, int right);
void quickSort2(vector<int>& nums, int left, int right);
int partition(vector<int>& nums, int left, int right);
void partition2(vector<int>& nums, int left, int right, int& i, int& j);
void print(vector<int> nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {10,80,30,90,40,50,70};

    quickSort2(nums, 0, nums.size() - 1);
    print(nums);

    return 0;
}

void quickSort1(vector<int>& nums, int left, int right)
{
    if (left < right)
    {
        int pi = partition(nums, left, right);

        quickSort1(nums, left, pi - 1);
        quickSort1(nums, pi + 1, right);
    }
}

int partition(vector<int>& nums, int left, int right)
{
    int pivot = nums[right];

    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[j], nums[i]);
        }
    }

    swap(nums[i + 1], nums[right]);
    return (i + 1);
}

void quickSort2(vector<int>& nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int i, j;

    partition2(nums, left, right, i, j);

    quickSort2(nums, left, i);
    quickSort2(nums, j, right);
}

void partition2(vector<int>& nums, int left, int right, int& i, int& j)
{
    if (right - left <= 1)
    {
        if (nums[right] < nums[left])
        {
            swap(nums[right], nums[left]);
        }

        i = left;
        j = right;
        return;
    }

    int mid = left;
    int pivot = nums[right];

    while  (mid <= right)
    {
        if (nums[mid] < pivot)
        {
            swap(nums[left++], nums[mid++]);
        }
        else if (nums[mid] == pivot)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[right--]);
        }
    }
    i = left - 1;
    j = mid;
}

void print(vector<int> nums)
{
    for (int n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
}