#include <iostream>
#include <vector>
using namespace std;

// Q1: Maximum Sum of Non-Adjacent Elements
// Leetcode 198: House Robber

class Solution
{
public:
    // space optimization
    // TC: O(N)
    // SC: O(1)
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += prev2;

            int not_take = 0 + prev;
            int cur = max(take, not_take);
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

    // TC: O(N)
    // SC: O(N)
    int rob_tabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];

        for (int i = 1; i <= n - 1; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += dp[i - 2];
            int not_take = 0 + dp[i - 1];
            dp[i] = max(take, not_take);
        }

        return dp[n - 1];
    }

    // TC: O(N)
    // SC: O(N + N)
    int rob_memoization(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, nums, dp);
    }

private:
    int f(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index == 0)
            return nums[index];

        if (index < 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int pick = nums[index] + f(index - 2, nums, dp);
        int not_pick = 0 + f(index - 1, nums, dp);

        return dp[index] = max(pick, not_pick);
    }

    // recursion
    // TC: O(2^N)
    // SC: O(N)
};

int main()
{

    return 0;
}