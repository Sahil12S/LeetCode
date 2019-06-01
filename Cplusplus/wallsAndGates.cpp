/**
 * You are given a m x n 2D grid initialized with these three possible values.
 * 
 * -1 - A wall or an obstacle.
 * 0 - A gate.
 * INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF 
 *      as you may assume that the distance to a gate is less than 2147483647.
 * Fill each empty room with the distance to its nearest gate.
 * If it is impossible to reach a gate, it should be filled with INF.
 */

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

void wallsAndGatesBFS(std::vector<std::vector<int>> &rooms);
void wallsAndGatesDFS(std::vector<std::vector<int>> &rooms);
void dfs(std::vector<std::vector<int>> &rooms, int x, int y);

void print(std::vector<std::vector<int>> &rooms);

std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(int argc, char const *argv[])
{
    int INF = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> rooms = {
        {INF, -1, 0, INF},
        {INF, INF, INF, -1},
        {INF, -1, INF, -1},
        {0, -1, INF, INF}};
    wallsAndGatesBFS(rooms);
    // wallsAndGatesDFS(rooms);
    print(rooms);
    return 0;
}
void print(std::vector<std::vector<int>> &rooms)
{
    for (auto row : rooms)
    {
        for (auto room : row)
        {
            if (room == __INT_MAX__)
            {
                std::cout << "INF\t";
            }
            else
            {
                std::cout << room << "\t";
            }
        }
        std::cout << '\n';
    }
}

void wallsAndGatesBFS(std::vector<std::vector<int>> &rooms)
{
    int rows = rooms.size();
    if (rows == 0)
    {
        return;
    }
    int cols = rooms[0].size();

    std::queue<std::vector<int>> q;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (rooms[r][c] == 0)
            {
                // Insert all gates
                q.push({r, c});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front()[0];
        int y = q.front()[1];
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nr = x + dirs[k][0];
            int nc = y + dirs[k][1];

            if (nr >= 0 && nr < rooms.size() && nc >= 0 && nc < rooms[0].size() && rooms[nr][nc] > rooms[x][y] + 1)
            {
                rooms[nr][nc] = rooms[x][y] + 1;
                print(rooms);
                std::cout << "=====================\n";
                q.push({nr, nc});
            }
        }
    }
}

void wallsAndGatesDFS(std::vector<std::vector<int>> &rooms)
{
    int rows = rooms.size();
    int cols = rooms[0].size();

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (rooms[r][c] == 0)
            {
                dfs(rooms, r, c);
            }
        }
    }
}

void dfs(std::vector<std::vector<int>> &rooms, int x, int y)
{
    int rows = rooms.size();
    int cols = rooms[0].size();

    for (int k = 0; k < 4; k++)
    {
        int nr = x + dirs[k][0];
        int nc = y + dirs[k][1];

        if (nr >= 0 && nr < rooms.size() && nc >= 0 && nc < rooms[0].size() && rooms[nr][nc] > rooms[x][y] + 1)
        {
            rooms[nr][nc] = rooms[x][y] + 1;
            print(rooms);
            std::cout << "=====================\n";
            dfs(rooms, nr, nc);
        }
    }
}