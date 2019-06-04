/**
 * Given an undirected graph, return true if and only if it is bipartite.
 * 
 * Recall that a graph is bipartite if we can split it's set of nodes into
 * two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
 * 
 * The graph is given in the following form: graph[i] is a list of indexes j
 * for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.
 * There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.
*/

#include <iostream>
#include <vector>
#include <queue>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)
#define PRINT(s) std::cout << s
#define PRINTS(s) std::cout << s << ' '
#define PRINTLN(s) std::cout << s << '\n'

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using qi = std::queue<int>;

bool isBipartite(vvi &graph);

int main(int argc, char const *argv[])
{
    vvi graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    if (isBipartite(graph))
        PRINTLN("Bipartite");
    else
        PRINTLN("Not bipartite");
    return 0;
}

bool isBipartite(vvi &graph)
{
    vi visited(graph.size(), 0);

    FORI(0, graph.size())
    {
        if (graph[i].size() != 0 && visited[i] == 0)
        {
            visited[i] = 1;
            qi q;
            q.push(i);
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                for (auto node : graph[curr])
                {
                    std::cout << "Current: " << curr << " "
                              << "Node: " << node << "\n";

                    if (visited[node] == 0)
                    {
                        visited[node] = (visited[curr] == 1) ? 2 : 1;
                        q.push(node);
                    }
                    else if (visited[curr] == visited[node])
                    {
                        // std::cout << "Checking: " << curr << " " << node << '\n';
                        return false;
                    }
                }
            }
        }
    }
    return true;
}