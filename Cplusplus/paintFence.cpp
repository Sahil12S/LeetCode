/**
 * there is a fence with n posts, each post can be painted with one of the k colors.
 * You have to paint all the posts such that no more than 
 * two adjacent fence posts have the same color.
 * 
 * Return the total number of ways you can paint the fence.
 */

#include <iostream>
#include <vector>

int numWays(int n, int k);
int numWays2(int n, int k);

int main()
{
    int n = 3;
    int k = 2;
    std::cout << numWays(n, k) << '\n';
    std::cout << numWays2(n, k) << '\n';
    return 0;
}

int numWays(int n, int k)
{
    if (n == 0)
    {
        return 0;
    }
    std::vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i] = k;
        }
        else if (i == 1)
        {
            dp[i] = k * k;
        }
        else
        {
            dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
        }
    }
    return dp[n - 1];
}

int numWays2(int n, int k)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return k;
    }
    else if (n == 2)
    {
        return k * k;
    }

    int same = k;
    int diff = k * (k - 1);

    for (int i = 3; i <= n; i++)
    {
        int tSame = diff;
        diff = (same + diff) * (k - 1);
        same = tSame;
    }
    return same + diff;
}