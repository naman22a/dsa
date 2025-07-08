#include <iostream>
#include <vector>
using namespace std;

// Leetcode 122: Best Time to Buy and Sell Stock II
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return maxProfit_space_optimization(prices);
    }

    // TC: O(N.2)
    // SC: O(4)
    int maxProfit_space_optimization(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ahead(2, 0);
        vector<int> cur(2, 0);

        // base case
        ahead[0] = 0;
        ahead[1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                    profit = max(-prices[i] + ahead[0], 0 + ahead[1]);
                else
                    profit = max(prices[i] + ahead[1], 0 + ahead[0]);
                cur[canBuy] = profit;
            }
            ahead = cur;
        }

        return ahead[1];
    }

    // TC: O(N.2)
    // SC: O(N.2)
    int maxProfit_tabu(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // base case
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                else
                    profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                dp[i][canBuy] = profit;
            }
        }

        return dp[0][1];
    }

    // TC: O(N.2)
    // SC: O(N.2) + O(N)
    int maxProfit_memo(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, true, prices, dp);
    }

private:
    int f(int i, bool canBuy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i == prices.size())
            return 0;

        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];

        int profit = 0;
        if (canBuy)
        {
            profit = max(
                -prices[i] + f(i + 1, false, prices, dp), // take
                0 + f(i + 1, true, prices, dp));          // not take
        }
        else
        {
            profit = max(prices[i] + f(i + 1, true, prices, dp), // take
                         0 + f(i + 1, false, prices, dp));       // not take
        }
        return dp[i][canBuy] = profit;
    }

    // Recursion
    // TC: O(2^N)
    // SC: O(N)
};

int main()
{

    return 0;
}