// Given a string which consists of lowercase or uppercase letters,
// find the length of the longest palindromes that can be built with those letters.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestPalindrome(string s);

int main(int argc, char const *argv[])
{
    // string s = "abccccdd";
    string s = "";
    cout << longestPalindrome(s) << endl;
    return 0;
}

int longestPalindrome(string s)
{
    vector<int> chars(58, 0);

    for (char c : s)
    {
        chars[c - 'A']++;
    }

    int length = 0;
    int odd = false;

    for (int count : chars)
    {
        if (count / 2 != 0)
        {
            length += (count / 2) * 2;
            count %= 2;
        }
        if (count)
        {
            odd = true;
        }
        
    }

    return odd ? length + 1 : length;
}