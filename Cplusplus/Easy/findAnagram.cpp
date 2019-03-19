// Given a string s and a non-empty string p,
// find all the start indices of p's anagrams in s.
// Strings consists of lowercase English letters only and
// the length of both strings s and p will not be larger than 20,100.

#include <iostream>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p);

int main(int argc, char const *argv[])
{
    // string s = "ebacbabacd";
    // string p = "abc";
    string s = "abab";
    string p = "ab";
    vector<int> ans = findAnagrams(s, p);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

vector<int> findAnagrams(string s, string p)
{
    if (s.length() < p.length())
    {
        return {};
    }
    vector<int> sVec(26, 0);
    vector<int> pVec(26, 0);
    vector<int> ans;

    for (int i = 0; i < p.length(); i++)
    {
        sVec[s[i] - 'a']++;
        pVec[p[i] - 'a']++;
    }

    if (sVec == pVec)
    {
        ans.emplace_back(0);
    }

    // Slide window
    for (int i = p.length(); i < s.length(); i++)
    {
        sVec[s[i] - 'a']++;
        sVec[s[i - p.length()] - 'a']--;

        if (sVec == pVec)
        {
            ans.emplace_back(i - p.size() + 1);
        }
    }
    return ans;
}