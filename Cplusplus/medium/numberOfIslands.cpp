// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

#include <iostream>
#include <vector>

using namespace std;

int numOflands(vector< vector<char>>& grid);
void dfsHelper(vector< vector<char>>& grid, int r, int c);
void printGrid(vector< vector<char>> grid);


int main(int argc, char const *argv[])
{
    // vector< vector<char>> island = {
    //     {'1', '1', '1', '1', '0'},
    //     {'1', '1', '0', '1', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '0', '0', '0'}
    // };
    vector< vector<char>> island = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of islands: " << numOflands(island) << endl;
    return 0;
}

int numOflands(vector< vector<char>>& grid)
{
    int numRows = grid.size();
    
    if (!numRows)
        return 0;
    
    int numColumns = grid[0].size();

    int numOfIslands = 0;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            if (grid[i][j] == '1')
            {
                ++numOfIslands;
                dfsHelper(grid, i, j);
            }
        }
    }

    return numOfIslands;
}


void dfsHelper(vector< vector<char>>& grid, int r, int c)
{
    int numRows = grid.size();
    int numColumns = grid[0].size();

    grid[r][c] = '0';


    if (r > 0 && grid[r - 1][c] == '1')
    {
        dfsHelper(grid, r - 1, c);
    }
    if (r + 1 < numRows && grid[r + 1][c] == '1')
    {
        dfsHelper(grid, r + 1, c);
    }

    if (c > 0 && grid[r][c - 1] == '1')
    {
        dfsHelper(grid, r, c - 1);
    }

    if (c + 1 < numColumns && grid[r][c + 1] == '1')
    {
        dfsHelper(grid, r, c + 1);
    }

}

void printGrid(vector< vector<char>> grid)
{
    for (vector<char> vc : grid)
    {
        for (char c : vc)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}