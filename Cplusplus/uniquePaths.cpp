/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 */

#include <iostream>
#include <vector>
#include <limits>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

#define INF std::numeric_limits<int>::max()

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int uniquePaths(int m, int n);
int uniquePaths2(int m, int n);

int main()
{
    int m = 7;
    int n = 3;
    std::cout << uniquePaths(m, n) << '\n';

    return 0;
}

int uniquePaths(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    VVI dp(m, VI(n, 0));

    dp[0][0] = 0;

    FORI(0, m)
    {
        FORJ(0, n)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePaths2(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    VI dp(n, 1);
    FORI(1, m)
    {
        FORJ(1, n)
        {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[n - 1];
}