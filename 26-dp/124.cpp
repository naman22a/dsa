#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Q1:
// Leetcode 64: Minimum Path Sum
class Solution
{
public:
    // TC: O(M.N)
    // SC: O(N)
    // space optimization
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> prev(n, 0);

        for (int i = 0; i <= m - 1; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j <= n - 1; j++)
            {
                if (i == 0 && j == 0)
                    cur[j] = grid[i][j];
                else
                {
                    // requiring previous row's j column
                    int up = i > 0 ? prev[j] : INT_MAX;

                    // requiring current row's j-1 column
                    int left = j > 0 ? cur[j - 1] : INT_MAX;
                    cur[j] = grid[i][j] + min(up, left);
                }
            }
            prev = cur;
        }

        return prev[n - 1];
    }

    // TC: O(M.N)
    // SC: O(M.N)
    int minPathSum_tabu(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i <= m - 1; i++)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                if (i == 0 && j == 0)
                    dp[0][0] = grid[0][0];
                else
                {
                    int up = i > 0 ? dp[i - 1][j] : INT_MAX;
                    int left = j > 0 ? dp[i][j - 1] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    // TC: O(M.N)
    // SC: O(M.N) + O((M-1) + (N-1))
    int minPathSum_memo(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, grid, dp);
    }

private:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = f(i - 1, j, grid, dp);
        int left = f(i, j - 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    // Recursion
    // TC: O(2^(M.N))
    // SC: O((M-1) + (N-1))
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << s.minPathSum(grid) << endl;

    return 0;
}
