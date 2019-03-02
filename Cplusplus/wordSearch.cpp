// Given a 2D board and a word, find if the word exists in the grid.

#include <iostream>
#include <vector>

using namespace std;

bool exist(vector< vector<char>>& board, string word);
bool find(vector< vector<char>>& board, string word, int i, int r, int c);

int main(int argc, char const *argv[])
{
    // vector< vector<char>> board = {
    //     {'A', 'B', 'C', 'E'},
    //     {'S', 'F', 'C', 'S'},
    //     {'A', 'D', 'E', 'E'}
    // };
    // string word = "ABCCED";
    // string word = "SEE";
    // string word = "ABCB";

    vector< vector<char>> board = {
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'}
    };
    string word = "AAB";


    if (exist(board, word))
    {
        cout << "Word found." << endl;
    }
    else
    {
        cout << "Not found." << endl;
    }
    

    return 0;
}

bool exist(vector< vector<char>>& board, string word)
{
    int m = board.size();
    int n = board[0].size();
    // int i = 0;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (find(board, word, 0, r, c))
                return true;
            
        }
    }
    return false;
}

bool find(vector< vector<char>>& board, string word, int i, int r, int c)
{
    int m = board.size();
    int n = board[0].size();

    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[i])
    {
        return false;
    }

    if (i == word.length() - 1)
    {
        return true;
    }

    char curr = board[r][c];

    board[r][c] = ' ';

    bool found = find(board, word, i + 1, r + 1, c)
                || find(board, word, i + 1, r - 1, c)
                || find(board, word, i + 1, r, c + 1)
                || find(board, word, i + 1, r, c - 1);
    
    board[r][c] = curr;

    return found;
}