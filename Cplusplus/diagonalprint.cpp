// Given a matrix of M x N elements (M rows, N columns),
// return all elements of the matrix in diagonal order.

#include <iostream>
#include <vector>

using namespace std;

void travelDiagonally(vector< vector<int>> matrix, int m, int n);

int main(int argc, char const *argv[])
{
    vector< vector<int>> matrix{
        { 1,  2,  3},
        { 4,  5,  6},
        { 7,  8,  9},
        {10, 11, 12},
        {13, 14, 15}
    };

    int m = matrix.size();
    int n = matrix[0].size();


    travelDiagonally(matrix, m, n);

    return 0;
}

void travelDiagonally(vector< vector<int>> matrix, int m, int n) {
    int row = 0, col = 0;
    bool row_inc = false;
    // to print upper half
    int min_len = min(m, n);

    for (int d_len = 1; d_len <= min_len; ++d_len) {
        for (int i = 0; i < d_len; ++i) {
            cout << matrix[row][col] << " ";

            // cout << "here" << endl;
            if (i + 1 == d_len) {
                break;
            }

            if (row_inc) {
                ++row, --col;
            } else {
                --row, ++col;
            }

        }
        if (d_len == min_len) {
            break;
        }
        if (row_inc) {
            ++row, row_inc = false;
        } else {
            ++col, row_inc = true;
        }
    }
    // cout << endl;

    // if we stop at row = 0, then we move to next column only if we are not in last column.
    // if we stop at col = 0 then we move to next column.

    // cout << row << ", " << col << endl;
    if (row == 0) {
        if (col == n - 1) {
            ++row;
        } else {
            ++col;
        }
        row_inc = true;
    } else {
        if (row == m - 1) {
            ++col;
        } else {
            ++row;
        }
        row_inc = false;
    }
    // cout << "1: " << row << ", " << col << endl;

    int max_len = max(m, n) - 1;

    for(int d_len = max_len; d_len > 0; --d_len) {
        int len = min(d_len, min_len);
        
        for (int i = 0; i < len; ++i) {
            // cout << "2: " << row << ", " << col << endl;
            cout << matrix[row][col] << " ";

            if (i + 1 == len) {
                break;
            }
            if (row_inc) {
                ++row, --col;
            } else {
                --row, ++col;
            }
        }
        // cout << "3: " << row << ", " << col << endl;

        if (row == 0 || col == n - 1) {
            if (col == n - 1) {
                ++row;
            } else {
                ++col;
            }
            row_inc = true;
        } else if (col == 0 || row == m - 1) {
            if (row == m - 1) {
                ++col;
            } else {
                ++row;
            }
            row_inc = false;
        }
    }
    cout << endl;

}
