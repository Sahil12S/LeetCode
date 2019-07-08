/**
 * There are 2N people a company is planning to interview.
 * The cost of flying the i-th person to city A is costs[i][0],
 * and the cost of flying the i-th person to city B is costs[i][1].
 * Return the minimum cost to fly every person to a city 
 * such that exactly N people arrive in each city.
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j > n; j--)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int twoCitySchedCost(VVI &costs);

int main()
{
    VVI costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    std::cout << twoCitySchedCost(costs) << '\n';
    return 0;
}

int twoCitySchedCost(VVI &costs)
{
    // Sort by maximum savings
    std::sort(costs.begin(), costs.end(), [](VI &p1, VI &p2) {
        return p1[0] - p1[1] < p2[0] - p2[1];
    });
    int min_cost = 0;
    FORI(0, costs.size() / 2)
    {
        min_cost += costs[i][0];
    }
    FORI(costs.size() / 2, costs.size())
    {
        min_cost += costs[i][1];
    }
    return min_cost;
}