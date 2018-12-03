// Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

#include <iostream>
#include <vector>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x);

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5};
    int k = 4, x = 4;

    for (int val : findClosestElements(arr, k, x)) {
        cout << val << ", ";
    }
    cout << endl;

    return 0;
}


vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     
     if (x < arr[0]) {
         cout << "if" << endl;
         return {arr.begin(), arr.begin() + k};
     } else if (x > arr[arr.size() - 1]){
         cout << "else if" << endl;
         return {arr.end() - k, arr.end()};
     }

    //  find closes index for given target.
    int left = 0, right = arr.size() - 1;
    int t_index = -1;

    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > x) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (arr[right] == x) {
        t_index = right;
    } else {
        t_index = left;
    }
    cout << "t_index: " << t_index << endl;

    int el_left = t_index - 1;
    int el_right = t_index + 1;
    // --k;

    while (k > 1) {
        cout << "el_left: " << el_left << ", el_right: " << el_right << endl;
        cout << "k: " << k << endl;
        if (el_left < 0) {
            ++el_right;
            // cout << "1" << endl;
        } else if (el_right >= arr.size()) {
            --el_left;
            // cout << "2" << endl;
            // --k;
        } else if (abs(arr[el_left] - x) <= abs(arr[el_right] - x)) {
            // cout << "3" << endl;
            --el_left;
        } else {
            // cout << "4" << endl;
            ++el_right;
        }
        --k;
    }
    cout << "el_left: " << el_left << ", el_right: " << el_right << endl;

    // cout << "Check: " << *(arr.begin() + el_left) << endl;

     return {arr.begin() + el_left+1, arr.begin() + el_right};
}