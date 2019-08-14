/**
 * Given a string, find the length of the longest substring T
 * that contains at most k distinct characters.
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

int lengthOfLongestSubstringKDistinct(std::string s, int k);

int main()
{
    // std::string s = "abcdccde";
    std::string s = "ecebaba";
    int k = 2;
    // std::string s = "aa";
    // int k = 1;
    std::cout << lengthOfLongestSubstringKDistinct(s, k) << '\n';
    return 0;
}

int lengthOfLongestSubstringKDistinct(std::string s, int k)
{
    if (s.size() == 0 || k == 0 || k > s.size())
    {
        return 0;
    }
    std::unordered_set<char> charSet;
    std::unordered_map<char, std::list<int>> m;
    int startIdx = 0;
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++)
    {
        charSet.insert(s[i]);
        m[s[i]].push_back(i);

        while (charSet.size() > k)
        {
            maxLen = std::max(maxLen, i - startIdx);
            char c = s[startIdx++];
            m[c].pop_front();
            if (m[c].empty())
            {
                m.erase(c);
                charSet.erase(c);
            }
        }
    }
    return std::max(maxLen, static_cast<int>(s.size() - startIdx));
}