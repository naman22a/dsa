#include <iostream>
#include <vector>
using namespace std;

// Q1: Unbounded Knapsack / Knapsack with Duplicate Items
/*
Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
*/

class Solution
{
public:
    // TC: O(N.capacity)
    // SC: O(capacity)
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<int> prev(capacity + 1, 0);

        // base cases
        for (int W = 0; W <= capacity; W++)
            prev[W] = (W / wt[0]) * val[0];

        for (int index = 1; index <= n - 1; index++)
        {
            for (int W = 0; W <= capacity; W++)
            {
                int not_take = 0 + prev[W];
                int take = INT_MIN;
                if (wt[index] <= W)
                    take = val[index] + prev[W - wt[index]];
                prev[W] = max(take, not_take);
            }
        }

        return prev[capacity];
    }

    // TC: O(N.capacity)
    // SC: O(2.capacity)
    int knapSack_space_optimized(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<int> prev(capacity + 1, 0);
        vector<int> cur(capacity + 1, 0);

        // base cases
        for (int W = 0; W <= capacity; W++)
            prev[W] = (W / wt[0]) * val[0];

        for (int index = 1; index <= n - 1; index++)
        {
            for (int W = 0; W <= capacity; W++)
            {
                int not_take = 0 + prev[W];
                int take = INT_MIN;
                if (wt[index] <= W)
                    take = val[index] + cur[W - wt[index]];
                cur[W] = max(take, not_take);
            }
            prev = cur;
        }

        return prev[capacity];
    }

    // TC: O(N.capacity)
    // SC: O(N.capacity)
    int knapSack_tabu(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // base cases
        for (int W = 0; W <= capacity; W++)
            dp[0][W] = (W / wt[0]) * val[0];

        for (int index = 1; index <= n - 1; index++)
        {
            for (int W = 0; W <= capacity; W++)
            {
                int not_take = 0 + dp[index - 1][W];
                int take = INT_MIN;
                if (wt[index] <= W)
                    take = val[index] + dp[index][W - wt[index]];
                dp[index][W] = max(take, not_take);
            }
        }

        return dp[n - 1][capacity];
    }

    // TC: O(N.capacity)
    // SC: O(N.capacity) + O(capacity)
    int knapSack_memo(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return f(n - 1, capacity, val, wt, dp);
    }

private:
    int f(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            return (W / wt[0]) * val[0];
        }

        if (dp[index][W] != -1)
            return dp[index][W];

        int not_take = 0 + f(index - 1, W, val, wt, dp);
        int take = INT_MIN;
        if (wt[index] <= W)
            take = val[index] + f(index, W - wt[index], val, wt, dp);

        return dp[index][W] = max(take, not_take);
    }

    // Recursion
    // TC: (exponential)
    // SC: O(capacity)
};

int main()
{

    return 0;
}