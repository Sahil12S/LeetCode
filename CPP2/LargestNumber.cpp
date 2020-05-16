#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string largestNumber(vector<int>& nums);
bool Compare(string str1, string str2);

int main()
{
    // vector<int> nums = {3, 30, 34, 5, 9};
    vector<int> nums = {0, 0};
    cout << largestNumber(nums) << endl;

    return 0;
}

bool Compare(string str1, string str2)
{
    return (str1 + str2) > (str2 + str1);
}

string largestNumber(vector<int>& nums)
{
    vector<string> strNums(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        strNums[i] = to_string(nums[i]);
    }

    sort(strNums.begin(), strNums.end(), Compare);
    if (strNums.size() && strNums[0] == "0")
    {
        return "0";
    }
    string result = "";
    for (int i = 0; i < nums.size(); i++)
    {
        result += strNums[i];
    }
    return result;
}