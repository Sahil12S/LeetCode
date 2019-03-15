// Given two strings s and t , write a function to determine if t is an anagram of s.

#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t);

int main(int argc, char const *argv[])
{
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s, t) << endl;
    return 0;
}

bool isAnagram(string s, string t)
{
    vector<int> letters(26, 0);
    if (s.length() != t.length())
    {
        return false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        letters[s[i] - 'a']++;
        letters[t[i] - 'a']--;
    }

    for (int i : letters)
    {
        if (i != 0)
        {
            return false;
        }
    }
    return true;

}