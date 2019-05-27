/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

void setZeroes(std::vector<std::vector<int>> &matrix);

int main()
{
    // std::vector<std::vector<int>> matrix = {
    //     {0, 1, 2, 0},
    //     {3, 4, 5, 2},
    //     {1, 3, 1, 5}};
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    setZeroes(matrix);
    for (auto row : matrix)
    {
        for (auto val : row)
        {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }
    return 0;
}

void setZeroes(std::vector<std::vector<int>> &matrix)
{
    int num_rows = matrix.size();
    if (num_rows == 0)
    {
        return;
    }
    int num_cols = matrix[0].size();

    // To check if 0th column needs to be made 0
    bool isCol = false;

    for (int r = 0; r < num_rows; r++)
    {
        // Check for 0th column
        if (matrix[r][0] == 0)
        {
            isCol = true;
        }

        for (int c = 1; c < num_cols; c++)
        {
            // mark first row and column to be converted to zeroes
            if (matrix[r][c] == 0)
            {
                matrix[r][0] = 0;
                matrix[0][c] = 0;
            }
        }
    }

    for (int r = 1; r < num_rows; r++)
    {
        for (int c = 1; c < num_cols; c++)
        {
            if (matrix[r][0] == 0 || matrix[0][c] == 0)
            {
                matrix[r][c] = 0;
            }
        }
    }

    // Check for 0th row
    if (matrix[0][0] == 0)
    {
        for (int c = 0; c < num_cols; c++)
        {
            matrix[0][c] = 0;
        }
    }
    // Check for 0th column
    if (isCol)
    {
        for (int r = 0; r < num_rows; r++)
        {
            matrix[r][0] = 0;
        }
    }
}
/* Space M + N
void setZeroes(std::vector<std::vector<int>> &matrix)
{
    int num_rows = matrix.size();
    if (num_rows == 0)
    {
        return;
    }
    int num_cols = matrix[0].size();

    std::unordered_set<int> rows;
    std::unordered_set<int> columns;

    for (int r = 0; r < num_rows; r++)
    {
        for (int c = 0; c < num_cols; c++)
        {
            if (matrix[r][c] == 0)
            {
                rows.insert(r);
                columns.insert(c);
            }
        }
    }

    for (auto it = rows.begin(); it != rows.end(); it++)
    {
        for (int i = 0; i < num_cols; i++)
        {
            matrix[*it][i] = 0;
        }
    }

    for (auto it = columns.begin(); it != columns.end(); it++)
    {
        for (int i = 0; i < num_rows; i++)
        {
            matrix[i][*it] = 0;
        }
    }
}
*/