#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& nums);
void swap(int *x, int *y);
void print(vector<int> nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 4, 1, 9, 6, 8};
    bubbleSort(nums);
    print(nums);
    return 0;
}

void print(vector<int> nums) {
    for (int num : nums) {
        cout << num << ", ";
    }
    cout << endl;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1 - i; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}