// Given a string, your task is to count how many palindromic substrings in this string.

#include <iostream>
#include <string>

using namespace std;

int countSubstring(string s);

int main(int argc, char const *argv[])
{
    string s = "aaa";
    cout << countSubstring(s) << endl;
    return 0;
}

int countSubstring(string s)
{
    int n = s.length();
    int ans = 0;
    for (int i = 0; i <= 2*n - 1; i++)
    {
        int left = i / 2;
        int right = left + i % 2;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            ans++;
            left--;
            right++;
        }
    }
    return ans;
}