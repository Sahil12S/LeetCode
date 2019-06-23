#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

#define INF std::numeric_limits<int>::max()

using VI = std::vector<int>;
using VVI = std::vector<VI>;

bool carPooling(std::vector<std::vector<int>> &trips, int capacity);

int main()
{
    VVI trips = {{2, 1, 5}, {3, 5, 7}};
    int capacity = 3;
    // VVI trips = {{3, 2, 7}, {3, 7, 9}, {8, 3, 9}};
    // int capacity = 11;
    // VVI trips = {{7, 5, 6}, {6, 7, 8}, {10, 1, 6}};
    // int capacity = 16;
    // VVI trips = {{5, 4, 7}, {7, 4, 8}, {4, 1, 8}};
    // int capacity = 17;

    std::cout << carPooling(trips, capacity) << '\n';
    return 0;
}

class Compare
{
public:
    bool operator()(std::pair<int, int> p1, std::pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

bool carPooling(std::vector<std::vector<int>> &trips, int capacity)
{
    if (trips.empty())
    {
        return true;
    }

    std::sort(trips.begin(), trips.end(), [](VI t1, VI t2) {
        return t1[1] < t2[1];
    });
    // std::cout << trips[0][1] << " " << trips[1][1] << '\n';

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare>
        stops;

    // int num_passengers = 0;
    stops.push({trips[0][0], trips[0][2]});
    capacity -= trips[0][0];
    int idx = 1;

    while (!stops.empty() && capacity >= 0 && idx < trips.size())
    {
        // drop passengers
        while (!stops.empty() && trips[idx][1] >= stops.top().second)
        {
            capacity += stops.top().first;
            stops.pop();
        }

        // pick passengers
        stops.push({trips[idx][0], trips[idx][2]});
        capacity -= trips[idx][0];
        idx++;
    }
    if (capacity < 0)
    {
        return false;
    }
    return true;
}