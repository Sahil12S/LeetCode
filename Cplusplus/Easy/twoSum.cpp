#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target);

int main(int argc, char const *argv[])
{
    vector<int> nums = {-15,-13,-8,-4,-3,-1};
    vector<int> ans = twoSum(nums, -12);
    for (int index : ans) {
        cout << index << ": " << nums[index] << endl;
    }
    return 0;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;

    while (i < j) {
        if (numbers[i] + numbers[j] < target) {
            ++i;
        } else if (numbers[i] + numbers[j] > target) {
            --j;
        } else {
            break;
        }
    }
    return {i, j};
}