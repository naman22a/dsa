#include <iostream>
#include <vector>
using namespace std;

// Q1: Matrix Chain Multiplication
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        return matrixMultiplication_tabulation(arr);
    }

    // TC: O(N^3)
    // SC: O(N^2)
    int matrixMultiplication_tabulation(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case
        /* for (int i = 0; i < n; i++)
            dp[i][i] = 0; */

        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                int mini = 1e9;
                for (int k = i; k <= j - 1; k++)
                {
                    int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};

int main()
{

    return 0;
}