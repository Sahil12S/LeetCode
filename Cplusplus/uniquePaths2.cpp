/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 */

#include <iostream>
#include <vector>

#define FORR(s, n) for (int r = s; r < n; r++)
#define FORC(s, n) for (int c = s; c < n; c++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int uniquePathsWithObstacles(VVI &obstacleGrid);

int main()
{
    VVI obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    std::cout << uniquePathsWithObstacles(obstacleGrid) << '\n';
    return 0;
}

int uniquePathsWithObstacles(VVI &obstacleGrid)
{
    if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
    {
        return 0;
    }

    if (obstacleGrid[0][0] == 1)
    {
        return 0;
    }

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    FORR(1, m)
    {
        obstacleGrid[r][0] = (obstacleGrid[r][0] == 0 && obstacleGrid[r - 1][0] == 1) ? 1 : 0;
    }

    FORC(1, n)
    {
        obstacleGrid[0][c] = (obstacleGrid[0][c] == 0 && obstacleGrid[0][c - 1] == 1) ? 1 : 0;
    }

    FORR(1, m)
    {
        FORC(1, n)
        {
            if (obstacleGrid[r][c] != 1)
            {
                obstacleGrid[r][c] = obstacleGrid[r - 1][c] + obstacleGrid[r][c - 1];
            }
            else
            {
                obstacleGrid[r][c] = 0;
            }
        }
    }
    return obstacleGrid[m - 1][n - 1];
}