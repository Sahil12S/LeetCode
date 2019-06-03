/**
 * There is a ball in a maze with empty spaces and walls.
 * The ball can go through empty spaces by rolling up, down, left or right,
 * but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
 * 
 * Given the ball's start position, the destination and the maze,
 * find the shortest distance for the ball to stop at the destination.
 * The distance is defined by the number of empty spaces traveled by the ball
 * from the start position (excluded) to the destination (included).
 * If the ball cannot stop at the destination, return -1.
 *
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space.
 * You may assume that the borders of the maze are all walls.
 * The start and destination coordinates are represented by row and column indexes.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Macros
#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)
#define PRINT(s) std::cout << s
#define PRINTS(s) std::cout << s << ' '
#define PRINTLN(s) std::cout << s << '\n'

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using qvi = std::queue<std::vector<int>>;

int shortestDistance(vvi &maze, vi &start, vi &destination);
bool isValidPoint(vvi &A, int i, int j);

int main(int argc, char const *argv[])
{
    vvi maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}};

    vi start = {0, 4};
    vi destination = {3, 2};
    // vi destination = {4, 4};

    FORI(0, 5)
    {
        FORJ(0, 5)
        {
            PRINTS(maze[i][j]);
        }
        PRINTLN("");
    }

    PRINTLN(shortestDistance(maze, start, destination));
    return 0;
}

int shortestDistance(vvi &maze, vi &start, vi &destination)
{
    vvi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vvi distance(maze.size(), vi(maze[0].size(), std::numeric_limits<int>::max()));
    qvi q;
    q.push(start);
    distance[start[0]][start[1]] = 0;

    while (!q.empty())
    {
        int r = q.front()[0];
        int c = q.front()[1];
        q.pop();

        FORI(0, 4)
        {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            int dist_travelled = 0;
            while (isValidPoint(maze, nr, nc) && maze[nr][nc] == 0)
            {
                nr += dirs[i][0];
                nc += dirs[i][1];
                dist_travelled++;
            }

            int val = maze[nr - dirs[i][0]][nc - dirs[i][1]];

            if (distance[r][c] + dist_travelled < distance[nr - dirs[i][0]][nc - dirs[i][1]])
            {
                q.push({nr - dirs[i][0], nc - dirs[i][1]});
                distance[nr - dirs[i][0]][nc - dirs[i][1]] = distance[r][c] + dist_travelled;
            }
        }
    }
    return distance[destination[0]][destination[1]] == std::numeric_limits<int>::max() ? -1 : distance[destination[0]][destination[1]];
}

bool isValidPoint(vvi &A, int i, int j)
{
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
    {
        return false;
    }
    return true;
}