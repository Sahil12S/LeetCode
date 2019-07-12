/*
Given an integer array, 
your task is to find all the different possible increasing subsequences of the given array, 
and the length of an increasing subsequence should be at least 2 .
*/

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

using namespace std;

VVI findSubsequences(VI &nums);

int main(int argc, char const *argv[])
{
    VI nums = {4, 6, 7, 7};
    VVI ans = findSubsequences(nums);
    for (auto pair : ans)
    {
        for (auto n : pair)
        {
            std::cout << n << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}

VVI findSubsequences(VI &nums)
{
    VI dp;
    VVI ans;

    FORI(0, std::size(nums))
    {
    }
    return ans;
}