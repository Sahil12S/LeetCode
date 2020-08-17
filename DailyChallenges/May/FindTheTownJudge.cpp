#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int findJudge(int N, vector<vector<int>>& trust);

int main()
{
    vector<vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    int N = 4;
    cout << findJudge(N, trust) << endl;
    return 0;
}

int findJudge(int N, vector<vector<int>>& trust)
{
    if (N == 1)
    {
        return 1;
    }
    map<int, int> trustedPeople;
    set<int> trustingPeople;

    for (int i = 0; i < trust.size(); i++)
    {
        if (trustedPeople.count(trust[i][1]) == 0)
        {
            trustedPeople[trust[i][1]] = 1;
        }
        else
        {
            trustedPeople[trust[i][1]]++;
        }
        trustingPeople.insert(trust[i][0]);
    }

    for (int i = 1; i <= N; i++)
    {
        if (trustingPeople.count(i) == 0 && trustedPeople.count(i) != 0 && trustedPeople[i] == N - 1)
        {
            return i;
        }
    }

    return -1;
}