// Implementation of graphs using Adjacency Matrix

#include <iostream>

using namespace std;

class Graph
{
private:
    bool** adjMatrix;
    int numVertices;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix = new bool*[numVertices];

        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
            {
                adjMatrix[i][j] = false;
            }
        }
    }

    ~Graph()
    {
        for (int i = 0; i < this->numVertices; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int fromVetex, int toVertex)
    {
        adjMatrix[fromVetex][toVertex] = true;

        // Don't use following for directed graph
        adjMatrix[toVertex][fromVetex] = true;
    }

    void removeEdge(int fromVertex, int toVertex)
    {
        adjMatrix[fromVertex][toVertex] = false;
        adjMatrix[toVertex][fromVertex] = false;
    }

    bool isEdge(int fromVertex, int toVertex)
    {
        return adjMatrix[fromVertex][toVertex];
    }

    void printGraph()
    {
        for (int i = 0; i < this->numVertices; i++)
        {
            cout << "[ ";
            for (int j = 0; j < this->numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "]" << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    g.printGraph();

    return 0;
}
