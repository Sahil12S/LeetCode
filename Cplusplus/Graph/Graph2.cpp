// Implementation of graph using STL
// Matrix representation

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;
using VP = std::vector<std::pair<int, int>>;

class Graph2
{
private:
    VVI adjMatrixUD;
    VVI adjMatrixD;
    int num_nodes;

public:
    // Number of nodes in graph
    Graph2(int N)
    {
        num_nodes = N;
        adjMatrixUD.resize(N);
        adjMatrixD.resize(N);
        FORI(0, N)
        {
            adjMatrixUD[i] = VI(N, 0);
            adjMatrixD[i] = VI(N, 0);
        }
    }

    // Create undirected graph
    void createUndirected(const VP &edges)
    {
        for (auto &edge : edges)
        {
            adjMatrixUD[edge.first][edge.second] = 1;
            adjMatrixUD[edge.second][edge.first] = 1;
        }
    }

    // Create Directed
    void createDirected(const VP &edges)
    {
        for (auto &edge : edges)
        {
            adjMatrixD[edge.first][edge.second] = 1;
        }
    }

    void printGraph(bool isDirected)
    {
        VVI matrix = isDirected ? adjMatrixD : adjMatrixUD;
        FORI(0, num_nodes)
        {
            std::cout << i << " --> ";
            FORJ(0, num_nodes)
            {
                if (matrix[i][j] && i != j)
                    std::cout << j << " ";
            }
            std::cout << '\n';
        }
    }
};