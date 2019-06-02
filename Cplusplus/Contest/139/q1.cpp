#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

string gcdOfStrings(string str1, string str2);

int main(int argc, char const *argv[])
{
    string str1 = "L";
    string str2 = "LODE";
    // string str1 = "LEET";
    // string str2 = "CODE";
    // string str1 = "ABABAB";
    // string str2 = "ABAB";
    // string str1 = "ABCABC";
    // string str2 = "ABC";
    cout << gcdOfStrings(str1, str2) << endl;
    return 0;
}

string gcdOfStrings(string str1, string str2)
{
    string ans = str1.size() < str2.size() ? str1 : str2;

    while (ans.size())
    {
        int mult1 = ceil(str1.size() / static_cast<float>(ans.size()));
        cout << mult1 << '\n';
        string temp1 = "";
        while (mult1-- > 0)
        {
            temp1 += ans;
        }
        cout << temp1 << '\n';

        int mult2 = ceil(str2.size() / static_cast<float>(ans.size()));
        cout << mult2 << '\n';
        string temp2 = "";
        while (mult2-- > 0)
        {
            temp2 += ans;
        }
        if (temp1 == str1 && temp2 == str2)
        {
            return ans;
        }
        ans = ans.substr(0, ans.size() - 1);
    }

    return "";
}