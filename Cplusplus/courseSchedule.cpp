/**
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have prerequisites,
 * for example to take course 0 you have to first take course 1,
 * which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs,
 * is it possible for you to finish all courses?
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VB = std::vector<bool>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;

bool canFinish(int numCourses, VVI &prerequisites);

int main()
{
    int numCourses = 4;
    // VVI prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    VVI prerequisites = {{1, 0}, {0, 1}};
    std::cout << canFinish(numCourses, prerequisites) << '\n';

    return 0;
}

bool canFinish(int numCourses, VVI &prerequisites)
{
    VVI adjList(numCourses);
    VI in_degree(numCourses, 0);
    // VB visited(numCourses, false);

    for (auto val : prerequisites)
    {
        adjList[val[1]].emplace_back(val[0]);
        in_degree[val[0]]++;
    }

    std::queue<int> q;

    FORI(0, numCourses)
    {
        if (in_degree[i] == 0)
        {
            // visited[i] = true;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        numCourses--;

        for (auto v : adjList[vertex])
        {
            // if (!visited[v])
            // {
            in_degree[v]--;
            if (in_degree[v] == 0)
            {
                q.push(v);
                // visited[v] = true;
            }
            // }
        }
    }

    return numCourses == 0;
}