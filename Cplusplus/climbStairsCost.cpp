/**
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

 * Once you pay the cost, you can either climb one or two steps.
 * You need to find minimum cost to reach the top of the floor,
 * and you can either start from the step with index 0, or the step with index 1.
 */

#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int> &cost);

int main()
{
    std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << minCostClimbingStairs(cost) << '\n';
    return 0;
}

int minCostClimbingStairs(std::vector<int> &cost)
{
    std::vector<int> dp(cost.size() + 1, 0);

    dp[1] = cost[0];

    for (int i = 1; i < cost.size(); i++)
    {
        dp[i + 1] = cost[i] + std::min(dp[i], dp[i - 1]);
    }

    return std::min(dp[cost.size()], dp[cost.size() - 1]);
}