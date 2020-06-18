// https://leetcode.com/problems/two-city-scheduling/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs);

int main()
{
    vector<vector<int>> costs =  {{10,20},{30,200},{400,50},{30,20}};
    cout << twoCitySchedCost(costs) << endl;
    return 0;
}

bool compare(vector<int> a, vector<int> b)
{
    return (a[1] - a[0]) < (b[1] - b[0]);
}

int twoCitySchedCost(vector<vector<int>>& costs)
{
    sort(costs.begin(), costs.end(), compare);
    int city_a = 0;
    int city_b = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        if (i < costs.size() / 2)
        {
            city_b += costs[i][1];
        }
        else
        {
            city_a += costs[i][0];
        }
        
    }
    return city_a + city_b;
}