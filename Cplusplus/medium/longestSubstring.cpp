// Given a string, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int lengthOfSubstring(string s);

int main(int argc, char const *argv[])
{
    // string s = "abcabcbb";
    // string s = "bbbbb";
    // string s = "pwwkew";
    string s = "pwpke";

    cout << lengthOfSubstring(s) << endl;
    
    return 0;
}

int lengthOfSubstring(string s) {
    unordered_set<char> uniqueChars;

    int maxLength = 0;

    int i = 0, j = 0;

    while (i < s.length() && j < s.length()) {
        if (!uniqueChars.count(s[j])) {
            uniqueChars.insert(s[j]);
            j++;
            maxLength = max(maxLength, (int)uniqueChars.size());
        }
        else {
            uniqueChars.erase(s[i]);
            i++;
        }
    }
    return maxLength;
}