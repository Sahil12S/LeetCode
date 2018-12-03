#include <iostream>
#include <vector>

using namespace std;


void rotate(vector<int>& nums, int k);

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3,4,5,6,7,8,9,0};
    rotate(nums, 4);

    for (int n : nums) {
        cout << " " << n;
    }
    cout << endl;
    return 0;
}

void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    int swap_size = size;
    
    for (; k %= swap_size; swap_size -= k) {
        for (int i = 0; i < k; ++i) {
            int index = size - swap_size;
            swap( nums[size - swap_size + i], nums[size - k + i] );
        }
    
    }
}