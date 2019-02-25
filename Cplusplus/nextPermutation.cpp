// mplement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums);
void print(vector<int> nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    // vector<int> nums = {3,2,1};
    nextPermutation(nums);
    print(nums);
    return 0;
}

void nextPermutation(vector<int>& nums)
{
    // vector<int>* num_ptr = &nums;
    auto index = is_sorted_until(nums.rbegin(), nums.rend());
    cout << "index " << *index << endl;

    if (index == nums.rend())
    {
        // sort in ascending order.
        reverse(nums.rbegin(), nums.rend());
        print(nums);
        return;
    }

    auto to_swap_with = upper_bound(nums.rbegin(), index, *index);
    // cout << "Check: " << *to_swap_with << endl;
    iter_swap(index, to_swap_with);
    // cout << "index: " << *index << ", next: " << *to_swap_with << endl;
    print(nums);
    reverse(nums.rbegin(), index);
}

void print(vector<int> nums)
{
    for (auto n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
}