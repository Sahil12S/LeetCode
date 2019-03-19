// Implement Disjoint Sets ADT

#include <iostream>

using namespace std;

class DisjointUnionSets
{
private:
    int* rank;
    int* parent;
    int numItems;

    void makeSet();

public:
    DisjointUnionSets(int n);
    ~DisjointUnionSets();
    int find(int X);

    // Union using Slow Find
    void unionSlowFind(int X, int Y);

    void doUnion(int X, int Y);
};

DisjointUnionSets::DisjointUnionSets(int n)
{
    rank = new int[n];
    parent = new int[n];
    this->numItems = n;
    makeSet();
}

DisjointUnionSets::~DisjointUnionSets()
{
    delete[] rank;
    delete[] parent;
}

// Create n sets with single items in each
void DisjointUnionSets::makeSet()
{
    for (int i = 0; i < numItems; i++)
    {
        // Initially all elements are in their own sets.
        parent[i] = i;
    }
}

// Return's representative of x's set
int DisjointUnionSets::find(int X)
{
    if (X < 0 || X >= numItems)
    {
        return -1;
    }

    // Find the representative of the set
    // that X is an element of
    if (parent[X] != X)
    {
        // if X is not the parent itself
        // then X is not the representative of his set.
        parent[X] = find(parent[X]);

        // so we recursively call Find on its parent 
        // and move i's node directly under the 
        // representative of this set
    }
    return parent[X];
}


void DisjointUnionSets::unionSlowFind(int X, int Y)
{
    if (find(X) == find(Y))
    {
        return;
    }

    if (X < 0 || X >= numItems || Y < 0 || Y >= numItems)
    {
        return;
    }

    parent[X] = Y;
}

void DisjointUnionSets::doUnion(int X, int Y)
{
    // Find represntatives of 2 sets
    int xRoot = find(X), yRoot = find(Y);

    // Elements are in same set, no need to unite anything
    if (xRoot == yRoot)
    {
        return;
    }

    // If X's rank is less than Y's rank
    if (rank[xRoot] < rank[yRoot])
    {
        // Then move X under Y so that depth 
        // of tree remains less
        parent[xRoot] = yRoot;
    }
    // else if Y's rank is less than X's
    else if (rank[xRoot] > rank[yRoot])
    {
        // Then move Y under X so that depth
        // of tree remains less
        parent[yRoot] = xRoot;
    }
    // if ranks are the same
    else
    {
        // Move any one tree under other
        parent[yRoot] = xRoot;

        rank[xRoot] += 1;
    }
    
}



int main(int argc, char const *argv[])
{
    // Let there be 5 persons with ids as
    // 0, 1, 2, 3, 4
    int n = 5;
    DisjointUnionSets ds(n);

    // 0 is a friend of 2
    ds.doUnion(0, 2);

    // 4 is a friend of 2
    ds.doUnion(4, 2);

    // 3 is a friend of 1
    ds.doUnion(3, 1);

    // Check if 4 is friend of 0
    if (ds.find(4) == ds.find(0))
    {
        cout << "4 is friend of 0" << endl;
    }
    else
    {
        cout << "4 is not a friend of 0." << endl;
    }
    
    // Check if 1 is friend of 0
    if (ds.find(1) == ds.find(0))
    {
        cout << "1 is friend of 0" << endl;
    }
    else
    {
        cout << "1 is not a friend of 0." << endl;
    }
    

    return 0;
}
