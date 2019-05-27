/**
 * Question asked in amazon
 * 
 * Find shortest distance to remove obstacle
 * Obstacle is represented by 9
 * path on which you can move is represented by 1
 * You can travel in trench represented by 0
 * 
*/

#include <iostream>
#include <vector>
#include <queue>

struct QItem
{
    int row;
    int col;
    int dist;
    QItem(int x, int y, int d) : row(x), col(y), dist(d) {}
};

int findMinPath(int rows, int cols, std::vector<std::vector<int>> &vec);

int main()
{
    std::vector<std::vector<int>> vec = {
        {1, 0, 0},
        {1, 0, 0},
        {1, 9, 1}};

    std::cout << findMinPath(3, 3, vec) << '\n';

    return 0;
}

int findMinPath(int rows, int cols, std::vector<std::vector<int>> &vec)
{
    QItem source(0, 0, 0);
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (vec[i][j] == 0)
            {
                visited[i][j] = true;
            }
            else
            {
                visited[i][j] = false;
            }
        }
    }

    std::queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty())
    {
        QItem p = q.front();
        q.pop();

        if (vec[p.row][p.col] == 9)
        {
            return p.dist;
        }

        // Moving up
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false)
        {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
        // moving down
        if (p.row + 1 < rows &&
            visited[p.row + 1][p.col] == false)
        {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }

        // moving left
        if (p.col - 1 >= 0 &&
            visited[p.row][p.col - 1] == false)
        {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }

        // moving right
        if (p.col + 1 < cols &&
            visited[p.row][p.col + 1] == false)
        {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}
