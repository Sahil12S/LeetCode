/**
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 */

#include <iostream>
#include <vector>
#include <limits>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

#define INF std::numeric_limits<int>::max()

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int minPathSum(VVI &grid);
int find_prev(VVI &dp, int r, int c);

int minPathSum2(VVI &grid);

int main()
{
    VVI grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    std::cout << minPathSum2(grid) << '\n';
    return 0;
}

int minPathSum(VVI &grid)
{
    if (grid.empty())
    {
        return 0;
    }
    int rows = grid.size();
    if (grid[0].empty())
    {
        return 0;
    }
    int cols = grid[0].size();

    VVI dp(rows, VI(cols, INF));
    dp[0][0] = 0;

    FORI(0, rows)
    {
        FORJ(0, cols)
        {
            int prev_val = find_prev(dp, i, j);
            dp[i][j] = std::min(prev_val, dp[i][j]) + grid[i][j];
        }
    }

    return dp[rows - 1][cols - 1];
}

int find_prev(VVI &dp, int r, int c)
{
    VVI dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int res = INF;

    for (auto dir : dirs)
    {
        int nr = r + dir[0];
        int nc = c + dir[1];

        if (nr < 0 || nr >= dp.size() || nc < 0 || nc >= dp[0].size())
        {
            continue;
        }
        res = std::min(dp[nr][nc], res);
    }

    return res;
}

int minPathSum2(VVI &grid)
{
    if (grid.empty())
    {
        return 0;
    }
    int rows = grid.size();
    if (grid[0].empty())
    {
        return 0;
    }
    int cols = grid[0].size();

    FORI(1, rows)
    {
        grid[i][0] += grid[i - 1][0];
    }
    FORJ(1, cols)
    {
        grid[0][j] += grid[0][j - 1];
    }

    FORI(1, rows)
    {
        FORJ(1, cols)
        {
            grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[rows - 1][cols - 1];
}