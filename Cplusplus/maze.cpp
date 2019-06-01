/**
 * There is a ball in a maze with empty spaces and walls.
 * The ball can go through empty spaces by rolling up, down, left or right,
 * but it won't stop rolling until hitting a wall. When the ball stops,
 * it could choose the next direction.
 * 
 * Given the ball's start position, the destination and the maze,
 * determine whether the ball could stop at the destination.
 * 
 * The maze is represented by a binary 2D array.
 * 1 means the wall and 0 means the empty space.
 * You may assume that the borders of the maze are all walls.
 * The start and destination coordinates are represented by row and column indexes.
 */

#include <iostream>
#include <vector>
#include <queue>

bool hasPath(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &destination);
bool valid(std::vector<std::vector<int>> &maze, int x, int y);

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}};

    std::vector<int> start = {0, 4};
    std::vector<int> destination = {4, 4};

    std::cout << hasPath(maze, start, destination) << '\n';

    return 0;
}
bool valid(std::vector<std::vector<int>> &maze, int x, int y)
{
    int rows = maze.size();
    int cols = maze[0].size();
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

bool hasPath(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &destination)
{
    std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    std::queue<std::vector<int>> q;
    q.push(start);
    maze[start[0]][start[1]] = -1;

    while (!q.empty())
    {
        std::vector<int> point = q.front();
        q.pop();

        if (point[0] == destination[0] && point[1] == destination[1])
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = point[0] + dirs[i][0];
            int nc = point[1] + dirs[i][1];

            while (valid(maze, nr, nc) && maze[nr][nc] == 0)
            {
                nr += dirs[i][0];
                nc += dirs[i][1];
            }
            if (!maze[nr - dirs[i][0]][nc - dirs[i][1]])
            {
                q.push({nr - dirs[i][0], nc - dirs[i][1]});
                maze[nr - dirs[i][0]][nc - dirs[i][1]] = -1;
            }
        }
    }
    return false;
}