// Given 2 arrays, find intersection between them.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    vector<int> result = intersection(nums1, nums2);
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> num1(nums1.begin(), nums1.end());
    vector<int> intersecting;

    for (int n : nums2) {
        if (num1.count(n)) {
            intersecting.emplace_back(n);
            num1.erase(n);
        }
    }
    return intersecting;
}