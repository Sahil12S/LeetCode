#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

void selectionSort(vector<int> &nums);
void swap(int *x, int *y);
void print(vector<int> nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 4, 1, 9, 6, 8};
    selectionSort(nums);
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

void selectionSort(vector<int> &nums) {
    int i, j, min_index = -1;

    for (i = 0; i < nums.size(); ++i) {
        min_index = i;

        for (j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[i]) {
                min_index = j;
            }
        }
        
        swap(&nums[i], &nums[min_index]);
    }
}