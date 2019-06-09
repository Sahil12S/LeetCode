/*
Given a string s, find the longest palindromic subsequence's length in s.
You may assume that the maximum length of s is 1000.
*/

#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s);
int helper(string s, int i, int j);

int longestPalindromeSubseq2(string s);

int main(int argc, char const *argv[])
{
    // string s = "bbbab";
    string s = "BBABCBCAB";

    cout << longestPalindromeSubseq2(s) << endl;
    return 0;
}

int longestPalindromeSubseq(string s)
{
    return helper(s, 0, s.length() - 1);
}

int helper(string s, int i, int j)
{
    // Single element
    if (i == j)
    {
        return 1;
    }

    if (s[i] != s[j])
    {
        return max(helper(s, i + 1, j), helper(s, i, j - 1));
    }
    else if (i + 1 == j)
    {
        return 2;
    }
    else
    {
        return helper(s, i + 1, j - 1) + 2;
    }
}

int longestPalindromeSubseq2(string s)
{
    vector<int> temp(s.length(), 0);
    vector<vector<int>> dp(s.length(), temp);

    for (int i = s.length() - 1; i >= 0; i--)
    {
        dp[i][i] = 1;

        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.length() - 1];
}