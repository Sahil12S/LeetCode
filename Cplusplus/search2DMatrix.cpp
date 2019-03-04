// Write an efficient algorithm that searches for a value in an m x n matrix.

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main(int argc, char const *argv[])
{
    // vector< vector<int>> matrix = {{1}, {3}};
    vector< vector<int>> matrix = {
    {1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
    };
    int target = 13;
    
    cout << searchMatrix(matrix, target) << endl;

    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if (!matrix.size())
    {
        return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0, high = m * n - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int num = matrix[mid / n][mid % n];

        if (target > num)
        {
            low = mid + 1;
        }
        else if (target < num)
        {
            high = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}