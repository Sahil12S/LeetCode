#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> &tickets);
void visit(std::string airport);

int main()
{
    std::vector<std::vector<std::string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};

    auto ans = findItinerary(tickets);
    for (auto a : ans)
    {
        std::cout << a << '\n';
    }
    return 0;
}
std::unordered_map<std::string, std::multiset<std::string>> places;
std::vector<std::string> route;

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> &tickets)
{
    for (auto ticket : tickets)
    {
        places[ticket[0]].insert(ticket[1]);
    }

    for (auto &it : places)
    {
        std::cout << it.first << " - ";
        for (auto it2 : it.second)
        {
            std::cout << it2 << " ";
        }
        std::cout << '\n';
    }

    visit("JFK");

    std::reverse(route.begin(), route.end());

    return route;
}

void visit(std::string airport)
{
    while (!places[airport].empty())
    {
        std::string next_airport = *places[airport].begin();

        // We just want to remove first element and not all duplicate elements
        places[airport].erase(places[airport].begin());
        visit(next_airport);
    }
    route.push_back(airport);
}