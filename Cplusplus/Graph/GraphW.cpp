// Implementation of weighted graph using STL

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)

using VVI = std::vector<std::vector<int>>;
using VVP = std::vector<std::vector<std::pair<int, int>>>;

class GraphW
{
private:
    VVP adjListUD;
    VVP adjListD;
    int num_nodes;

public:
    GraphW(int N)
    {
        num_nodes = N;
        adjListUD.resize(N);
        adjListD.resize(N);
    }

    void createUndirected(const VVI &edges)
    {
        for (auto &edge : edges)
        {
            adjListUD[edge[0]].emplace_back(std::make_pair(edge[1], edge[2]));
            adjListD[edge[1]].emplace_back(std::make_pair(edge[0], edge[2]));
        }
    }

    void createDirected(const VVI &edges)
    {
        for (auto &edge : edges)
        {
            adjListD[edge[0]].emplace_back(std::make_pair(edge[1], edge[2]));
        }
    }

    void printGraph(bool isDirected)
    {
        auto list = isDirected ? adjListD : adjListUD;
        FORI(0, num_nodes)
        {
            std::cout << i << " -> ";
            for (auto node : list[i])
            {
                std::cout << "(" << node.first << ", " << node.second << ")"
                          << " ";
            }
            std::cout << '\n';
        }
    }
};