#include "Graph.cpp"
#include "Graph2.cpp"
#include "GraphW.cpp"
#include "Graph2W.cpp"

int main(int argc, char const *argv[])
{
    std::cout << "Adjacency List implementation" << '\n';
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
    std::cout << "Weighted Directed Graph" << '\n';
    std::cout << "============" << '\n';
    gw->printGraph(true);

    std::cout << '\n'
              << "Adjacency Matrix implementation" << '\n';

    Graph2 *g2 = new Graph2(6);
    g2->createUndirected({{0, 1}, {1, 2}, {2, 0}, {3, 2}, {4, 5}});
    std::cout << "============" << '\n';
    std::cout << "Unweighted Undirected Graph" << '\n';
    std::cout << "============" << '\n';
    g2->printGraph(false);
    g2->createDirected({{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}});
    std::cout << "============" << '\n';
    std::cout << "Unweighted Directed Graph" << '\n';
    std::cout << "============" << '\n';
    g2->printGraph(true);

    Graph2W *g2w = new Graph2W(6);
    g2w->createUndirected({{0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {3, 2, 10}, {5, 4, 3}});
    std::cout << "============" << '\n';
    std::cout << "Weighted Undirected Graph" << '\n';
    std::cout << "============" << '\n';
    g2w->printGraph(false);
    g2w->createDirected({{0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {4, 5, 1}, {5, 4, 3}});
    std::cout << "============" << '\n';
    std::cout << "Weighted Directed Graph" << '\n';
    std::cout << "============" << '\n';
    g2w->printGraph(true);

    return 0;
}
