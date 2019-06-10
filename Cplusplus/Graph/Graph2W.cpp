// Implementation of weighted graph using STL
// Adjacency matrix implementation

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;
using VP = std::vector<std::pair<int, int>>;
using VVP = std::vector<VP>;

class Graph2W
{
private:
    VVI adjMatrixUD;
    VVI adjMatrixD;
    int num_nodes;

public:
    Graph2W(int N)
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

    void createUndirected(const VVI &edges)
    {
        for (auto &edge : edges)
        {
            adjMatrixUD[edge[0]][edge[1]] = edge[2];
            adjMatrixUD[edge[1]][edge[0]] = edge[2];
        }
    }

    void createDirected(const VVI &edges)
    {
        for (auto &edge : edges)
        {
            adjMatrixD[edge[0]][edge[1]] = edge[2];
        }
    }

    void printGraph(bool isDirected)
    {
        auto list = isDirected ? adjMatrixD : adjMatrixUD;
        VVI matrix = isDirected ? adjMatrixD : adjMatrixUD;
        FORI(0, num_nodes)
        {
            std::cout << i << " --> ";
            FORJ(0, num_nodes)
            {
                if (matrix[i][j] && i != j)
                    std::cout << "(" << j << ", " << matrix[i][j] << ") ";
            }
            std::cout << '\n';
        }
    }

    VVI getGraph()
    {
        return adjMatrixUD;
    }
};