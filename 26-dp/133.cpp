#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Q1: 0/1 Knapsack
/*
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized.

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/
class Solution
{
public:
    // TC: O(N.W)
    // SC: O(W)
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<int> prev(W + 1, 0);

        // base case
        for (int i = wt[0]; i <= W; i++)
            prev[i] = val[0];

        for (int index = 1; index < n; index++)
        {
            // change the direction of filling
            // will not effect the answer
            // process from W to 0 to avoid overwriting needed values
            for (int weight = W; weight >= 0; weight--)
            {
                int not_take = 0 + prev[weight];
                int take = INT_MIN;
                if (wt[index] <= weight)
                    take = val[index] + prev[weight - wt[index]];

                prev[weight] = max(take, not_take);
            }
        }

        return prev[W];
    }

    // TC: O(N.W)
    // SC: O(2.W)
    int knapsack_space_optimized(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<int> prev(W + 1, 0);
        vector<int> cur(W + 1, 0);

        // base case
        for (int i = wt[0]; i <= W; i++)
            prev[i] = val[0];

        for (int index = 1; index < n; index++)
        {
            for (int weight = 0; weight <= W; weight++)
            {
                int not_take = 0 + prev[weight];
                int take = INT_MIN;
                if (wt[index] <= weight)
                    take = val[index] + prev[weight - wt[index]];

                cur[weight] = max(take, not_take);
            }
            prev = cur;
        }

        return prev[W];
    }

    // TC: O(N.W)
    // SC: O(N.W)
    int knapsack_tabu(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // base case
        for (int i = wt[0]; i <= W; i++)
            dp[0][i] = val[0];

        for (int index = 1; index < n; index++)
        {
            for (int weight = 0; weight <= W; weight++)
            {
                int not_take = 0 + dp[index - 1][weight];
                int take = INT_MIN;
                if (wt[index] <= weight)
                    take = val[index] + dp[index - 1][weight - wt[index]];

                dp[index][weight] = max(take, not_take);
            }
        }

        return dp[n - 1][W];
    }

    // TC: O(N.W)
    // SC: O(N.W) + O(N)
    int knapsack_memo(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, val, wt, dp);
    }

private:
    int f(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            // if last element can fit in the bag
            if (wt[0] <= W)
                return val[0];

            return 0;
        }

        if (dp[index][W] != -1)
            return dp[index][W];

        int not_take = 0 + f(index - 1, W, val, wt, dp);
        int take = INT_MIN;
        if (wt[index] <= W)
            take = val[index] + f(index - 1, W - wt[index], val, wt, dp);

        return dp[index][W] = max(take, not_take);
    }

    // Recursion
    // TC: O(2^N)
    // SC: O(N)
};

int main()
{

    return 0;
}