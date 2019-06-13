#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int mincostTickets(std::vector<int> &days, std::vector<int> &costs);
int dpHelper(int day, const std::unordered_set<int> &travel_days, std::vector<int> &cost_on_days, const std::vector<int> &costs);

int mincostTickets2(std::vector<int> &days, std::vector<int> &costs);
int dpHelper2(int day_idx, const std::vector<int> &days, std::vector<int> &cost_on_days, const std::vector<int> &costs, const std::vector<int> &durations);

int main()
{
    std::vector<int> days = {1, 4, 6, 7, 8, 20};
    std::vector<int> costs = {2, 7, 15};
    std::cout << mincostTickets2(days, costs) << '\n';
    return 0;
}

int mincostTickets(std::vector<int> &days, std::vector<int> &costs)
{
    if (days.size() == 0 || costs.size() == 0)
    {
        return -1;
    }
    // All days on which we are travelling
    std::unordered_set<int> travel_days(days.begin(), days.end());

    // All available days
    std::vector<int> cost_on_days(366, -1);

    return dpHelper(1, travel_days, cost_on_days, costs);
}

int dpHelper(int day, const std::unordered_set<int> &travel_days, std::vector<int> &cost_on_days, const std::vector<int> &costs)
{
    // Valid day
    if (day > 365)
    {
        return 0;
    }

    // If we already have cost for that day
    if (cost_on_days[day] != -1)
    {
        return cost_on_days[day];
    }

    int min_cost;

    // If we are travelling on this day
    if (travel_days.find(day) != travel_days.end())
    {
        min_cost = std::min(dpHelper(day + 1, travel_days, cost_on_days, costs) + costs[0],
                            dpHelper(day + 7, travel_days, cost_on_days, costs) + costs[1]);
        min_cost = std::min(min_cost, dpHelper(day + 30, travel_days, cost_on_days, costs) + costs[2]);
    }
    else
    {
        // Go to next day to check
        min_cost = dpHelper(day + 1, travel_days, cost_on_days, costs);
    }

    cost_on_days[day] = min_cost;
    std::cout << "for day: " << day << " min_cost: " << min_cost << '\n';
    return min_cost;
}

int mincostTickets2(std::vector<int> &days, std::vector<int> &costs)
{
    std::vector<int> cost_on_days(days.size(), -1);
    std::vector<int> durations = {1, 7, 30};

    return dpHelper2(0, days, cost_on_days, costs, durations);
}
int dpHelper2(int day_idx, const std::vector<int> &days, std::vector<int> &cost_on_days, const std::vector<int> &costs, const std::vector<int> &durations)
{
    if (day_idx >= days.size())
    {
        return 0;
    }

    if (cost_on_days[day_idx] != -1)
    {
        std::cout << "return - day: " << days[day_idx] << " cost_on_days: " << cost_on_days[day_idx] << '\n';
        return cost_on_days[day_idx];
    }

    std::cout << "Current day_idx and day " << day_idx << " " << days[day_idx] << '\n';

    int min_cost = std::numeric_limits<int>::max();
    int next_day_idx = day_idx;
    for (int k = 0; k < 3; k++)
    {
        // Find how many days can we travel with current duration
        // So we skip days that we can travel on a pass if bought on current day
        while (next_day_idx < days.size() && days[next_day_idx] < days[day_idx] + durations[k])
        {
            next_day_idx++;
        }
        std::cout << "next day: " << next_day_idx << '\n';
        min_cost = std::min(min_cost, dpHelper2(next_day_idx, days, cost_on_days, costs, durations) + costs[k]);
        std::cout << "day: " << days[day_idx] << " for cost: " << costs[k] << " min_cost: " << min_cost << '\n';
    }

    std::cout << "for day: " << days[day_idx] << " min_cost: " << min_cost << '\n';
    cost_on_days[day_idx] = min_cost;
    return min_cost;
}