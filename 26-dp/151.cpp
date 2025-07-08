#include <iostream>
#include <vector>
using namespace std;

// Leetcode 123: Best Time to Buy and Sell Stock III
// similar to knapsack
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return maxProfit_space_optimization(prices);
    }

    // TC: O(N.2.3)
    // SC: O(2.3.2)
    int maxProfit_space_optimization(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int capacity = 1; capacity <= 2; capacity++)
                {
                    if (buy)
                        cur[buy][capacity] = max(-prices[i] + ahead[0][capacity], 0 + ahead[1][capacity]);
                    else
                        cur[buy][capacity] = max(prices[i] + ahead[1][capacity - 1], 0 + ahead[0][capacity]);
                }
            }
            ahead = cur;
        }

        return ahead[1][2];
    }

    // TC: O(N.2.3)
    // SC: O(N.2.3)
    int maxProfit_tabu(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // base cases
        /* for (int i = 0; i <= n - 1; i++)
        {
            for (int buy = 0; buy <= 1; buy++)
                dp[i][buy][0] = 0;
        }
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int capacity = 0; capacity <= 2; capacity++)
                dp[n][buy][capacity] = 0;
        } */

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int capacity = 1; capacity <= 2; capacity++)
                {
                    if (buy)
                        dp[i][buy][capacity] = max(-prices[i] + dp[i + 1][0][capacity], 0 + dp[i + 1][1][capacity]);
                    else
                        dp[i][buy][capacity] = max(prices[i] + dp[i + 1][1][capacity - 1], 0 + dp[i + 1][0][capacity]);
                }
            }
        }

        return dp[0][1][2];
    }

    // TC: O(N.2.3)
    // SC: O(N.2.3) + O(N)
    int maxProfit_memo(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }

private:
    // 3 changing params => 3D DP
    int f(int i, int buy, int capacity, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (capacity == 0)
            return 0;
        if (i == prices.size())
            return 0;

        if (dp[i][buy][capacity] != -1)
            return dp[i][buy][capacity];

        if (buy)
            return dp[i][buy][capacity] = max(-prices[i] + f(i + 1, 0, capacity, prices, dp), 0 + f(i + 1, 1, capacity, prices, dp));
        else
            return dp[i][buy][capacity] = max(prices[i] + f(i + 1, 1, capacity - 1, prices, dp), 0 + f(i + 1, 0, capacity, prices, dp));
    }

    // Recursion
    // TC: O(exponential)
    // SC: O(N)
};

int main()
{

    return 0;
}