/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix( vector< vector<int>>& matrix, int target );

int main(int argc, char const *argv[])
{
    // vector< vector<int>> matrix = 
    // {
    //     {1,   4,  7, 11, 15},
    //     {2,   5,  8, 12, 19},
    //     {3,   6,  9, 16, 22},
    //     {10, 13, 14, 17, 24},
    //     {18, 21, 23, 26, 30}
    // };
    vector< vector<int>> matrix = { { -5 } };
    int target = -5;

    cout << searchMatrix( matrix, target ) << endl;

    return 0;
}

bool searchMatrix( vector< vector<int>>& matrix, int target )
{
    if ( matrix.size() == 0 )
    {
        return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0;
    int col = n - 1;

    cout << row << ", " << col << endl;
    while ( row < m && col >= 0 )
    {
        if ( target < matrix[row][col] )
        {
            col--;
        }
        else if ( target > matrix[row][col] )
        {
            row++;
        }
        else
        {
            return true;
        }
    }
    return false;
}