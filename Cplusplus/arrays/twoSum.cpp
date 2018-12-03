#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main(int argc, char const *argv[])
{
    vector<int> nums {-1,-2,-3,-4,-5};
    // vector<int> nums {3,3};

    vector<int> ans = twoSum(nums, -8);
    for (int n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}   


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> myMap;
    vector<int> ans(2);

    for (int a = 0; a < nums.size(); ++a) {
        int otherVal = target - nums[a];
        cout << otherVal << endl;

        if (myMap.find(otherVal) != myMap.end()) {
            ans[0] = myMap[otherVal];
            ans[1] = a;
        }
        cout << myMap[nums[a]] << " " << a << endl;
        myMap[nums[a]] = a;
    }

    // map<int, int>::iterator start = myMap.begin();
    // map<int, int>::iterator end = myMap.end();


    // --end;
    // while (start->first + end->first != target && start != myMap.end()) {

    //     start->first + end->first > target ? --end : ++start;
    // }
  

    // ans[0] = start->second;
    // ans[1] = end->second;
    return ans;
    
}
