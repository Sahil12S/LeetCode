#include <iostream>
#include <vector>
#include <deque>
#include <math.h>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board);
bool HasDuplicate(vector<vector<char>> board, int start_row, int end_row, int start_col, int end_col);

int main(int argc, char const *argv[])
{
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << isValidSudoku(board) << endl;

    return 0;
}

bool isValidSudoku(vector<vector<char>>& board) {
    // Check for duplicates in row
    for (int i = 0; i < board.size(); i++) {
        if (HasDuplicate(board, i, i+1, 0, board.size())) {
            return false;
        }
    }
    cout << "1" << endl;

    // Check for duplicate in column
    for (int j = 0; j < board.size(); j++) {
        if (HasDuplicate(board, 0, board.size(), j, j+1)) {
            return false;
        }
    }
    cout << "2" << endl;

    // Check for regions
    int area_size = sqrt(board.size());
    for (int k = 0; k < area_size; ++k) {
        for (int l = 0; l < area_size; ++l) {
            if (HasDuplicate(board, area_size*k, area_size*(k+1), area_size*l, area_size*(l+1))) {
                return false;
            }
        }
    }
    cout << "3" << endl;
    return true;
}

bool HasDuplicate(vector<vector<char>> board, int start_row, int end_row, int start_col, int end_col) {
    // deque<bool> is_Duplicate(board.size() + 1, false);
    vector<bool> is_Duplicate(board.size() + 1, false);
    
    cout << "4" << endl;
    for (int i = start_row; i < end_row; i++) {
        cout << "5" << endl;
        for (int j = start_col; j < end_col; j++) {
            cout << "6" << endl;
            cout << "i=" << i << ", j=" << j << endl;
            cout << "board=" << board[i][j]  << endl;
            cout << "int(board[i][j] - '0')=" << int(board[i][j] - '0') << endl;
            if (board[i][j] != '.' && is_Duplicate[int(board[i][j] - '0')]) {
                cout << "7" << endl;
                return true;
            }
            cout << "8" << endl;
            cout << "is_Duplicate for " << i << ", " << j << " is " << int(board[i][j] - '0') << endl;
            if(board[i][j] != '.') {
                is_Duplicate[int(board[i][j]-'0')] = true;
            }
        }
    }
    cout << "9" << endl;
    return false;
}