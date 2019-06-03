/**
 * In a given 2D binary array A, there are two islands.
 * (An island is a 4-directionally connected group of 1s not connected to any other 1s.)
 * 
 * Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
 * 
 * Return the smallest number of 0s that must be flipped.
 * (It is guaranteed that the answer is at least 1.)
 */

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)
#define PRINT(s) std::cout << s
#define PRINTS(s) std::cout << s << ' '
#define PRINTLN(s) std::cout << s << '\n'

using vi = std::vector<int>;
using vvi = std::vector<vi>;

int shortestBridge(vvi &A);
void paintdfs(vvi &A, int i, int j);
bool isValidPoint(vvi &A, int i, int j);
bool expand(vvi &A, int i, int j, int color);

int main(int argc, char const *argv[])
{
    vvi A1 = {{0, 1}, {1, 0}};
    vvi A2 = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    vvi A3 = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};

    PRINTLN(shortestBridge(A3));

    return 0;
}

int shortestBridge(vvi &A)
{
    int m = A.size();
    int n = A[0].size();

    // Lets find first island and mark all values of that island as 2
    bool found_island = false;
    FORI(0, m)
    {
        if (found_island)
        {
            break;
        }
        FORJ(0, n)
        {
            if (A[i][j] == 1)
            {
                paintdfs(A, i, j);
                found_island = true;
                break;
            }
        }
    }

    for (int color = 2;; color++)
    {
        FORI(0, m)
        {
            FORJ(0, n)
            {
                // If we found the color, then expand it
                if (color == A[i][j] &&
                    (expand(A, i + 1, j, color) || expand(A, i - 1, j, color) ||
                     expand(A, i, j + 1, color) || expand(A, i, j - 1, color)))
                {
                    // We found the island
                    return color - 2;
                }
            }
        }
    }
    return -1;
}

// Mark values of one island with 2
void paintdfs(vvi &A, int i, int j)
{
    if (isValidPoint(A, i, j) && A[i][j] == 1)
    {
        A[i][j] = 2;
        paintdfs(A, i + 1, j);
        paintdfs(A, i - 1, j);
        paintdfs(A, i, j + 1);
        paintdfs(A, i, j - 1);
    }
}

bool expand(vvi &A, int i, int j, int color)
{
    if (!isValidPoint(A, i, j))
    {
        return false;
    }

    if (A[i][j] == 0)
    {
        A[i][j] = color + 1;
    }

    // Have we found another island?
    return A[i][j] == 1;
}

bool isValidPoint(vvi &A, int i, int j)
{
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
    {
        return false;
    }
    return true;
}