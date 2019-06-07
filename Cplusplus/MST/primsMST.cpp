/**
 * Implementation of Kruskal's Minimum Spanning Tree
 */

#include <algorithm>
#include <queue>
#include <vector>
#include <limits>

#include "../Graph/GraphW.cpp"
#include "../Union_Find/union_find.cpp"

using VVI = std::vector<std::vector<int>>;
using Pair = std::pair<int, int>;

struct Edge
{
    int src;
    int dest;
    int weight;
};

class Compare
{
public:
    bool operator()(Pair p1, Pair p2)
    {
        return p1.first > p2.first;
    }
};

std::vector<Edge> primsMST(GraphW *g, int num_nodes);

int main(int argc, char const *argv[])
{
    GraphW *g = new GraphW(9);
    VVI edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 8, 2}, {2, 5, 4}, {2, 3, 7}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}, {5, 6, 2}, {6, 8, 6}, {6, 7, 1}, {7, 8, 7}};

    g->createUndirected(edges);

    std::vector<Edge> ans = primsMST(g, 9);

    int min_weight = 0;

    std::cout << "-------------------------------------------------\n";
    std::cout << "Minimum Spanning Tree\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "\tSource"
              << "\t|Destination"
              << "\t|\tweight" << '\n';
    std::cout << "-------------------------------------------------\n";
    for (auto edge : ans)
    {
        min_weight += edge.weight;
        std::cout << "\t" << edge.src << "\t|\t" << edge.dest << "\t|\t" << edge.weight << '\n';
    }

    std::cout << "Minimum Weight of tree: " << min_weight << '\n';

    return 0;
}

std::vector<Edge> primsMST(GraphW *g, int num_nodes)
{
    // Priority queue to store edges starting from current nodes
    // or set of connected nodes
    std::priority_queue<Pair, std::vector<Pair>, Compare> pq;

    // We take a vector of keys and set it to infinity
    // It could also be the weight to travel to that node
    std::vector<int> key(num_nodes, std::numeric_limits<int>::max());

    // We store parent for each node
    std::vector<Edge> parent(num_nodes);

    // Keep track of visited nodes
    std::vector<bool> visited(num_nodes, false);

    // Starting with 0th node
    int src = 0;

    // Let's fetch our graph (adjacency list)
    VVP graph = g->getGraph();

    std::cout << "graph\n";
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            std::cout << "\t" << i << "\t|\t" << graph[i][j].first << "\t|\t" << graph[i][j].second << '\n';
        }
    }

    key[src] = 0;
    pq.push({key[src], src});

    while (!pq.empty())
    {
        // Get the vertex with lowest weight
        int v = pq.top().second;
        pq.pop();

        // Visit it
        visited[v] = true;

        // Find all of its adjacent nodes
        for (auto node : graph[v])
        {
            // Get vertex and it's weight
            int vert = node.first;
            int wt = node.second;

            std::cout << "Adj node of " << v << " is " << vert << " with wt " << wt << '\n';

            // See if vert have not been visited and if not
            // check if weight is less or not
            if (!visited[vert] && key[vert] > wt)
            {
                // Store list of all edges
                std::cout << "Inserting " << v << " " << vert << " " << wt << '\n';
                key[vert] = wt;
                pq.push({key[vert], vert});

                // Mark parent of current node
                // parent[vert] = {v, vert, wt};
                parent[vert - 1] = {v, vert, wt}; // to get rid or reverse function
            }
        }
    }

    // To remove the first empty element
    // std::reverse(std::begin(parent), std::end(parent));
    // parent.pop_back();
    // std::reverse(std::begin(parent), std::end(parent));

    return parent;
}