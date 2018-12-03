#include <iostream>
#include <vector>
#include <array>

using namespace std;

// vector<int> performSpiral(vector< vector<int>> matrix);
vector<int> performSpiral2(vector< vector<int>> matrix);

int main(int argc, char const *argv[])
{
    vector< vector<int>> matrix{{1,2,3}, {4,5,6}, {7,8,9}};
    // vector< vector<int>> matrix{{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};

    cout << "Given Martrix:\n";

    for ( int x = 0; x < matrix.size(); ++x) {
        for (int y = 0; y < matrix.size(); ++y) {
            cout << matrix[x][y] << "\t";
        }
        cout << endl;
    }
    cout << "Solution: \n";
    vector<int> ans = performSpiral2(matrix);
    for (int n : ans) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

vector<int> performSpiral(vector< vector<int>> matrix) {
    const array< array<int, 2>, 4> shift = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    int dir = 0, x = 0, y = 0;
    vector<int> spiral_order;

    for (int i = 0; i < matrix.size() * matrix.size(); ++i) {
        spiral_order.emplace_back(matrix[x][y]);
        matrix[x][y] = 0;
        int next_x = x + shift[dir][0], next_y = y + shift[dir][1];

        if (next_x < 0 || next_x >= matrix.size() || next_y < 0 || next_y >= matrix.size() || matrix[next_x][next_y] == 0) {
            dir = (dir + 1) % 4;
            next_x = x + shift[dir][0], next_y = y + shift[dir][1];
        }
        x = next_x, y = next_y;
    }
    return spiral_order;
}

vector<int> performSpiral2(vector< vector<int>> matrix) {
    vector<int> values;
    if (matrix.size() == 0) {
        return values;
    }
    array< array<int, 2>, 4> shift = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    
    int direction = 0, x = 0, y = 0;
    
    // vector<vector<bool>> checks;

    for (int i = 0; i < matrix.size() * matrix[0].size(); ++i) {
        values.emplace_back(matrix[x][y]);
        matrix[x][y] = 0;
        int next_x = x + shift[direction][0], next_y = y + shift[direction][1];
        cout << "[1] -> next_x: " << next_x << ", next_y: " << next_y << endl;
        if (next_x < matrix.size() && next_y < matrix[0].size()) {
            cout << matrix[next_x][next_y] << endl;
        }
        cout << "[CHECK]: " << next_x << " " << next_y << " "<< matrix.size() << " "<< matrix[0].size() <<  endl;

        
        if (next_x < 0 || next_x >= matrix.size() || next_y < 0 || next_y >= matrix[0].size() || matrix[next_x][next_y] == 0) {
            direction = (direction + 1) % 4;
            next_x = x + shift[direction][0], next_y = y + shift[direction][1];
            cout << "[2] -> next_x: " << next_x << ", next_y: " << next_y << endl;
        }
        x = next_x, y = next_y;
        cout << "[3] -> x: " << x << ", y: " << y << endl;
    }
    return values;
}