/**
 * We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 
 * Now we have some workers. worker[i] is the ability of the ith worker,
 * which means that this worker can only complete a job with difficulty at most worker[i]. 
 * Every worker can be assigned at most one job, but one job can be completed multiple times.
 * For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.
 * If a worker cannot complete any job, his profit is $0.
 * What is the most profit we can make?
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int maxProfitAssignment(VI &difficulty, VI &profit, VI &worker);

int main()
{
    VI difficulty = {2, 4, 6, 8, 10};
    VI profit = {10, 20, 30, 40, 50};
    VI worker = {4, 5, 6, 7};

    std::cout << maxProfitAssignment(difficulty, profit, worker) << '\n';
    return 0;
}

int maxProfitAssignment(VI &difficulty, VI &profit, VI &worker)
{
    std::vector<std::pair<int, int>> vec(difficulty.size());
    FORI(0, difficulty.size())
    {
        vec[i] = {difficulty[i], profit[i]};
    }
    std::sort(vec.begin(), vec.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
        return p1.first < p2.first;
    });

    std::sort(worker.begin(), worker.end());

    int max_profit = 0;
    int idx = 0;
    int curr_max = 0;

    FORI(0, worker.size())
    {
        while (idx < vec.size() && worker[i] >= vec[i].first)
        {
            curr_max = std::max(curr_max, vec[i++].second);
        }
        max_profit += curr_max;
    }

    return max_profit;
}