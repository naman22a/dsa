#include <iostream>
#include <vector>
using namespace std;

// Leetcode 188: Best Time to Buy and Sell Stock IV
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        return maxProfit_space_optimization(k, prices);
    }

    // TC: O(N.2.K)
    // SC: O(2.K)
    int maxProfit_space_optimization(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ahead(2 * k + 1, 0);
        vector<int> cur(2 * k + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
            {
                // buy
                if (transaction % 2 == 0)
                    cur[transaction] = max(
                        -prices[index] + ahead[transaction + 1],
                        0 + ahead[transaction]);
                // sell
                else
                    cur[transaction] = max(
                        prices[index] + ahead[transaction + 1],
                        0 + ahead[transaction]);
            }
            ahead = cur;
        }

        return ahead[0];
    }

    int maxProfit_tabu(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
            {
                // buy
                if (transaction % 2 == 0)
                    dp[index][transaction] = max(
                        -prices[index] + dp[index + 1][transaction + 1],
                        0 + dp[index + 1][transaction]);
                // sell
                else
                    dp[index][transaction] = max(
                        prices[index] + dp[index + 1][transaction + 1],
                        0 + dp[index + 1][transaction]);
            }
        }

        return dp[0][0];
    }

    int maxProfit_memo(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return f(0, 0, k, prices, dp);
    }

    int f(int index, int transaction, int k, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size() || transaction == 2 * k)
            return 0;

        if (dp[index][transaction] != -1)
            return dp[index][transaction];

        // buy
        if (transaction % 2 == 0)
            return dp[index][transaction] = max(
                       -prices[index] + f(index + 1, transaction + 1, k, prices, dp),
                       0 + f(index + 1, transaction, k, prices, dp));
        // sell
        else
            return dp[index][transaction] = max(
                       prices[index] + f(index + 1, transaction + 1, k, prices, dp),
                       0 + f(index + 1, transaction, k, prices, dp));
    }

    int maxProfit_alt(int k, vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int capacity = 1; capacity <= k; capacity++)
                {
                    if (buy)
                        cur[buy][capacity] = max(-prices[i] + ahead[0][capacity], 0 + ahead[1][capacity]);
                    else
                        cur[buy][capacity] = max(prices[i] + ahead[1][capacity - 1], 0 + ahead[0][capacity]);
                }
            }
            ahead = cur;
        }

        return ahead[1][k];
    }
};

int main()
{

    return 0;
}