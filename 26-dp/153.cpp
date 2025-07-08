#include <iostream>
#include <vector>
using namespace std;

// Leetcode 309: Best Time to Buy and Sell Stock with Cooldown
class Solution
{
public:
    // TC: O(N)
    // SC: O(6)
    // space optimization
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> cur(2, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            cur[1] = max(
                -prices[index] + front1[0],
                0 + front1[1]);
            cur[0] = max(prices[index] + front2[1], 0 + front1[0]);

            front2 = front1;
            front1 = cur;
        }

        return cur[1];
    }

    int maxProfit_tabu(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                    dp[index][buy] = max(
                        -prices[index] + dp[index + 1][0],
                        0 + dp[index + 1][1]);
                else
                    dp[index][buy] = max(prices[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
            }
        }

        return dp[0][1];
    }

    int maxProfit_memo(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }

private:
    int f(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        if (buy)
            return dp[index][buy] = max(
                       -prices[index] + f(index + 1, 0, prices, dp),
                       0 + f(index + 1, 1, prices, dp));
        else
            return dp[index][buy] = max(prices[index] + f(index + 2, 1, prices, dp), 0 + f(index + 1, 0, prices, dp));
    }
};

int main()
{

    return 0;
}