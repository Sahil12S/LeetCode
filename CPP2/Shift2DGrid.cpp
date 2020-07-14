#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k);

int main()
{
    vector<vector<int>> grid = {{1,2,3}, {4,5,6}, {7,8,9}};
    int k = 9;
    grid = shiftGrid(grid, k);
    for (auto row : grid)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << '\n';
    }
    return 0;
}

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> nextCol(m);

    while (k-- > 0)
    {
        for (int r = 0; r < m; r++)
        {
            int prev = grid[r][0];
            for (int c = 1; c < n; c++)
            {
                int tmp = grid[r][c];
                grid[r][c] = prev;
                prev = tmp;
                if (c == n - 1)
                {
                    grid[r][0] = prev;
                }
            }
        }
        int prev = grid[0][0];
        for (int r = 1; r < m; r++)
        {
            int tmp = grid[r][0];
            grid[r][0] = prev;
            prev = tmp;
            if (r == m - 1)
            {
                grid[0][0] = prev;
            }
        }
    }
    return grid;
}