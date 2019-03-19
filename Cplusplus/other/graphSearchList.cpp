// Implement searching in graphs made with Adjacency List

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
private:
    int numVertices;
    list<int>* adjList;

    void DFSHelper(int vertex, bool* visited);
    void BFSHelper(int vertex, bool* visited);

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
    adjList = new list<int>[numVertices];
}

Graph::~Graph()
{
    delete adjList;
}

void Graph::addEdge(int src, int dest)
{
    adjList[src].push_back(dest);
    // adjList[dest].push_back(src);
}

void Graph::DFS(int vertex)
{
    bool* visited = new bool[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    
    DFSHelper(vertex, visited);
    delete visited;
}

void Graph::DFSHelper(int vertex, bool* visited)
{
    visited[vertex] = true;

    cout << "Visited: " << vertex << ".\n";

    for (auto it = adjList[vertex].begin(); it != adjList[vertex].end(); it++)
    {
        cout << "From node: " << vertex << ", looking at: " << *it << ".\n";
        if (!visited[*it])
        {
            cout << "From node: " << vertex << ", Going towards: " << *it << ".\n";
            DFSHelper(*it, visited);
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

    BFSHelper(vertex, visited);
    delete visited;
}

void Graph::BFSHelper(int vertex, bool* visited)
{
    queue<int>* vertices = new queue<int>;
    vertices->push(vertex);
    visited[vertex] = true;

    while (!vertices->empty())
    {
        int v = vertices->front();
        vertices->pop();
        cout << "Visited: " << v << ".\n";

        for (auto it = adjList[v].begin(); it != adjList[v].end(); it++)
        {
            cout << "From node: " << v << " looking at: " << *it << ".\n";
            if (!visited[*it])
            {
                cout << "From node: " << v << " adding node: " << *it << " to queue.\n";
                vertices->push(*it);
                visited[*it] = true;
            }
        }
    }
    delete vertices;
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

    cout << "DFS starting from vertex 0:" << endl;
    g->DFS(0);
    cout << "\n";
    cout << "===============" << endl;
    cout << "BFS starting from vertex 0" << endl;
    g->BFS(0);
    cout << "\n";

    return 0;
}