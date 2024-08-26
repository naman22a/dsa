#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Q1:
// Leetcode 51: N-Queens

class Solution
{
private:
    unordered_set<int> cols;
    unordered_set<int> postiveDiagonal;  // (r + c)
    unordered_set<int> negativeDiagonal; // (r - c)

public:
    // TC: O(N!)
    // SC: O(N^2)
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(result, n, board, 0);
        return result;
    }

private:
    void backtrack(vector<vector<string>> &result, int n, vector<string> board, int row)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            // exclude this position
            if (cols.find(col) != cols.end() || postiveDiagonal.find(row + col) != postiveDiagonal.end() || negativeDiagonal.find(row - col) != negativeDiagonal.end())
            {
                continue;
            }

            // include this position
            cols.insert(col);
            postiveDiagonal.insert(row + col);
            negativeDiagonal.insert(row - col);
            board[row][col] = 'Q';

            backtrack(result, n, board, row + 1);

            // cleanup
            cols.erase(col);
            postiveDiagonal.erase(row + col);
            negativeDiagonal.erase(row - col);
            board[row][col] = '.';
        }
    }
};

int main()
{

    return 0;
}