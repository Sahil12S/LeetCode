#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int> nums1, vector<int> nums2);

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {1, 2};

    

    // unordered_set<int> test (nums1.begin(), nums1.end());
    
    for (int n : intersection(nums1, nums2)) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> num1 (nums1.begin(), nums1.end());
    // cout << num1[1] << endl;
    vector<int> result;

    for (int n : nums2) {
        if (num1.find(n) != num1.end()) {
            result.emplace_back(n);
            num1.erase(n);
        }
    }


    return result;
}