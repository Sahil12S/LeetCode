#include <iostream>
#include <vector>

int minCost(std::vector<std::vector<int>> &costs);

int main()
{
    std::vector<std::vector<int>> costs = {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
    std::cout << minCost(costs) << '\n';
    return 0;
}

int minCost(std::vector<std::vector<int>> &costs)
{
    if (costs.empty())
    {
        return 0;
    }

    for (int i = 1; i < costs.size(); i++)
    {
        costs[i][0] += std::min(costs[i - 1][1], costs[i - 1][2]);
        costs[i][1] += std::min(costs[i - 1][0], costs[i - 1][2]);
        costs[i][2] += std::min(costs[i - 1][0], costs[i - 1][1]);
    }

    return std::min(std::min(costs[costs.size() - 1][0], costs[costs.size() - 1][1]), costs[costs.size() - 1][2]);
}