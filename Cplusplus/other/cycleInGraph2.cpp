// Using Disjoint sets check if unidrected graph is cyclic
// Union by Rank and Path Comparison

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

struct Subset
{
    int parent, rank;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));

    graph->numV = V;
    graph->numE = E;
    graph->edge = (struct Edge*) malloc(graph->numE * sizeof(struct Edge));

    return graph;
}

int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void doUnion(struct Subset subsets[], int x, int y)
{
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);

    if (subsets[xRoot].rank < subsets[yRoot].rank)
    {
        subsets[xRoot].parent = yRoot;
    }
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
    {
        subsets[yRoot].parent = xRoot;
    }
    else
    {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
    
}

int isCycle(struct Graph* graph)
{
    int V = graph->numV;
    int E = graph->numE;
    
    struct Subset* subsets = (struct Subset*) malloc(V * sizeof(struct Subset));

    for (int i = 0; i < V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int x = find(subsets, graph->edge[i].src);
        int y = find(subsets, graph->edge[i].dest);

        if (x == y)
        {
            return 1;
        }

        doUnion(subsets, x, y);
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