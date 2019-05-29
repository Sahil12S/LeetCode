#include <iostream>
#include <vector>
#include <queue>

struct Tree
{
    int row;
    int col;
    int dist;
    Tree(int r, int c, int d) : row(r), col(c), dist(d) {}
};

class Compare
{
public:
    bool operator()(const std::vector<int> &v1, const std::vector<int> &v2)
    {
        return v1[0] > v2[0];
    }
};

int cutOffTree(std::vector<std::vector<int>> &forest);
int helper(
    std::vector<std::vector<int>> &forest,
    std::vector<std::vector<bool>> visited,
    int row, int col, int start_x, int start_y, int dest_x, int dest_y);

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> forest = {
        {2, 3, 4},
        {0, 0, 5},
        {8, 7, 6}};
    // std::vector<std::vector<int>> forest = {
    //     {1, 2, 3},
    //     {0, 0, 0},
    //     {7, 6, 5}};
    // std::vector<std::vector<int>> forest = {
    //     {1, 2, 3},
    //     {0, 0, 4},
    //     {7, 6, 5}};

    std::cout << cutOffTree(forest) << std::endl;
    return 0;
}

int cutOffTree(std::vector<std::vector<int>> &forest)
{
    int num_row = forest.size();
    int num_col = forest[0].size();

    // Find min heights of trees & obstacles
    auto comp = [](std::vector<int> v1, std::vector<int> v2) { return v1[0] > v2[0]; };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> pq(comp);
    // std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare> pq;
    std::vector<std::vector<bool>> visited(num_row, std::vector<bool>(num_col, false));
    for (int r = 0; r < num_row; r++)
    {
        for (int c = 0; c < num_col; c++)
        {
            if (forest[r][c] == 0)
            {
                visited[r][c] = true;
            }
            else if (forest[r][c] > 1)
            {
                pq.push({forest[r][c], r, c});
            }
        }
    }

    int retval = 0;

    int start_x = 0;
    int start_y = 0;
    while (!pq.empty())
    {
        // First target
        auto target = pq.top();
        pq.pop();
        int steps = helper(forest, visited, num_row, num_col, start_x, start_y, target[1], target[2]);
        if (steps == -1)
        {
            return -1;
        }
        retval += steps;
        start_x = target[1];
        start_y = target[2];
    }
    return retval;
}

int helper(
    std::vector<std::vector<int>> &forest,
    std::vector<std::vector<bool>> visited,
    int row, int col, int start_x, int start_y, int dest_x, int dest_y)
{
    if (start_x == dest_x && start_y == dest_y)
    {
        return 0;
    }

    // We start at 0,0
    std::queue<Tree> q;
    Tree t(start_x, start_y, 0);
    // Our starting position
    q.push(t);

    visited[start_x][start_y] = false;

    while (!q.empty())
    {
        Tree p = q.front();
        q.pop();

        if (p.row == dest_x && p.col == dest_y)
        {
            return p.dist;
        }

        // Moving up
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false)
        {
            q.push(Tree(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
        // moving down
        if (p.row + 1 < row &&
            visited[p.row + 1][p.col] == false)
        {
            q.push(Tree(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }

        // moving left
        if (p.col - 1 >= 0 &&
            visited[p.row][p.col - 1] == false)
        {
            q.push(Tree(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }

        // moving right
        if (p.col + 1 < col &&
            visited[p.row][p.col + 1] == false)
        {
            q.push(Tree(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}