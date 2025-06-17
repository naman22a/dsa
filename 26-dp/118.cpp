#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Q1: Frog Jump with K Jumps

A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.
To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances
*/

class Solution
{
public:
    // no need for space optimization
    int minCost(vector<int> &height, int k)
    {
    }

    int minCost_tabulation(vector<int> &height, int k)
    {
        int n = height.size();
        vector<int> dp(n, -1);

        dp[0] = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            // int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            // int right = i > 1 ? dp[i - 2] + abs(height[i] - height[i - 2]) : INT_MAX;
            // dp[i] = min(left, right);

            int minsteps = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i - j] + abs(height[i] - height[i - j]);
                    minsteps = min(minsteps, jump);
                }
            }
            dp[i] = minsteps;
        }

        return dp[n - 1];
    }

    int minCost_memoization(vector<int> &height, int k)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        return f(n - 1, height, dp, k);
    }

private:
    int f(int index, vector<int> &height, vector<int> &dp, int k)
    {
        if (index == 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // int left = f(index - 1, height, dp) + abs(height[index] - height[index - 1]);
        // int right = index > 1 ? f(index - 2, height, dp) + abs(height[index] - height[index - 2]) : INT_MAX;
        // return dp[index] = min(left, right);

        int minsteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (index - j >= 0)
            {
                int jump = f(index - j, height, dp, k) + abs(height[index] - height[index - j]);
                minsteps = min(minsteps, jump);
            }
        }
        return dp[index] = minsteps;
    }
};

int main()
{

    return 0;
}
