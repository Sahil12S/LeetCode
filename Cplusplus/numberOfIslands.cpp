// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

#include <iostream>
#include <vector>
#include <queue>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)
#define FORK(s, n) for (int k = s; k < n; k++)

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vc = std::vector<char>;
using vvc = std::vector<vc>;
using qc = std::queue<std::pair<int, int>>;

bool isValidPoint(vvc &A, int i, int j);
int numOflands2(vvc &grid);
void dfsHelper(vvc &grid, int r, int c);
void printGrid(vvc grid);

int main(int argc, char const *argv[])
{
    // vector< vector<char>> island = {
    //     {'1', '1', '1', '1', '0'},
    //     {'1', '1', '0', '1', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '0', '0', '0'}
    // };
    vvc island = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    int count = numOflands2(island);
    std::cout << "Number of islands: " << count << std::endl;
    return 0;
}

int numOflands2(vvc &grid)
{
    int m = grid.size();
    if (m == 0)
    {
        return -1;
    }
    int n = grid[0].size();

    vvi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int count = 0;
    FORI(0, m)
    {
        FORJ(0, n)
        {
            if (grid[i][j] == '1')
            {
                count++;
                // std::cout << count << '\n';
                qc q;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty())
                {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    // std::cout << r << " " << c << " " << grid[r][c] << '\n';

                    FORK(0, 4)
                    {
                        int nr = r + dirs[k][0];
                        int nc = c + dirs[k][1];
                        if (isValidPoint(grid, nr, nc) && grid[nr][nc] == '1')
                        {
                            // std::cout << "pushing: " << nr << " " << nc << '\n';
                            q.push({nr, nc});
                            grid[nr][nc] = '0';
                        }
                    }
                }
            }
        }
    }
    return count;
}

bool isValidPoint(vvc &A, int i, int j)
{
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
    {
        return false;
    }
    return true;
}

int numOflands(vvc &grid)
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

void dfsHelper(vvc &grid, int r, int c)
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

void printGrid(vvc grid)
{
    for (vc v : grid)
    {
        for (char c : v)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}