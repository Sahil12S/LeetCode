#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main()
{
    vector<int> nums1 = {1, 2, 8, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m  = 3;
    int n = 3;
    merge(nums1, m, nums2, n);
    for (int v : nums1)
    {
        cout << v << ' ';
    }
    cout << endl;
    return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    for (int i = nums1.size() - 1; i >= 0; i--)
    {
        if (m > 0 && n > 0)
        {
            if (nums1[m - 1] >= nums2[n - 1])
            {
                nums1[i] = nums1[m - 1];
                m--;
            }
            else
            {
                nums1[i] = nums2[n - 1];
                n--;
            }
        }
        else if (n > 0)
        {
            nums1[i] = nums2[n - 1];
            n--;
        }
    }
}