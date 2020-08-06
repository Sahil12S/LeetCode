#include <iostream>
#include <vector>

using namespace std;

bool canConstruct(string ransomNote, string magazine);

int main()
{
    string ransomNote = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string magazine = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << canConstruct(ransomNote, magazine) << endl;
    return 0;
}

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> charCount(26, 0);
    for (char c : magazine)
    {
        charCount[c - 'a']++;
    }

    cout << charCount[0] << endl;
    for (char c : ransomNote)
    {
        if (charCount[c - 'a'] > 0)
        {
            charCount[c - 'a']--;
        }
        else
        {
            return false;
        }
    }
    return true;
}