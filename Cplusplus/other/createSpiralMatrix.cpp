// Given size of matrix, create matrix in spiral form.

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector< vector<int>> createSpiralMatrix(int n);
// void performTraversal(vector< vector<int>>& matrix, int start_pos, vector<int>& values);

int main(int argc, char const *argv[])
{
    vector< vector<int>> matrix{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    // cout << matrix.size() << endl;
    vector< vector<int>> ans = createSpiralMatrix(3);

    for (vector<int> a : ans) {
        for (int n : a) {
            cout << n << ' ';

        }
    }
    
    cout << endl;

    return 0;
}

vector< vector<int>> createSpiralMatrix(int n) {
    vector< vector<int>> matrix(n, vector<int>(n, 0));

    vector< vector<int>> shift{{0,1}, {1,0}, {0,-1}, {-1,0}};

    int counting = n*n;
    // int x = 0, y = 0;
    int i = 1;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            matrix[x][y] = i;
            ++i;
            if (i == n*n) break;

        }
        
    }


    // for (int start_pos = 0; start_pos < ceil( matrix.size() / 2.0 ); ++start_pos) {
    //     performTraversal(matrix, start_pos, values);
    // }
    return matrix;
}