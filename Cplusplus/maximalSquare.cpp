#include <iostream>
#include <vector>

int maximalSquare(std::vector<std::vector<char>> &matrix);
int maximalSquare2(std::vector<std::vector<char>> &matrix);

int main()
{
    std::vector<std::vector<char>> matrix = {
        {'0', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1'},
        {'0', '0', '1', '1', '1'}};
    std::cout << maximalSquare(matrix) << '\n';
    std::cout << maximalSquare2(matrix) << '\n';
    return 0;
}

int maximalSquare(std::vector<std::vector<char>> &matrix)
{
    if (matrix.empty())
    {
        return 0;
    }
    int rows = matrix.size();
    if (matrix[0].empty())
    {
        return 0;
    }
    int cols = matrix[0].size();

    std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));

    int maxSquare = 0;

    for (int r = 1; r <= rows; r++)
    {
        for (int c = 1; c <= cols; c++)
        {
            if (matrix[r - 1][c - 1] == '1')
            {
                dp[r][c] = std::min(std::min(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]) + 1;
                maxSquare = std::max(maxSquare, dp[r][c]);
            }
        }
    }
    return maxSquare * maxSquare;
}

int maximalSquare2(std::vector<std::vector<char>> &matrix)
{
    if (matrix.empty())
    {
        return 0;
    }
    int rows = matrix.size();
    if (matrix[0].empty())
    {
        return 0;
    }
    int cols = matrix[0].size();

    std::vector<int> dp(cols + 1, 0);
    int prev = 0;
    int maxSquare = 0;

    for (int r = 1; r <= rows; r++)
    {
        for (int c = 1; c <= cols; c++)
        {
            int temp = dp[c];
            if (matrix[r - 1][c - 1] == '1')
            {
                dp[c] = std::min(std::min(dp[c], dp[c - 1]), prev) + 1;
                maxSquare = std::max(maxSquare, dp[c]);
            }
            else
            {
                dp[c] = 0;
            }

            prev = temp;
        }
    }
    return maxSquare * maxSquare;
}