#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 322: Coin Change
class Solution
{
public:
    // TC: O(N.amount)
    // SC: O(amount)
    // space optimization
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> cur(amount + 1, 0);

        // base case
        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
            else
                prev[target] = 1e9;
        }

        for (int index = 1; index <= n - 1; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int not_take = 0 + prev[target];
                int take = 1e9;
                if (coins[index] <= target)
                    take = 1 + cur[target - coins[index]];
                cur[target] = min(take, not_take);
            }

            prev = cur;
        }

        int result = prev[amount];
        return (result >= 1e9) ? -1 : result;
    }

    // TC: O(N.amount)
    // SC: O(N.amount)
    int coinChange_tabu(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // base case
        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            else
                dp[0][target] = 1e9;
        }

        for (int index = 1; index <= n - 1; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int not_take = 0 + dp[index - 1][target];
                int take = 1e9;
                if (coins[index] <= target)
                    take = 1 + dp[index][target - coins[index]];
                dp[index][target] = min(take, not_take);
            }
        }

        int result = dp[n - 1][amount];
        return (result >= 1e9) ? -1 : result;
    }

    // TC: O(N.amount)
    // SC: O(N.amount) + O(amount)
    int coinChange_memo(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = f(n - 1, amount, coins, dp);
        return (result >= 1e9) ? -1 : result;
    }

private:
    int f(int index, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target % coins[index] == 0)
                return target / coins[index];
            return 1e9;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        int not_take = 0 + f(index - 1, target, coins, dp);
        int take = 1e9;
        if (coins[index] <= target)
            take = 1 + f(index, target - coins[index], coins, dp);

        return dp[index][target] = min(take, not_take);
    }

    // Recursion
    // TC: O(exponential) (not O(2^N))
    // SC: O(target) (not O(N))
};

int main()
{

    return 0;
}