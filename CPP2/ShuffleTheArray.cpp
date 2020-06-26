#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n);

int main()
{
    vector<int> nums = { 2, 5, 1, 3, 4, 7 };
    int n = 3;
    vector<int> ans = shuffle(nums, n);
    for (auto x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}

vector<int> shuffle(vector<int>& nums, int n)
{
    vector<int> ans(2 * n);

    for (int i = 0, j = 0; i < n; i++, j += 2)
    {
        ans[j] = nums[i];
    }
    for (int i = n, j = 1; i < 2 * n; i++, j += 2)
    {
        ans[j] = nums[i];
    }
    return ans;
}