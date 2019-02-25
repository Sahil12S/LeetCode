// Implement search for graphs made with Adjacency Matrix.

#include <iostream>
// #include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    // Storing in 2D array
    bool** adjMatrix;
    int numVertices;
    void DFSHelper(int vertex, bool* visited);
    // void BFSHelper(int vertex, bool* visited);

public:
    Graph(int numVertices);
    ~Graph();

    void addEdge(int src, int dest);

    void DFS(int vertex);
    void BFS(int vertex);
};

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;

    // Allocate size to our matrix
    adjMatrix = new bool*[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        adjMatrix[i] = new bool[numVertices];
    }

    // Initialize whole matrix with false
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            adjMatrix[i][j] = false;
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < numVertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::addEdge(int src, int dest)
{
    adjMatrix[src][dest] = true;
}


void Graph::DFS(int vertex)
{
    bool* visited = new bool[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }

    DFSHelper(vertex, visited);
}

void Graph::DFSHelper(int vertex, bool* visited)
{
    visited[vertex] = true;
    cout << "Visited: " << vertex << ".\n";

    for (int i = 0; i < numVertices; i++)
    {
        cout << "Looking at: " << i << " from: " << vertex << ".\n";
        if (!visited[i] && adjMatrix[vertex][i])
        {
            cout << "Visiting: " << i << " from: " << vertex << ".\n";
            DFSHelper(i, visited);
        }
    }
}

void Graph::BFS(int vertex)
{
    bool* visited = new bool[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }

    queue<int>* q = new queue<int>;

    q->push(vertex);
    visited[vertex] = true;
    cout << "Visited: " << vertex << ".\n";

    while (!q->empty())
    {
        int v = q->front();
        q->pop();

        for (int i = 0; i < numVertices; i++)
        {
            cout << "From node: " << v << " looking at: " << i << ".\n";
            if (!visited[i] && adjMatrix[v][i])
            {
                cout << "Visiting node: " << i << ".\n";
                q->push(i);
                visited[i] = true;
            }
        }

    }

}


int main(int argc, char const *argv[])
{
    Graph* g = new Graph(4);

    g->addEdge(0, 1); 
    g->addEdge(0, 2); 
    g->addEdge(1, 2); 
    g->addEdge(2, 0); 
    g->addEdge(2, 3); 
    g->addEdge(3, 3);

    cout << "DFS starting from vertex 2:" << endl;
    g->DFS(2);
    cout << "\n";
    cout << "===========\n";
    cout << "BFS starting from vertex 2:\n";
    g->BFS(2);
    cout << "\n";

    return 0;
}
