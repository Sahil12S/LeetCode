#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

#define FORI(s, e) for (int i = s; i < e; i++)
#define FORJ(s, e) for (int j = s; j < e; j++)

std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict);

int main()
{
    std::string s = "catsanddog";
    std::vector<std::string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    auto ans = wordBreak(s, wordDict);
    for (const auto &val : ans)
    {
        std::cout << val << '\n';
    }
    return 0;
}
std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());

    std::vector<std::vector<std::string>> dp(s.length() + 1, std::vector<std::string>());
    dp[0].emplace_back("");

    FORI(1, s.length() + 1)
    {
        // std::vector<std::string> temp;
        FORJ(0, i)
        {
            std::string substring = s.substr(j, i - j);
            std::cout << "Check: j-" << j << " & i-" << i << " : " << substring << '\n';
            if (dp[j].size() > 0 && words.count(substring) > 0)
            {
                std::cout << (dp[j].size() > 0) << '\n';
                for (std::string val : dp[j])
                {
                    dp[i].emplace_back(val + (val == "" ? "" : " ") + substring);
                }
            }
        }
        std::cout << '\n';
    }

    return dp[s.length()];
}