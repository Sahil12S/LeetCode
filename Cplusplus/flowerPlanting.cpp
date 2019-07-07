/**
 * You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.
 * paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.
 * Also, there is no garden that has more than 3 paths coming into or leaving it. * 
 * Your task is to choose a flower type for each garden such that,
 * for any two gardens connected by a path, they have different types of flowers.
 * Return any such a choice as an array answer,
 * where answer[i] is the type of flower planted in the (i+1)-th garden.
 * The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.
 */

#include <iostream>
#include <vector>
#include <queue>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j > n; j--)

using VB = std::vector<bool>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;

VI gardenNoAdj(int N, VVI &paths);

int main()
{
    VVI paths = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}};
    int N = 4;
    VI ans = gardenNoAdj(N, paths);
    for (auto val : ans)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';
    return 0;
}

VI gardenNoAdj(int N, VVI &paths)
{
    VI result(N, 0);
    VVI adjList(N);

    for (auto path : paths)
    {
        adjList[path[0] - 1].push_back(path[1] - 1);
        adjList[path[1] - 1].push_back(path[0] - 1);
    }

    FORI(0, N)
    {
        // We got total of 4 flowers
        VB used_flower(5);
        // Check which flowers have been used already
        // for current set of gardens.
        for (auto garden : adjList[i])
        {
            used_flower[result[garden]] = true;
        }
        FORJ(4, 0)
        {
            if (!used_flower[j])
            {
                result[i] = j;
            }
        }
    }
    return result;
}