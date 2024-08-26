#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 37: Sudoku Solver

// helper function
bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        // check rows
        if (board[i][col] == c)
            return false;

        // check cols
        if (board[row][i] == c)
            return false;

        // check subboxes
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

// solve the board
bool backtrack(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        // move up the "true" in the decision tree
                        if (backtrack(board))
                            return true;
                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

// TC: O(1) -> O(9^81), -> O(9^(n^2)) in general case
// SC: O(1) -> O(81), -> O(n^2) in general case
void solveSudoku(vector<vector<char>> &board)
{
    backtrack(board);
}

int main()
{

    return 0;
}