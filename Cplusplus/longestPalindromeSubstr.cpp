// Find longeset palindorme substring in given string

#include <iostream>
#include <algorithm>

using namespace std;

string longestPalindrome(string s);
int helper(string s, int left, int right);
bool checkPalindrome(string s);

int main(int argc, char const *argv[])
{
    // string s = "babad";
    // string s = "cbbd";
    string s = "c";

    cout << longestPalindrome(s) << endl;

    return 0;
}

// Taking index as center and expanding it.
string longestPalindrome(string s)
{
    int start = 0;
    int end = 0;
    
    for (int i = 0; i < s.length(); i++)
    {
        int len1 = helper(s, i, i);
        int len2 = helper(s, i, i + 1);

        int len = max(len1, len2);

        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    cout << start << ", " << end - start + 1 << endl;
    return s.substr(start, (end - start + 1));
}

int helper(string s, int left, int right)
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}