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
    int fromFirst = 1;
    int fromLast = 1;

    vector<int> ans(nums.size(), 1);

    for (int i = 0; i < nums.size(); i++) {
        ans[i] *= fromFirst;
        fromFirst *= nums[i];

        ans[nums.size() - 1 - i] *= fromLast;
        fromLast *= nums[nums.size() - 1 - i];
    }

    /*
    1,2,3,4
    ans = 24,12,8,6
    ff = 1,2,6,24
    fl = 4,12,24,24
    */
    return ans;
}

void print(vector<int> nums) {
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

/*
fromBegin[0]=1;
vector<int> fromLast(n);
fromLast[0]=1;

for(int i=1;i<n;i++){
    fromBegin[i]=fromBegin[i-1]*nums[i-1];
    fromLast[i]=fromLast[i-1]*nums[n-i];
}
n = 1,2,3,4
fb = 1,1,2,6
fl = 1,4,12,24
*/