#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Q1:
// Leetcode 931: Minimum Falling Path Sum
class Solution
{
public:
    // TC: O(M.N)
    // SC: O(N)
    // space optimization
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0), cur(n, 0);

        // base case
        for (int j = 0; j < n; j++)
            prev[j] = matrix[0][j];

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = prev[j];
                int left_diagonal = (j > 0) ? prev[j - 1] : INT_MAX;
                int right_diagonal = (j + 1 < n) ? prev[j + 1] : INT_MAX;

                cur[j] = matrix[i][j] + min(up, min(left_diagonal, right_diagonal));
            }

            prev = cur;
        }

        int mini = INT_MAX;
        for (int j = 0; j < n; j++)
            mini = min(mini, prev[j]);
        return mini;
    }

    // TC: O(M.N)
    // SC: O(M.N)
    int minFallingPathSum_tabu(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // base case
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = dp[i - 1][j];
                int left_diagonal = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int right_diagonal = (j + 1 < n) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(up, min(left_diagonal, right_diagonal));
            }
        }

        int mini = dp[m - 1][0];
        for (int j = 1; j < n; j++)
            mini = min(mini, dp[m - 1][j]);
        return mini;
    }

    // TC: O(M.N)
    // SC: O(M.N) + O(M)
    int minFallingPathSum_memo(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int mini = INT_MAX;
        for (int j = 0; j < n; j++)
            mini = min(mini, f(m - 1, j, matrix, dp));
        return mini;
    }

private:
    int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        int n = matrix[0].size();
        if (j < 0 || j >= n)
            return INT_MAX;

        if (i == 0)
            return matrix[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = f(i - 1, j, matrix, dp);
        int left_diagonal = f(i - 1, j - 1, matrix, dp);
        int right_diagonal = f(i - 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min(up, min(left_diagonal, right_diagonal));
    }

    // Recursion
    // TC: O(3^(M.N))
    // SC: O(M)
};

int main()
{

    return 0;
}