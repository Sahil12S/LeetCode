#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

VVI subsets(VI &nums);
void backtrack(VI temp, VVI &ans, const VI &nums, int i);
void backtrack2(VI temp, VVI &ans, const VI &nums, int i);

int main()
{
    // VI nums = {1, 3, 2, 5, 4};
    VI nums = {1, 2, 3, 5, 4, 8, 7, 6, 20, 15, 19, 10, 9, 12, 11, 18, 13, 14, 17, 16};
    VVI ans = subsets(nums);
    // for (auto arr : ans)
    // {
    //     for (auto val : arr)
    //     {
    //         std::cout << val << " ";
    //     }
    //     std::cout << '\n';
    // }
    return 0;
}

VVI subsets(VI &nums)
{
    /**
    if (nums.empty())
    {
        return {};
    }
    VVI res;
    backtrack2({}, res, nums, 0);
    return res;
    */

    VVI res = {{}};

    for (auto num : nums)
    {
        int n = res.size();
        FORI(0, n)
        {
            res.push_back(res[i]);
            res.back().push_back(num);
        }
    }
    return res;
}

void backtrack(VI temp, VVI &ans, const VI &nums, int i)
{
    if (i == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    backtrack(temp, ans, nums, i + 1);
    temp.push_back(nums[i]);
    backtrack(temp, ans, nums, i + 1);
}

void backtrack2(VI temp, VVI &ans, const VI &nums, int start)
{
    ans.push_back(temp);
    FORI(start, nums.size())
    {
        temp.push_back(nums[i]);
        backtrack2(temp, ans, nums, i + 1);
        temp.pop_back();
    }
}