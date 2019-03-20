/*
A 2d grid map of m rows and n columns is initially filled with water.
We may perform an addLand operation which turns the water at position (row, col) into a land.
Given a list of positions to operate, count the number of islands after each addLand operation.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> numIslands2(int m, int n, vector< pair<int, int>>& position);
void countIslands(vector< vector<bool>> islands, vector<int>& counts, int r, int c);
void countHelper(vector< vector<bool>>& islands, int r, int c);
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
    vector<bool> temp(n, false);
    vector< vector<bool>> islands(m, temp);

    vector<int> counts;

    for (pair <int, int> p : position)
    {
        islands[p.first][p.second] = true;
        countIslands(islands, counts, m, n);
    }
    return counts;
}

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