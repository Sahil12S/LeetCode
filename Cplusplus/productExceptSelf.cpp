// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].


#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums);
void print(vector<int> nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);
    print(ans);
    return 0;
}

/**
 * [1,2,3,4]
 * 1, 2, 6, 24
 * 24, 24, 12, 4
 */

vector<int> productExceptSelf(vector<int>& nums) {
    /**
    vector<int> numsLeft(nums.size());
    vector<int> numsRight(nums.size());
    vector<int> ans(nums.size());

    // Moving right
    for (int i = 0; i < nums.size(); i++) {
        numsLeft[i] = i > 0 ? numsLeft[i - 1] * nums[i] : nums[i];
    }
    print(numsLeft);

    for (int i = nums.size() - 1; i >= 0; i--) {
        numsRight[i] = (i == nums.size() - 1) ? nums[i] : numsRight[i + 1] * nums[i];
    }
    print(numsRight);

    for (int i = 0; i < nums.size(); i++) {
        ans[i] = (i == 0) ? 1 * numsRight[i + 1] : ((i == nums.size() - 1) ? numsLeft[i - 1] * 1 : numsLeft[i - 1] * numsRight[i + 1]);
    }

    return ans;
    */

   int fromFirst = 1;
   int fromLast = 1;

   vector<int> ans(nums.size(), 1);

   for (int i = 0; i < nums.size(); i++) {
       ans[i] *= fromFirst;
       fromFirst *= nums[i];

       ans[nums.size() - 1 - i] *= fromLast;
        fromLast *= nums[nums.size() - 1 - i];
   }
   return ans;
}

void print(vector<int> nums) {
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}