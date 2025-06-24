#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 518: Coin Change II
class Solution
{
public:
    // TC: O(N.amount)
    // SC: O(amount)
    // space optimization
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<long long> prev(amount + 1, 0);
        vector<long long> cur(amount + 1, 0);

        // base case
        for (int target = 0; target <= amount; target++)
            prev[target] = target % coins[0] == 0;

        for (int index = 1; index <= n - 1; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                long long not_take = prev[target];
                long long take = 0;
                if (coins[index] <= target)
                    take = prev[target - coins[index]];
                cur[target] = take + not_take;
            }

            prev = cur;
        }

        return prev[amount];
    }

    // TC: O(N.amount)
    // SC: O(N.amount)
    int change_tabu(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

        // base case
        for (int target = 0; target <= amount; target++)
            dp[0][target] = target % coins[0] == 0;

        for (int index = 1; index <= n - 1; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                long long not_take = dp[index - 1][target];
                long long take = 0;
                if (coins[index] <= target)
                    take = dp[index][target - coins[index]];
                dp[index][target] = take + not_take;
            }
        }

        return dp[n - 1][amount];
    }

    // TC: O(N.amount)
    // SC: O(N.amount) + O(amount)
    int change_memo(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }

private:
    long long f(int index, int target, vector<int> &coins, vector<vector<long long>> &dp)
    {
        if (index == 0)
            return target % coins[0] == 0;

        if (dp[index][target] != -1)
            return dp[index][target];

        long long not_take = f(index - 1, target, coins, dp);
        long long take = 0;
        if (coins[index] <= target)
            take = f(index, target - coins[index], coins, dp);
        return dp[index][target] = take + not_take;
    }

    // Recursion
    // TC: (exponential)
    // SC: O(amount)
};

int main()
{

    return 0;
}