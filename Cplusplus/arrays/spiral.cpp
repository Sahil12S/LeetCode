// Given n x n matrix.

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> spiralTravel(vector< vector<int>> matrix);
void performTraversal(vector< vector<int>>& matrix, int start_pos, vector<int>& values);

int main(int argc, char const *argv[])
{
    vector< vector<int>> matrix{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    // cout << matrix.size() << endl;
    vector<int> ans = spiralTravel(matrix);

    for (int n : ans) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}


vector<int> spiralTravel(vector< vector<int>> matrix) {
    vector<int> values;
    
    for (int start_pos = 0; start_pos < ceil( matrix.size() / 2.0 ); ++start_pos) {
        performTraversal(matrix, start_pos, values);
    }
    return values;
}

void performTraversal(vector< vector<int>>& matrix, int start_pos, vector<int>& values) {
    if (start_pos == matrix.size() - start_pos - 1) {
        values.emplace_back( matrix[start_pos][start_pos] );
        return;
    }

    // Move right from start pos till start_pos column before last.
    for (int j = start_pos; j < matrix.size() -start_pos - 1; ++j) {
        values.emplace_back( matrix[start_pos][j] );
    }

    // Move down from in column start_pos before last till before row start_pos before last.
    for (int i = start_pos; i < matrix.size() - start_pos - 1; ++i) {
        values.emplace_back( matrix[i][matrix.size() - start_pos - 1] );
    }

    // Move left in row start_pos before last till before start_pos column.
    for (int j = matrix.size() - start_pos - 1; j > start_pos; --j) {
        values.emplace_back( matrix[matrix.size() - start_pos - 1][j] );
    }
    
    // Move up in start_pos column till before start_pos row.
    for (int i = matrix.size() - start_pos - 1; i > start_pos; --i) {
        values.emplace_back( matrix[i][start_pos] );
    }


}