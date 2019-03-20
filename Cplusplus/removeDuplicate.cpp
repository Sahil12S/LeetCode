// Given a sorted array nums, remove the duplicates in-place 
// such that each element appear only once and return the new length.
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main() {
    vector<int> nums = {0, 0, 1, 1, 2, 2, 2, 3};
    int length = removeDuplicates(nums);

    printf("Length: %d\n", length);

    for (size_t i = 0; i < nums.size(); i++) {
        printf("%d", nums[i]);
    }
    printf("\n");
    return 0;
}


int removeDuplicates(vector<int>& nums) {
    int count = 1;
    for (int i = 0, j = 0; i < nums.size(); i++) {
        if( nums[i] == nums[j] ) {
            continue;
        } else {
            count++;
            nums[++j] = nums[i];
        }
    }
    return count;
}
