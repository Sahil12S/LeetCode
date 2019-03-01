//  We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
// Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int findLHS(vector<int>& nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << findLHS(nums) << endl;
    
    return 0;
}

int findLHS(vector<int>& nums) {
    unordered_map<int, int> myMap;
    
    for (int n : nums)
    {
        myMap[n] += 1;
    }
    
    int ans = 0;

    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        if (myMap.find(it->first + 1) != myMap.end())
        {
            ans = max(ans, it->second + myMap[it->first + 1]);
        }
    }
    return ans;
}