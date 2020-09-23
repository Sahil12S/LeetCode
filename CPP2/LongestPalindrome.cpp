#include <iostream>
#include <vector>

using namespace std;

int longestPalindrome(string s);

int main()
{
    string s = "baaadb";
    cout << longestPalindrome(s);
    return 0;
}

int longestPalindrome(string s)
{
    vector<int> letters(256, 0);

    for (char c : s)
    {
        letters[c]++;
    }

    int palindrome_len = 0;
    bool has_odd = false;

    for (int i : letters)
    {
        if (i % 2 != 0)
        {
            palindrome_len += i - 1;
            has_odd = true;
        }
        else
        {
            palindrome_len += i;
        }
    }
    
    if (has_odd)
    {
        palindrome_len++;
    }
    
    return palindrome_len;
}