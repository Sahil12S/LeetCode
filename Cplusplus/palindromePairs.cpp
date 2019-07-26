/**
 * Given a list of unique words,
 * find all pairs of distinct indices (i, j) in the given list,
 * so that the concatenation of the two words,
 * i.e. words[i] + words[j] is a palindrome.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using VS = std::vector<std::string>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;

VVI palindromePairs(VS &words);
bool isPalindrome(std::string word);

int main()
{
    VS words = {"abcd", "dcba", "lls", "s", "sssll", ""};
    auto ans = palindromePairs(words);
    for (auto pair : ans)
    {
        std::cout << pair[0] << " " << pair[1] << '\n';
    }
    return 0;
}

// Assuming our list doesn't have duplicate words
VVI palindromePairs(VS &words)
{
    std::unordered_map<std::string, int> dict;

    for (int i = 0; i < words.size(); i++)
    {
        std::string temp = words[i];
        std::reverse(temp.begin(), temp.end());
        dict[temp] = i;
    }

    VVI result;

    /**
     * Now that we have all the reversed string,
     * We can check if we are able to make palindrome by combining
     * any two strings.
     */

    /**
     * Case 1
     * There can be a case where one string is empty
     * and if we have some palindrominc string
     * then both of these can make a pair like ["", str], [str, ""]
     * 
     * We try to resolve this case first
     */

    if (dict.find("") != dict.end())
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (i != dict[""])
            {
                if (isPalindrome(words[i]))
                {
                    // We take the case ["", str] here and other case later
                    result.push_back({dict[""], i});
                }
            }
        }
    }

    /**
     * Now we travel given list of string
     * and try to split them in 2 parts L, R
     * if we find any of the part in dict
     * and other part is either empty or palindrome
     * then we can combine them like
     * L | R | str, where R is palindrome in itself & L == reverse(str)
     * str | L | R , where L is palindrome in itself & str == reverse(L)
     */

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            // Here we are not travelling so far right that
            // right becomes empty. But rather till the end of
            // the string, which leaves one character for "right"
            // That is why we require separate handling of the
            // case where right could be empty, which we covered above
            std::string left = words[i].substr(0, j);
            std::string right = words[i].substr(j);

            std::cout << words[i] << " - " << left << ", " << right << '\n';

            // Check if left is a match in dictionary and right is palindrome
            if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i)
            {
                result.push_back({i, dict[left]}); // here we cover [str, ""]
            }

            // Check if right is a match in dictionary and left is palindrome
            if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i)
            {
                result.push_back({dict[right], i}); // str | L | R
            }
        }
    }
    return result;
}

bool isPalindrome(std::string word)
{
    int i = 0;
    int j = word.size() - 1;

    while (i < j)
    {
        if (word[i++] != word[j--])
        {
            return false;
        }
    }
    return true;
}