/*
A 2d grid map of m rows and n columns is initially filled with water.
We may perform an addLand operation which turns the water at position (row, col) into a land.
Given a list of positions to operate, count the number of islands after each addLand operation.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class DisjointSets
{
private:
    int* parent;
    int* rank;
    int n;
    void makeSet();
    int numDistinct = 0;

public:
    DisjointSets(int N);
    ~DisjointSets();
    int find(int x);
    void Union(int x, int y);
    int getCount();
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
    print();
    cout << "x: " << x << ", y: " << y << endl;
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
        numDistinct++;
    }
    print();
}

int DisjointSets::getCount()
{
    return numDistinct;
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

vector<int> numIslands2(int m, int n, vector< pair<int, int>>& position);
// void countIslands(vector< vector<bool>> islands, vector<int>& counts, int r, int c);
// void countHelper(vector< vector<bool>>& islands, int r, int c);
void printGrid(vector< vector<bool>> grid);

int main(int argc, char const *argv[])
{
    vector< pair<int, int>> position = {
        {0,0},
        {0,1},
        {1,2},
        {2,1}
    };

    int m = 3, n = 3;

    vector<int> ans = numIslands2(m, n, position);

    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}

vector<int> numIslands2(int m, int n, vector< pair<int, int>>& position)
{
    DisjointSets ds(m * n);
    // int *c = new int[m * n];
    map<int, int> c;

    vector<int> count;

    vector<int> temp(n, 0);
    vector< vector<int>> grid(m, temp);

    for (int i = 0; i < position.size(); i++)
    {
        int x = position[i].first;
        int y = position[i].second;
        cout << "MAIN: x: " << x << ", y: " << y << endl;

        grid[x][y] = 1;

        if (x + 1 < n && grid[x + 1][y] == 1)
        {
            ds.Union(x * m + y, (x + 1) * m + y);
        }
        if (x - 1 >= 0 && grid[x - 1][y] == 1)
        {
            ds.Union(x * m + y, (x - 1) * m + y);
        }
        if (y + 1 < m && grid[x][y + 1] == 1)
        {
            ds.Union(x * m + y, x * m + y + 1);
        }
        if (y - 1 >= 0 && grid[x][y - 1] == 1)
        {
            ds.Union(x * m + y, x * m + y - 1);
        }

        int f = ds.find(x * m + y);
        if (c.find(f) == c.end())
        {
            cout << "in map at: " << f << endl;
            c[f] = 1;
        }
        else
        {
            c[f]++;
        }
        count.push_back(c.size());
        cout << "Getting count: " << ds.getCount() << endl;
    }
    // count.push_back(c.size());

    return count;

}
/*
void countIslands(vector< vector<bool>> islands, vector<int>& counts, int r, int c)
{
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (islands[i][j])
            {
                ++count;
                countHelper(islands, i, j);
            }
        }
    }
    counts.push_back(count);
}

void countHelper(vector< vector<bool>>& islands, int r, int c)
{
    int numRow = islands.size();
    int numCols = islands[0].size();

    islands[r][c] = false;

    if (r > 0 && islands[r - 1][c])     countHelper(islands, r - 1, c);
    if (r + 1 < numRow && islands[r + 1][c])     countHelper(islands, r + 1, c);
    if (c > 0 && islands[r][c - 1])     countHelper(islands, r, c - 1);
    if (c + 1 < numCols && islands[r][c + 1])     countHelper(islands, r, c + 1);

}
*/
void printGrid(vector< vector<bool>> grid)
{
    for (vector<bool> vc : grid)
    {
        for (bool c : vc)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}