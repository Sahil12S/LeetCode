#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target);

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(numbers, target);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}

vector<int> twoSum(vector<int>& numbers, int target)
{
    vector<int> nums(2);
    for (int i = 0, j = numbers.size() - 1; i < j;)
    {
        int sum = numbers[i] + numbers[j];
        if (sum == target)
        {
            nums[0] = i + 1;
            nums[1] = j + 1;
            break;
        }
        else if (sum < target)
        {
            i++;
        }
        else if (sum > target)
        {
            j--;
        }
    }
    return nums;
}