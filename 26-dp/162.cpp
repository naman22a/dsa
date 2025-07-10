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
        return matrixMultiplication_memo(arr);
    }

    // TC: O(N^3)
    // SC: O(N^2) + O(N)
    int matrixMultiplication_memo(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(1, n - 1, arr, dp);
    }

private:
    // i -> start
    // j -> end
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        // single matrix
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = 1e9;
        for (int k = i; k <= j - 1; k++)
        {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            mini = min(mini, steps);
        }

        return dp[i][j] = mini;
    }

    // Recursion
    // TC: O(exponential)
    // SC: O(N)
};

int main()
{

    return 0;
}