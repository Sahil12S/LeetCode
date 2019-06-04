// Implementation of graph using STL

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)

using VVI = std::vector<std::vector<int>>;
using VP = std::vector<std::pair<int, int>>;

class Graph
{
private:
    VVI adjListUD;
    VVI adjListD;
    int num_nodes;

public:
    // Number of nodes in graph
    Graph(int N)
    {
        num_nodes = N;
        adjListUD.resize(N);
        adjListD.resize(N);
    }

    // Create undirected graph
    void createUndirected(const VP &edges)
    {
        for (auto &edge : edges)
        {
            adjListUD[edge.first].push_back(edge.second);
            adjListUD[edge.second].push_back(edge.first);
        }
    }

    // Create Directed
    void createDirected(const VP &edges)
    {
        for (auto &edge : edges)
        {
            adjListD[edge.first].push_back(edge.second);
        }
    }

    void printGraph(bool isDirected)
    {
        auto list = isDirected ? adjListD : adjListUD;
        FORI(0, num_nodes)
        {
            std::cout << i << " --> ";
            for (auto node : list[i])
            {
                std::cout << node << " ";
            }
            std::cout << '\n';
        }
    }
};