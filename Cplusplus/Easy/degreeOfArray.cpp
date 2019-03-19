// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int findShortestSubarray(vector<int>& nums);

int main(int argc, char const *argv[])
{
    // vector<int> nums = {1,2,2,3,1,4,2};
    vector<int> nums = {1, 2, 2, 3, 1};
    cout << findShortestSubarray(nums) << endl;

    return 0;
}

int findShortestSubarray(vector<int>& nums) {
    /*int MAX_NUM = 50000;
    vector<int> numCount(MAX_NUM, 0);



    for (int i = 0; i < nums.size(); ++i) {
        numCount[nums[i]]++;
    }

    // Find numbers with max frequency
    int maxCount = -1;
    map<int, int> number;

    for (int i = 0; i < MAX_NUM; i++) {
        if (numCount[i] >= maxCount) {
            maxCount = numCount[i];
            number[i] = -1;
        }
    }

    map<int, int>::iterator it = number.begin();

    int minLength = MAX_NUM;

    for (; it != number.end(); ++it) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] != it->first) {
                ++i;
            }
            if (nums[j] != it->first) {
                --j;
            }

            if (nums[i] == nums[j])

            // it->second = (j - i + 1);
        }
        if ((j - i + 1) < minLength) {
            minLength = (j - i + 1);
        }
    }
    */

   map<int, list<int>> numsCount;

   for (int i = 0; i < nums.size(); ++i) {
       numsCount[nums[i]].push_back(i);
   }

    int highestDegree = -1;
    int minSubarrayLength = 50000;

    for (auto it = numsCount.begin(); it != numsCount.end(); it++) {
        cout << "size for: " << it->first << " is " << it->second.size() << endl;
        int listSize = it->second.size();
        if (listSize > highestDegree) {
            highestDegree = listSize;
            minSubarrayLength = (it->second.back() - it->second.front() + 1);
        } else if (listSize == highestDegree) {
            if ((it->second.back() - it->second.front() + 1) < minSubarrayLength) {
                cout << "Sub: " << it->second.back() << " & " << it->second.front() << endl;
                minSubarrayLength = (it->second.back() - it->second.front() + 1);
            }
        }
    }

    return minSubarrayLength;
}