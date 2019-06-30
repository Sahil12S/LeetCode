#include <iostream>
#include <vector>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)

using VS = std::vector<std::string>;

using VI = std::vector<int>;
using VVI = std::vector<VI>;

VS generatedAbbreviations(std::string word);
void backtrack(VS &res, std::string str, std::string word, int pos, int count);

int main()
{
    std::string word = "word";
    VS res = generatedAbbreviations(word);
    for (auto w : res)
    {
        std::cout << w << " ";
    }
    std::cout << '\n';
    return 0;
}

VS generatedAbbreviations(std::string word)
{
    VS res;
    backtrack(res, "", word, 0, 0);
    return res;
}

void backtrack(VS &res, std::string str, std::string word, int pos, int count)
{
    std::cout << str << '\n';
    if (pos == word.size())
    {
        if (count)
        {
            str += std::to_string(count);
        }
        res.push_back(str);
    }
    else
    {
        backtrack(res, str, word, pos + 1, count + 1);
        backtrack(res, str + (count ? std::to_string(count) : "") + word[pos], word, pos + 1, 0);
    }
}