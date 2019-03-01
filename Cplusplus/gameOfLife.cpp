/*
Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal)
using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. 
The next state is created by applying the above rules simultaneously to every cell in the current state, 
where births and deaths occur simultaneously.
*/

#include <iostream>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board);
void print(vector< vector<int>> board);

int main(int argc, char const *argv[])
{
    vector< vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    // vector< vector<int>> board = {
    //     {0,0}
    // };

    gameOfLife(board);
    print(board);
    
    return 0;
}
/*
void gameOfLife(vector<vector<int>>& board)
{
    int m = board.size();
    int n = board[0].size();

    vector<int> temp(n, 0);
    vector< vector <int>> updatedBoard(m, temp);
    
    // bool die = false;
    int count = 0;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            count = 0;

            // Cell below
            if (r + 1 < m && board[r + 1][c] == 1)
            {
                count++;
            }
            // Cell above
            if (r - 1 >= 0 && board[r - 1][c] == 1)
            {
                count++;
            }
            // Cell right
            if (c + 1 < n && board[r][c + 1] == 1)
            {
                count++;
            }
            // Cell left
            if (c - 1 >= 0 && board[r][c - 1] == 1)
            {
                count++;
            }
            // Cell right above
            if (r - 1 >= 0 && c + 1 < n && board[r - 1][c + 1] == 1)
            {
                count++;
            }
            // Cell left above
            if (r - 1 >= 0 && c - 1 >= 0 && board[r - 1][c - 1] == 1)
            {
                count++;
            }
            // Cell right below
            if (r + 1 < m && c + 1 < n && board[r + 1][c + 1] == 1)
            {
                count++;
            }
            // Cell left below
            if (r + 1 < m && c - 1 >= 0 && board[r + 1][c - 1] == 1)
            {
                count++;
            }

            cout << "r: " << r << ", c: " << c << endl;
            if (board[r][c] == 0 && count == 3)
            {
                updatedBoard[r][c] = 1;

            }

            if (board[r][c] == 1 && (count == 2 || count == 3))
            {
                updatedBoard[r][c] = 1;
            }

        }
    }

    board = updatedBoard;
}
*/

void gameOfLife(vector<vector<int>>& board)
{
    int m = board.size();
    int n = board[0].size();

    // vector<int> temp(n, 0);
    // vector< vector <int>> updatedBoard(m, temp);
    vector<pair<int, int>> coords;
    
    // bool die = false;
    int count = 0;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            count = 0;

            // Cell below
            if (r + 1 < m && board[r + 1][c] == 1)
            {
                count++;
            }
            // Cell above
            if (r - 1 >= 0 && board[r - 1][c] == 1)
            {
                count++;
            }
            // Cell right
            if (c + 1 < n && board[r][c + 1] == 1)
            {
                count++;
            }
            // Cell left
            if (c - 1 >= 0 && board[r][c - 1] == 1)
            {
                count++;
            }
            // Cell right above
            if (r - 1 >= 0 && c + 1 < n && board[r - 1][c + 1] == 1)
            {
                count++;
            }
            // Cell left above
            if (r - 1 >= 0 && c - 1 >= 0 && board[r - 1][c - 1] == 1)
            {
                count++;
            }
            // Cell right below
            if (r + 1 < m && c + 1 < n && board[r + 1][c + 1] == 1)
            {
                count++;
            }
            // Cell left below
            if (r + 1 < m && c - 1 >= 0 && board[r + 1][c - 1] == 1)
            {
                count++;
            }

            // cout << "r: " << r << ", c: " << c << endl;
            if (board[r][c] == 0 && count == 3)
            {
                coords.push_back(make_pair(r, c));
            }

            if (board[r][c] == 1 && (count < 2 || count > 3))
            {
                coords.push_back(make_pair(r, c));
            }

            // if (board[r][c] == 1 && (count == 2 || count == 3))
            // {
            //     coords.push_back(make_pair(r, c));
            // }

        }
    }

    for (auto c : coords)
    {
        board[c.first][c.second] = !board[c.first][c.second];
    }
}

void print(vector< vector<int>> board)
{
    for (vector<int> row : board)
    {
        for(int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}