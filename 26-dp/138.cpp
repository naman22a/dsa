#include <iostream>
#include <vector>
using namespace std;

// Q1: Rod Cutting Problem
/*
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.
Note: n = size of price, and price[] is 1-indexed array.

https://www.geeksforgeeks.org/problems/rod-cutting0840/1
*/

class Solution
{
public:
    // TC: O(N^2)
    // SC: O(N)
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> prev(n + 1, 0);

        for (int N = 0; N <= n; N++)
            prev[N] = N * price[0];

        for (int index = 1; index <= n - 1; index++)
        {
            for (int N = 0; N <= n; N++)
            {
                int not_take = 0 + prev[N];
                int take = INT_MIN;
                int rodLength = index + 1;
                if (rodLength <= N)
                    take = price[index] + prev[N - rodLength];
                prev[N] = max(take, not_take);
            }
        }

        return prev[n];
    }

    // TC: O(N^2)
    // SC: O(2.N)
    int cutRod_space_optimization(vector<int> &price)
    {
        int n = price.size();
        vector<int> prev(n + 1, 0);
        vector<int> cur(n + 1, 0);

        for (int N = 0; N <= n; N++)
            prev[N] = N * price[0];

        for (int index = 1; index <= n - 1; index++)
        {
            for (int N = 0; N <= n; N++)
            {
                int not_take = 0 + prev[N];
                int take = INT_MIN;
                int rodLength = index + 1;
                if (rodLength <= N)
                    take = price[index] + cur[N - rodLength];
                cur[N] = max(take, not_take);
            }
            prev = cur;
        }

        return prev[n];
    }

    // TC: O(N^2)
    // SC: O(N^2)
    int cutRod_tabu(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int N = 0; N <= n; N++)
            dp[0][N] = N * price[0];

        for (int index = 1; index <= n - 1; index++)
        {
            for (int N = 0; N <= n; N++)
            {
                int not_take = 0 + dp[index - 1][N];
                int take = INT_MIN;
                int rodLength = index + 1;
                if (rodLength <= N)
                    take = price[index] + dp[index][N - rodLength];
                dp[index][N] = max(take, not_take);
            }
        }

        return dp[n - 1][n];
    }

    // TC: O(N^2)
    // SC: O(N^2) + O(N)
    int cutRod_memo(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n - 1, n, price, dp);
    }

private:
    int f(int index, int N, vector<int> &price, vector<vector<int>> &dp)
    {
        if (index == 0)
            return N * price[0];

        if (dp[index][N] != -1)
            return dp[index][N];

        int not_take = 0 + f(index - 1, N, price, dp);
        int take = INT_MIN;
        int rodLength = index + 1;
        if (rodLength <= N)
            take = price[index] + f(index, N - rodLength, price, dp);
        return dp[index][N] = max(take, not_take);
    }
};

// similar to "Unbounded Knapsack"

int main()
{

    return 0;
}