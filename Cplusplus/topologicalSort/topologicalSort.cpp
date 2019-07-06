#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VB = std::vector<bool>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;

// Implementation using BFS
VI topologicalSort(int N, VVI &adjList);

// Implementation usign DFS
void dfs(int curr_vertex, VB &visited, VI &res, VVI &adjList);
VI topologicalSort2(int N, VVI &adjList);

int main()
{
    // VVI adjList = {{0, 1}, {0, 2}}
    VVI adjList = {{1, 2}, {2, 3}, {3, 4, 5}, {4, 5}, {5}, {}};

    auto res = topologicalSort2(6, adjList);

    for (auto n : res)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}

// Implementation using BFS
VI topologicalSort(int N, VVI &adjList)
{
    VI res;
    VI in_degree(N, 0);
    VB visited(N, false);

    FORI(0, N)
    {
        for (auto vert : adjList[i])
        {
            in_degree[vert]++;
        }
    }

    std::queue<int> q;

    FORI(0, N)
    {
        if (in_degree[i] == 0)
        {
            visited[i] = true;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        res.emplace_back(vertex);

        for (int j : adjList[vertex])
        {
            if (!visited[j])
            {
                in_degree[j]--;
                if (in_degree[j] == 0)
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return res;
}

VI topologicalSort2(int N, VVI &adjList)
{
    VI res;
    VB visited(N, false);

    dfs(0, visited, res, adjList);
    std::reverse(res.begin(), res.end());
    return res;
}

void dfs(int curr_vertex, VB &visited, VI &res, VVI &adjList)
{
    visited[curr_vertex] = true;

    for (auto vertex : adjList[curr_vertex])
    {
        if (!visited[vertex])
        {
            dfs(vertex, visited, res, adjList);
        }
    }
    res.emplace_back(curr_vertex);
}