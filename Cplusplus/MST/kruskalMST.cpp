/**
 * Implementation of Kruskal's Minimum Spanning Tree
 */

#include <algorithm>
#include <queue>
#include <vector>

#include "../Graph/GraphW.cpp"
#include "../Union_Find/union_find.cpp"

using VVI = std::vector<std::vector<int>>;

struct Edge
{
    int src;
    int dest;
    int weight;
};

class Compare
{
public:
    bool operator()(Edge e1, Edge e2)
    {
        return e1.weight > e2.weight;
    }
};

std::vector<Edge> kruskalMST(GraphW *g, int num_nodes);

int main(int argc, char const *argv[])
{
    GraphW *g = new GraphW(9);
    VVI edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 8, 2}, {2, 5, 4}, {2, 3, 7}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}, {5, 6, 2}, {6, 8, 6}, {6, 7, 1}, {7, 8, 7}};

    g->createUndirected(edges);

    std::vector<Edge> ans = kruskalMST(g, 9);

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

std::vector<Edge> kruskalMST(GraphW *g, int num_nodes)
{
    auto graph = g->getGraph();

    std::priority_queue<Edge, std::vector<Edge>, Compare> pq;
    std::vector<int> visited(num_nodes, false);

    for (int i = 0; i < num_nodes; i++)
    {
        visited[i] = true;
        for (auto node : graph[i])
        {
            if (!visited[node.first])
            {
                Edge e = {i, node.first, node.second};
                pq.push(e);
            }
        }
    }
    auto temp = pq;
    std::cout << "Priority Queue\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "\tSource"
              << "\t|Destination"
              << "\t|\tweight" << '\n';
    std::cout << "-------------------------------------------------\n";

    while (!temp.empty())
    {
        Edge e = temp.top();
        temp.pop();
        std::cout << "\t" << e.src << "\t|\t" << e.dest << "\t|\t" << e.weight << '\n';
    }
    std::cout << "-------------------------------------------------\n";

    UnionFind *uf = new UnionFind(num_nodes);
    // int num_comp = uf->numComponents();
    // std::cout << num_comp << std::endl;

    std::vector<Edge> result;

    // When we have one component only then we get our MST
    while (uf->numComponents() != 1)
    {
        Edge e = pq.top();
        pq.pop();
        // std::cout << "on edge: " << e.src << '\n';
        if (!uf->isConnected(e.src, e.dest))
        {
            result.emplace_back(e);
            uf->unify(e.src, e.dest);
            // num_comp--;
        }
    }

    return result;
}