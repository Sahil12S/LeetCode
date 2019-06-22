/**
 * Given a sequence of words written in the alien language,
 * and the order of the alphabet,
 * return true if and only if the given words are sorted lexicographicaly in this alien language.
 */

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

bool isAlienSorted(std::vector<std::string> &words, std::string order);

int main()
{
    // std::vector<std::string> words = {"hello", "leetcode"};
    // std::string order = "hlabcdefgijkmnopqrstuvwxyz";
    // std::vector<std::string> words = {"word", "world", "row"};
    // std::string order = "worldabcefghijkmnpqstuvxyz";
    std::vector<std::string> words = {"apple", "app"};
    std::string order = "abcdefghijklmnopqrstuvwxyz";
    std::cout << isAlienSorted(words, order) << '\n';
    return 0;
}

bool isAlienSorted(std::vector<std::string> &words, std::string order)
{
    if (words.size() <= 1)
    {
        return true;
    }

    std::vector<int> letters(order.size());

    FORI(0, order.size())
    {
        letters[order[i] - 'a'] = i;
    }

    FORI(1, words.size())
    {
        // Let's compare now
        FORJ(0, std::min(words[i - 1].size(), words[i].size()))
        {
            if (words[i - 1][j] != words[i][j])
            {
                if (letters[words[i - 1][j] - 'a'] < letters[words[i][j] - 'a'])
                {
                    goto outer;
                }
                return false;
            }
        }
        if (words[i].size() < words[i - 1].size())
        {
            return false;
        }
    outer:;
    }

    return true;
}