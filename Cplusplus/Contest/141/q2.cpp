#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_map>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

#define INF std::numeric_limits<int>::max()

using VI = std::vector<int>;
using VVI = std::vector<VI>;

class Compare
{
public:
    bool operator()(std::pair<int, int> p1, std::pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

int largestValsFromLabels(VI &values, VI &labels, int num_wanted, int use_limit);
int main()
{

    VI values = {5, 4, 3, 2, 1};
    VI labels = {1, 1, 2, 2, 3};
    int num_wanted = 3;
    int use_limit = 1;
    std::cout << largestValsFromLabels(values, labels, num_wanted, use_limit) << '\n';
    return 0;
}

int largestValsFromLabels(VI &values, VI &labels, int num_wanted, int use_limit)
{
    if (num_wanted == 0 || use_limit == 0)
    {
        return 0;
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;

    // std::unordered_map<int, std::priority_queue<int, VI, std::greater<int>>> um;

    FORI(0, values.size())
    {
        // std::cout << values[i] << " " << labels[i] << '\n';
        pq.push({values[i], labels[i]});
        // std::cout << pq.top().first << '\n';
    }

    std::unordered_map<int, int> um;

    int sum = 0;

    while (!pq.empty())
    {
        if (um.count(pq.top().second) < use_limit && num_wanted > 0)
        {
            um[pq.top().second]++;
            std::cout << pq.top().first << " " << pq.top().second << '\n';
            num_wanted--;
            sum += pq.top().first;
        }
        pq.pop();
    }
    return sum;
}