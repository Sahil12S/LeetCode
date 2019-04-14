/*
A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.
Here are the rules of Tic-Tac-Toe:
    Players take turns placing characters into empty squares (" ").
    The first player always places "X" characters, while the second player always places "O" characters.
    "X" and "O" characters are always placed into empty squares, never filled ones.
    The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
    The game also ends if all squares are non-empty.
    No more moves can be played if the game is over.
*/

#include <iostream>
#include <vector>

using namespace std;

bool validTicTacToe( vector<string>& board );
bool win( vector<string>& board, char player );

int main(int argc, char const *argv[])
{
    vector<string> board = { "XOX", " X ", "   " };
    cout << validTicTacToe( board ) << endl;

    return 0;
}


bool validTicTacToe( vector<string>& board )
{
    int countX = 0;
    int countO = 0;

    for ( string row : board )
    {
        for ( char c : row )
        {
            if ( c == 'X' )
            {
                countX++;
            }
            if ( c == 'O' )
            {
                countO++;
            }
        }
    }

    if ( countX != countO && countX != countO + 1 )
    {
        return false;
    }

    if ( countX != countO && win( board, 'O' ) )
    {
        return false;
    }

    if ( countX != countO + 1 && win( board, 'X' ) )
    {
        return false;
    }

    return true;
}

bool win( vector<string>& board, char player )
{
    int n = board.size();
    for ( int i = 0; i < n; i++ )
    {
        // Check row for win
        for ( int j = 0; j < n; j++ )
        {
            if (board[i][j] != player )
            {
                break;
            }
            else if ( j == n - 1 && board[i][j] == player )
            {
                return true;
            }
        }

        // Check column for win
        for ( int j = 0; j < n; j++ )
        {
            if (board[j][i] != player )
            {
                break;
            }
            else if ( j == n - 1 && board[j][i] == player )
            {
                return true;
            }
        }


        // if ( board[i][0] == player && board[i][1] == player && board[i][2] == player )
        // {
        //     return true;
        // }

        // if ( board[0][i] == player && board[1][i] == player && board[2][i] == player )
        // {
        //     return true;
        // }
    }

    // Check first diagonal
    for ( int i = 0; i < n; i++ )
    {
        if ( board[i][i] != player )
        {
            break;
        }
        else if ( board[i][i] == player && i == n - 1 )
        {
            return true;
        }
    }

    // Check second diagonal
    for ( int i = 0; i < n; i++ )
    {
        if ( board[i][n - i - 1] != player )
        {
            break;
        }
        else if ( board[i][n - i - 1] == player && i == n - 1 )
        {
            return true;
        }
    }

    // if ( board[0][0] == player && board[1][1] == player && board[2][2] == player )
    // {
    //     return true;
    // }

    // if ( board[0][2] == player && board[1][1] == player && board[2][0] == player )
    // {
    //     return true;
    // }
    return false;
}