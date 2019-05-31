/**
 * Let's play the minesweeper game (Wikipedia, online game)!
 * You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine,
 * 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent
 * (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines 
 * are adjacent to this revealed square, and finally 'X' represents a revealed mine.
 *
 * Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'),
 * return the board after revealing this position according to the following rules:
 *
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') 
 * and all of its adjacent unrevealed squares should be revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed,
 * then change it to a digit ('1' to '8') representing the number of adjacent mines.
 * Return the board when no more squares will be revealed.
 */

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>> &board, std::vector<int> &click);
int count_mines(std::vector<std::vector<char>> &board, int rows, int cols, int r, int c);
void pirnt(std::vector<std::vector<char>> &board);

int main(int argc, char const *argv[])
{
    // std::vector<std::vector<char>> board = {
    //     {'E', 'E', 'E', 'E', 'E'},
    //     {'E', 'M', 'M', 'E', 'E'},
    //     {'E', 'E', 'E', 'E', 'E'},
    //     {'E', 'E', 'E', 'E', 'E'}};
    // std::vector<int> click = {3, 0};

    // std::vector<std::vector<char>> board = {
    //     {'B', 'B', 'E', 'B', 'B'},
    //     {'B', '1', 'M', '1', 'B'},
    //     {'B', '1', '1', '1', 'B'},
    //     {'B', 'B', 'B', 'B', 'B'}};
    // std::vector<int> click = {1, 2};

    // std::vector<std::vector<char>> board = {
    //     {'E', 'E', 'E', 'E', 'E'},
    //     {'E', 'E', 'E', 'E', 'E'},
    //     {'E', 'E', 'E', 'E', 'E'},
    //     {'E', 'E', 'E', 'E', 'E'}};

    // std::vector<int> click = {3, 0};

    std::vector<std::vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'M'},
        {'E', 'E', 'M', 'E', 'E', 'E', 'E', 'E'},
        {'M', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'M', 'E', 'E', 'E', 'E'}};
    std::vector<int> click = {0, 0};

    std::vector<std::vector<char>>
        revealed_board = updateBoard(board, click);
    for (auto row : revealed_board)
    {
        for (auto col : row)
        {
            std::cout << col << " ";
        }
        std::cout << '\n';
    }
    return 0;
}

void pirnt(std::vector<std::vector<char>> &board)
{
    for (auto row : board)
    {
        for (auto col : row)
        {
            std::cout << col << " ";
        }
        std::cout << '\n';
    }
}

std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>> &board, std::vector<int> &click)
{
    int rows = board.size();
    int cols = board[0].size();

    int r = click[0];
    int c = click[1];

    // Check if we clicked on a mine
    if (board[r][c] == 'M')
    {
        board[r][c] = 'X';
        return board;
    }

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    visited[r][c] = true;
    std::queue<std::vector<int>> q;
    q.push({r, c});

    while (!q.empty())
    {
        int itr_size = q.size();

        std::cout << "==================" << '\n';
        std::cout << "Size: " << itr_size << '\n';
        std::cout << "==================" << '\n';

        while (itr_size--)
        {
            r = q.front()[0];
            c = q.front()[1];
            q.pop();

            int num_mines = count_mines(board, rows, cols, r, c);

            // Check if adjacent cell has a mine
            if (num_mines > 0)
            {
                // std::cout << 1 + '0' << '\n';
                board[r][c] = num_mines + '0';
                continue;
            }

            board[r][c] = 'B';
            std::cout << "for r: " << r << " c: " << c << " mines: " << board[r][c] << '\n';

            // If adjacent cells are blank
            for (int i = 0; i < 8; i++)
            {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    board[nr][nc] == 'E' && !visited[nr][nc])
                {
                    visited[nr][nc] = true;
                    std::cout << "Pushing: " << nr << " " << nc << ", " << board[nr][nc] << '\n';
                    q.push({nr, nc});
                }
            }
        }
    }
    return board;
}

int count_mines(std::vector<std::vector<char>> &board, int rows, int cols, int r, int c)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        int nr = r + directions[i][0];
        int nc = c + directions[i][1];

        if (nr >= 0 && nr < rows &&
            nc >= 0 && nc < cols &&
            board[nr][nc] == 'M')
        {
            count++;
        }
    }
    return count;
}