#include <iostream>

using namespace std;

bool validPalindrome(string s);

int main()
{
    string s = "abc";
    cout << validPalindrome(s) << '\n';
    return 0;
}

bool checkPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++, j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++, j--;
        }
        else
        {
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
        }
        
    }
    return true;
}