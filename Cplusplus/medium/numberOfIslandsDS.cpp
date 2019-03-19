// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

// Implementation using Disjoint Sets

#include <iostream>
#include <vector>

using namespace std;


class DisjointSets
{
private:
    int* parent;
    int* rank;
    int n;
    void makeSet();

public:
    DisjointSets(int N);
    ~DisjointSets();
    int find(int x);
    void Union(int x, int y);

    void print();
};

DisjointSets::DisjointSets(int N)
{
    n = N;
    parent = new int[n];
    rank = new int[n];
    makeSet();
}

DisjointSets::~DisjointSets()
{
    delete[] parent;
    delete[] rank;
}

void DisjointSets::makeSet()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int DisjointSets::find(int x)
{
    if (parent[x] != x)
    {
        return find(parent[x]);
    }

    return x;
}

void DisjointSets::Union(int x, int y)
{
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot == yRoot)
    {
        return;
    }

    if(rank[xRoot] < rank[yRoot])
    {
        parent[xRoot] = yRoot;
    }
    else if (rank[xRoot] > rank[yRoot])
    {
        parent[yRoot] = xRoot;
    }
    else
    {
        parent[yRoot] = xRoot;
        rank[xRoot]++;  
    }

}

void DisjointSets::print()
{
    cout << "Parent" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " ";
    }

    cout << endl;

    cout << "Rank" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << rank[i] << " ";
    }
    cout << endl;
}


int countIslands(vector< vector<int>>& grid);
void printGrid(vector< vector<int>> grid);


int main(int argc, char const *argv[])
{
    // vector< vector<int>> island = {
    //     {1, 1, 1, 1, 0},
    //     {1, 1, 0, 1, 0},
    //     {1, 1, 0, 0, 0},
    //     {0, 0, 0, 0, 0}
    // };

    // vector< vector<int>> island = {
    //     {1, 1, 0, 0, 0},
    //     {1, 1, 0, 0, 0},
    //     {0, 0, 1, 0, 0},
    //     {0, 0, 0, 1, 1}
    // };

    vector< vector<int>> island = {
        {1, 1, 0, 0, 0}, 
        {0, 1, 0, 0, 1}, 
        {1, 0, 0, 1, 1}, 
        {0, 0, 0, 0, 0}, 
        {1, 0, 1, 0, 1} 
    };

    cout << "Number of Islands: " << countIslands(island) << endl;
    return 0;
}

int countIslands(vector< vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    DisjointSets* ds = new DisjointSets(m * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                continue;
            }

            if (i + 1 < n && grid[i + 1][j] == 1)
            {
                ds->Union(i * (m) + j, (i + 1) * (m) + j);
            }
            if (i - 1 >= 0 && grid[i - 1][j] == 1)
            {
                ds->Union(i * (m) + j, (i - 1) * (m) + j);
            }
            if (j + 1 < m && grid[i][j + 1] == 1)
            {
                ds->Union(i * (m) + j, i * (m) + j + 1);
            }
            if (j - 1 <= 0 && grid[i][j - 1])
            {
                ds->Union(i * (m) + j, i * (m) + j - 1);
            }
            if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == 1)
            {
                ds->Union(i * m + j, (i + 1) * m + j + 1);
            }
            if (i + 1 < n && j - 1 >= 0 && grid[i + 1][j - 1] == 1)
            {
                ds->Union(i * m  + j, (i + 1) * m + j - 1);
            }
            if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] == 1)
            {
                ds->Union(i * m + j, (i - 1) * m + j + 1);
            }
            if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 1)
            {
                ds->Union(i * m + j, (i - 1) * m + j - 1);
            }

        }
    }

    // ds->print();

    int* c = new int[n * m];

    int numIslands = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                int x = ds->find(i * m + j);

                if (c[x] == 0)
                {
                    numIslands++;
                    c[x]++;
                }
                else
                {
                    c[x]++;
                }
            }
        }
    }
    return numIslands;
}

void printGrid(vector< vector<int>> grid)
{
    for (vector<int> vc : grid)
    {
        for (int c : vc)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}