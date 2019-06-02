// https://en.wikipedia.org/wiki/Negative_base#Addition

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2);

int main(int argc, char const *argv[])
{
    // vector<int> arr1 = {1, 1, 1, 1, 1};
    // vector<int> arr2 = {1, 0, 1};
    vector<int> arr1 = {1};
    vector<int> arr2 = {1, 1};
    auto ans = addNegabinary(arr1, arr2);
    for (auto val : ans)
    {
        cout << val;
    }
    cout << endl;
    return 0;
}

vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
{
    map<int, vector<int>> bitmap;
    bitmap[-2] = {0, 1};
    bitmap[-1] = {1, 1};
    bitmap[0] = {0, 0};
    bitmap[1] = {1, 0};
    bitmap[2] = {0, -1};
    bitmap[3] = {1, -1};

    int carry = 0;
    int extra_carry = 0;
    int m = arr1.size() - 1;
    int n = arr2.size() - 1;

    vector<int> ans;
    int temp;

    while (m >= 0 || n >= 0 || carry != 0)
    {
        carry += m >= 0 ? arr1[m--] : 0;
        carry += n >= 0 ? arr2[n--] : 0;

        ans.emplace_back(bitmap[carry][0]);
        // cout << carry << endl;
        carry = bitmap[carry][1];
    }
    while (ans.size() > 1 && ans.back() == 0)
    {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}