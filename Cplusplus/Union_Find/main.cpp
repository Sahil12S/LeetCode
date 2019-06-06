#include "union_find.cpp"

int main()
{
    // Let's have 8 nodes
    // 1, 2, 3, 4, 5, 6, 7, 8
    VVI pairs = {{1, 2}, {1, 3}, {2, 3}, {4, 3}, {5, 6}, {6, 7}};
    UnionFind uf(8);
    for (auto pair : pairs)
    {
        uf.unify(pair[0], pair[1]);
    }

    std::cout << "======================" << '\n';
    std::cout << "Number of connected components: " << uf.numComponents() << '\n';
    std::cout << "Size of component that has element 1: " << uf.componentSize(1) << '\n';
    std::cout << "Size of component that has element 6: " << uf.componentSize(6) << '\n';
    std::cout << "Are 1 & 4 connected? " << uf.isConnected(1, 4) << '\n';
    std::cout << "Are 3 & 6 connected? " << uf.isConnected(3, 6) << '\n';
    std::cout << "Are 5 & 8 connected? " << uf.isConnected(5, 8) << '\n';

    return 0;
}