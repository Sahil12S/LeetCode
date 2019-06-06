/**
 * Implementation of Union Find
 */

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

class UnionFind
{
private:
    // Size of our graph or total number of elements.
    int m_Size;

    // Number of components in our graph
    int m_NumComponents;

    // node[i] will point to parent of node i
    VI m_Nodes;

    // Tracks the size of each component
    VI m_CompSize;

public:
    /**
     * Constructor
     * 
     * @param size - total number of nodes
     */
    UnionFind(int size)
    {
        m_Size = size;
        m_NumComponents = size;

        m_Nodes.resize(size);
        m_CompSize.resize(size);

        FORI(0, size)
        {
            m_Nodes[i] = i;    // Create nodes with parents as themselves
            m_CompSize[i] = 1; // All components are separate, thus have size of 1
        }
    }

    /**
     * find finds the parent or component of given node
     * 
     * @param p - node for which we have to find the parent.
     * @return - return p's parent
     */
    int find(int p)
    {
        // Find which component p belongs to
        int root = p;
        while (root != m_Nodes[root])
        {
            root = m_Nodes[root];
        }

        // Compress the path for that node
        while (p != root)
        {
            int next = m_Nodes[p];
            m_Nodes[p] = root;
            p = next;
        }
        return root;
    }

    /**
     * unify creates union of two components if they dont already have same parent.
     * 
     * @param p - first node that we want to join
     * @param q - second node that we want to join
     */
    void unify(int p, int q)
    {
        std::cout << "***Creating union of " << p << " & " << q << "***" << '\n';
        // Find parents of both nodes
        int root1 = find(p);
        int root2 = find(q);
        std::cout << "***Parent of " << p << " is " << root1 << " & that of " << q << " is " << root2 << "***" << '\n';

        // If they have same parents then we don't have to unify them
        if (root1 == root2)
        {
            std::cout << "***Elements " << p << " & " << q << " have same parent " << root1 << "***" << '\n';
            return;
        }

        // Merge component with smaller size with component with larger size
        if (m_CompSize[root1] < m_CompSize[root2])
        {
            std::cout << "***Merging " << root1 << " of size " << m_CompSize[root1] << " with " << root2 << " of size " << m_CompSize[root2] << "***" << '\n';
            m_CompSize[root2] += m_CompSize[root1];
            m_Nodes[root1] = root2;
        }
        else
        {
            std::cout << "***Merging " << root2 << " of size " << m_CompSize[root2] << " with " << root1 << " of size " << m_CompSize[root1] << "***" << '\n';
            m_CompSize[root1] += m_CompSize[root2];
            m_Nodes[root2] = root1;
        }

        // Reduce number of components when union is performed
        m_NumComponents--;
        std::cout << "***Remainging number of components " << m_NumComponents << "***" << '\n';
    }

    /**
     * size returns total number of elements in Disjoint set
     * 
     * @return - total number of individual elements present
     */
    int size()
    {
        return m_Size;
    }

    /**
     * numComponents returns total number of individual components
     * 
     * @return - number of components present in our disjoint set
     */
    int numComponents()
    {
        return m_NumComponents;
    }

    /**
     * componentSize return number of elements in component that contains element p
     * 
     * @param p - element/node
     * @return - size of component in which p is present
     */
    int componentSize(int p)
    {
        return m_CompSize[find(p)];
    }

    /**
     * isConnected - checks if two elements are connected or not
     * 
     * @param p - first node that we want to check
     * @param q - second node that we want to check
     * @return - true if both elements are connected false otherwise
     */
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
};

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