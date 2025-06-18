#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // space optimization
    // TC: O(M.N)
    // SC: O(2.N)
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);

        prev[0] = 1;
        for (int row = 0; row < m; row++)
        {
            vector<int> temp(n, 0);
            for (int col = 0; col < n; col++)
            {
                int up = prev[col];
                int left = (col > 0) ? temp[col - 1] : 0;
                temp[col] = up + left;
            }
            prev = temp;
        }

        return prev[n - 1];
    }

    // TC: O(M.N)
    // SC: O(M.N)
    int uniquePaths_tabu(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                    dp[row][col] = 1; // base case
                else
                {
                    int up = 0;
                    int left = 0;
                    if (row > 0)
                        up = dp[row - 1][col];
                    if (col > 0)
                        left = dp[row][col - 1];

                    dp[row][col] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    // TC: O(M.N)
    // SC: O((M-1) + (N-1)) + O(M.N)
    int uniquePaths_memo(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }

private:
    int f(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
            return 1;

        if (row < 0 || col < 0)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int up = f(row - 1, col, dp);
        int left = f(row, col - 1, dp);

        return dp[row][col] = up + left;
    }

    // Recursion
    // TC: O(2^(M.N))
    // SC: O((M-1) + (N-1))
};

int main()
{

    return 0;
}