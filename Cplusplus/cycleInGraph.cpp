// Using Disjoint sets check if unidrected graph is cyclic

#include <iostream>
using namespace std;


struct Edge
{
    int src, dest;
};

struct Graph
{
    int numV, numE;

    struct Edge* edge;
};

struct Graph* createGraph(int numV, int numE)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numV = numV;
    graph->numE = numE;

    graph->edge = (struct Edge*) malloc(graph->numE * sizeof(struct Edge));

    return graph;
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return find(parent, parent[i]);
}

void doUnion(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);

    if (xset != yset)
    {
        parent[xset] = yset;
    }
}

int isCycle(struct Graph* graph)
{
    int* parent = (int*) malloc(graph->numV * sizeof(int));

    for (int i = 0; i < graph->numV; ++i)
    {
        parent[i] = -1;
    }

    for (int i = 0; i < graph->numE; i++)
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if (x == y)
        {
            return 1;
        }

        doUnion(parent, x, y);
    }
    return 0;
}


int main()
{
    int numV = 3, numE = 3;
    struct Graph* graph = createGraph(numV, numE);
    
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    graph->edge[2].src = 2;
    graph->edge[2].dest = 0;

    if (isCycle(graph))
    {
        cout << "Graph has cycle" << endl;
    }
    else
    {
        cout << "Graph doesn't have cycle." << endl;
    }
    
    return 0;
}