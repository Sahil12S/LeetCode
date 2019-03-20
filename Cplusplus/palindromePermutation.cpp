// Given a string, determine if a permutation of the string could form a palindrome.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canPermutePalindrome(string s);

int main(int argc, char const *argv[])
{
    string s = "ab";
    cout << canPermutePalindrome(s) << endl;
    return 0;
}

bool canPermutePalindrome(string s)
{
    vector<int> chars(256);

    for (int i = 0; i < s.length(); i++)
    {
        chars[s[i]]++;
    }

    int countOdd = 0;

    for (int i : chars)
    {
        if (i % 2 == 1)
        {
            countOdd++;
        }
    }

    return countOdd < 2 ? true : false;
}