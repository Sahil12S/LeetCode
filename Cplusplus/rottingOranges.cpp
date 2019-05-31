/**
 * In a given grid, each cell can have one of three values:
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
 */

#include <iostream>
#include <vector>

int orangesRotting(std::vector<std::vector<int>> &grid);

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> grid = {{0, 2}};
    // std::vector<std::vector<int>> grid = {
    //     {2, 1, 1},
    //     {1, 1, 0},
    //     {1, 0, 1}};
    // std::vector<std::vector<int>> grid = {
    //     {2, 1, 1},
    //     {1, 1, 0},
    //     {0, 1, 1}};

    int ans = orangesRotting(grid);

    std::cout << "Took " << ans << " minutes for all oranges to rot." << '\n';
    return 0;
}

int orangesRotting(std::vector<std::vector<int>> &grid)
{
    if (grid.size() == 0)
    {
        return -1;
    }
    int rows = grid.size();
    int cols = grid[0].size();

    int fresh_count = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == 1)
            {
                fresh_count++;
            }
        }
    }

    std::vector<std::vector<int>> curr_state = grid;

    int minutes = 0;
    while (fresh_count > 0)
    {
        int old_count = fresh_count;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] != minutes + 2)
                {
                    continue;
                }
                std::cout << "Rotten one at: " << r << " " << c << '\n';

                // Check left-right
                if (c - 1 >= 0 && grid[r][c - 1] == 1)
                {
                    std::cout << "Rotting at: " << r << " " << c - 1 << '\n';
                    grid[r][c - 1] += 2 + minutes;
                    fresh_count--;
                }
                if (c + 1 < cols && grid[r][c + 1] == 1)
                {
                    std::cout << "Rotting at: " << r << " " << c + 1 << '\n';
                    grid[r][c + 1] += 2 + minutes;
                    fresh_count--;
                }
                // Check top-down
                if (r - 1 >= 0 && grid[r - 1][c] == 1)
                {
                    std::cout << "Rotting at: " << r - 1 << " " << c << '\n';
                    grid[r - 1][c] += 2 + minutes;
                    fresh_count--;
                }
                if (r + 1 < rows && grid[r + 1][c] == 1)
                {
                    std::cout << "Rotting at: " << r + 1 << " " << c << '\n';
                    grid[r + 1][c] += 2 + minutes;
                    fresh_count--;
                }
            }
        }
        if (old_count == fresh_count)
            break;
        minutes++;
        std::cout << "Fresh count after " << minutes << " minutes is " << fresh_count << '\n';
    }
    return fresh_count == 0 ? minutes : -1;
}