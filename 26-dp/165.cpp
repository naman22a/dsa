#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Q1:
// Leetcode 312: Burst Balloons
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        return maxCoins_tabu(nums);
    }

    // TC: O(N^3)
    // SC: O(N^2)
    int maxCoins_tabu(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;

                int maxi = INT_MIN;
                for (int index = i; index <= j; index++)
                {
                    int cost = nums[i - 1] * nums[index] * nums[j + 1] + dp[i][index - 1] + dp[index + 1][j];
                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }

    // TC: O(N^3)
    // SC: O(N^2) + O(N)
    int maxCoins_memo(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(1, n, nums, dp);
    }

private:
    // i => left
    // j => right
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;
        for (int index = i; index <= j; index++)
        {
            int cost = nums[i - 1] * nums[index] * nums[j + 1] + f(i, index - 1, nums, dp) + f(index + 1, j, nums, dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    // Recursion
    // TC: O(exponential)
    // SC: O(N)
};

int main()
{

    return 0;
}