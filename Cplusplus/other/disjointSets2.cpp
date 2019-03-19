// Implementation of Disjoint sets using Quick Find of Fast Union

#include <iostream>

using namespace std;

class DisjointUnionSets
{
private:
    int* size;
    int* height;
    int* parent;
    int numItems;

    void makeSet();
    void print();

public:
    DisjointUnionSets(int n);
    ~DisjointUnionSets();
    int find(int X);

    // Union by Size
    void unionSize(int X, int Y);

    // Union by height
    void unionHeight(int X, int Y);
};

DisjointUnionSets::DisjointUnionSets(int n)
{
    size = new int[n];
    height = new int[n];
    parent = new int[n];
    this->numItems = n;
    makeSet();
}

DisjointUnionSets::~DisjointUnionSets()
{
    delete[] size;
    delete[] height;
    delete[] parent;
}

// Create n sets with single items in each
void DisjointUnionSets::makeSet()
{
    // For Union with Size
    for (int i = 0; i < numItems; i++)
    {
        // Initially all elements are in their own sets.
        parent[i] = -1;
        size[i] = 1;
    }

    // For union with height
    // for (int i = 0; i < numItems; i++)
    // {
    //     // Initially all elements are in their own sets.
    //     parent[i] = -1;
    //     height[i] = 1;
    // }
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
    if (parent[X] == -1)
    {
        return X;
    }
    else
    {
        return find(parent[X]);
    }
}

void DisjointUnionSets::unionSize(int X, int Y)
{
    if (find(X) == find(Y) && find(X) != -1)
    {
        return;
    }

    if (size[Y] < size[X])
    {
        parent[Y] = X;
        size[X] += size[Y];
    }
    else
    {
        parent[X] = Y;
        size[Y] += size[X];
    }

    print();
    
}

void DisjointUnionSets::print()
{
    cout  << "Printing size: " << endl;
    for (int i = 0; i < numItems; i++)
    {
        cout << size[i] << " ";
    }
    cout << endl;

    cout << "Printing parent: " << endl;
    for (int i = 0; i < numItems; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
    
}


void DisjointUnionSets::unionHeight(int X, int Y)
{
    if (find(X) == find(Y) && find(X) != -1)
    {
        return;
    }

    if (parent[Y] < parent[X])
    {
        parent[X] = Y;
    }
    else
    {
        if (parent[Y] == parent[X])
        {
            parent[X]--;
            parent[Y] = X;
        }
    }
    

}


int main(int argc, char const *argv[])
{
    // Let there be 5 persons with ids as
    // 0, 1, 2, 3, 4
    int n = 5;
    DisjointUnionSets ds(n);

    // 0 is a friend of 2
    ds.unionSize(0, 2);
    // ds.unionHeight(0, 2);

    // 4 is a friend of 2
    ds.unionSize(4, 2);
    // ds.unionHeight(4, 2);

    // 3 is a friend of 1
    ds.unionSize(3, 1);
    // ds.unionHeight(3, 1);

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