#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;

int numTrees(int n);

int main()
{
    int n = 3;
    std::cout << numTrees(n) << '\n';
    return 0;
}

int numTrees(int n)
{
    VI dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    // Loop for the level
    FORI(2, n + 1)
    {
        // Now count left and right subtree count for that level
        FORJ(1, i + 1)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}