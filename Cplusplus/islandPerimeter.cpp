#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)
#define FORK(s, n) for (int k = s; k < n; k++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int islandPerimeter(VVI &grid);

int main()
{
    VVI grid = {{0, 1, 0, 0},
                {1, 1, 1, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0}};

    std::cout << islandPerimeter(grid) << '\n';
    return 0;
}

int islandPerimeter(VVI &grid)
{
    int rows = grid.size();
    if (rows == 0)
    {
        return 0;
    }

    int cols = grid[0].size();
    if (cols == 0)
    {
        return 0;
    }

    int perimeter = 0;
    VVI dirs = {{0, -1}, {-1, 0}};
    // , {0, 1}, {1, 0}
    FORI(0, rows)
    {
        FORJ(0, cols)
        {
            if (grid[i][j] == 0)
            {
                continue;
            }
            perimeter += 4;
            FORK(0, 2)
            {
                int nr = i + dirs[k][0];
                int nc = j + dirs[k][1];
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] == 0)
                {
                    continue;
                }
                perimeter -= 2;
            }
            std::cout << perimeter << " ";
            // perimeter += p;
        }
        std::cout << '\n';
    }
    return perimeter;
}