// Implementation of Graph using Adjacency List

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    struct adjNode
    {
        int vertex;
        adjNode* next;

        adjNode(int vertex) : vertex(vertex), next(nullptr)
        {
        }
    };
    
    vector< adjNode*> graph;
    int numVertices;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        graph.resize(numVertices);

        for (int i = 0; i < numVertices; i++)
        {
            graph[i] = nullptr;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            delete graph[i];
        }
        delete &graph;
    }

    void addEdge(int source, int destination)
    {
        // Edge from source to destination
        adjNode* node = new adjNode(destination);
        node->next = graph[source];
        graph[source] = node;

        // Edge from destination to source
        node = new adjNode(source);
        node->next = graph[destination];
        graph[destination] = node;
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            adjNode* tempNode = graph[i];

            cout << i << ":\t";

            while (tempNode)
            {
                cout << tempNode->vertex << " -> ";
                tempNode = tempNode->next;
            }
            cout << "null\n";
        }
    }
};


int main(int argc, char const *argv[])
{
    Graph* g = new Graph(5);

    g->addEdge(0, 1);
    g->addEdge(0, 4);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(2, 3);
    g->addEdge(3, 4);
  
    g->printGraph();


    return 0;
}
