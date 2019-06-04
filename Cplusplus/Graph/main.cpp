#include "Graph.cpp"
#include "GraphW.cpp"

int main(int argc, char const *argv[])
{
    Graph *g = new Graph(6);
    g->createUndirected({{0, 1}, {1, 2}, {2, 0}, {3, 2}, {4, 5}});
    std::cout << "============" << '\n';
    std::cout << "Unweighted Undirected Graph" << '\n';
    std::cout << "============" << '\n';
    g->printGraph(false);
    g->createDirected({{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}});
    std::cout << "============" << '\n';
    std::cout << "Unweighted Directed Graph" << '\n';
    std::cout << "============" << '\n';
    g->printGraph(true);

    GraphW *gw = new GraphW(6);
    gw->createUndirected({{0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {3, 2, 10}, {5, 4, 3}});
    std::cout << "============" << '\n';
    std::cout << "Weighted Undirected Graph" << '\n';
    std::cout << "============" << '\n';
    gw->printGraph(false);
    gw->createDirected({{0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {4, 5, 1}, {5, 4, 3}});
    std::cout << "============" << '\n';
    std::cout << "Weighted Undirected Graph" << '\n';
    std::cout << "============" << '\n';
    gw->printGraph(true);
    return 0;
}
