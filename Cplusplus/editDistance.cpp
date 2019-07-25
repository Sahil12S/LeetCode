/**
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int minDistance(std::string word1, std::string word2);

int main()
{
    std::string word1 = "horse";
    std::string word2 = "ros";
    std::cout << minDistance(word1, word2) << '\n';
    return 0;
}

int minDistance(std::string word1, std::string word2)
{
    int m = word1.size();
    int n = word2.size();

    /**
    VVI dp(m + 1, VI(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // If current character is same, then move ahead
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // Check minimum of 3 operations and add current operation
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    return dp[m][n];
*/

    /**
    VI prev(n + 1, 0);
    VI curr(n + 1, 0);

    for (int j = 1; j <= n; j++)
    {
        prev[j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = std::min(prev[j - 1], std::min(curr[j - 1], prev[j])) + 1;
            }
        }
        prev = curr;
    }
    return prev[n];
*/

    VI curr(n + 1, 0);

    for (int j = 1; j <= n; j++)
    {
        curr[j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        int prev = curr[0];
        curr[0] = i;
        for (int j = 1; j <= n; j++)
        {
            int temp = curr[j];
            if (word1[i - 1] == word2[j - 1])
            {
                curr[j] = prev;
            }
            else
            {
                curr[j] = std::min(prev, std::min(curr[j - 1], curr[j])) + 1;
            }
            prev = temp;
        }
    }
    return curr[n];
}