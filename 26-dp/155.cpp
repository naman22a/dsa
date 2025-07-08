#include <iostream>
#include <vector>
using namespace std;

// Leetcode 300: Longest Increasing Subsequence
class Solution
{
public:
    // TC: O(N^2)
    // SC: O(N)
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        for (int i = 0; i <= n - 1; i++)
        {
            for (int prev = 0; prev <= i - 1; prev++)
            {
                if (nums[prev] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[prev]);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }

    // TC: O(N.N)
    // SC: O(N.2)
    int lengthOfLIS_space_optimization(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> next(n + 1, 0);
        vector<int> cur(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev_index = index - 1; prev_index >= -1; prev_index--)
            {
                int length = 0 + next[prev_index + 1];
                if (prev_index == -1 || nums[index] > nums[prev_index])
                    length = max(length, 1 + next[index + 1]);

                cur[prev_index + 1] = length;
            }
            next = cur;
        }

        return cur[0];
    }

    // TC: O(N.N)
    // SC: O(N.N)
    int lengthOfLIS_tabu(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev_index = index - 1; prev_index >= -1; prev_index--)
            {
                int length = 0 + dp[index + 1][prev_index + 1];
                if (prev_index == -1 || nums[index] > nums[prev_index])
                    length = max(length, 1 + dp[index + 1][index + 1]);

                dp[index][prev_index + 1] = length;
            }
        }

        // return dp[0][-1 + 1];
        return dp[0][0];
    }

    // TC: O(N.N)
    // SC: O(N.N) + O(N)
    int lengthOfLIS_memo(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }

private:
    int f(int index, int prev_index, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index == nums.size())
            return 0;

        if (dp[index][prev_index + 1] != -1)
            return dp[index][prev_index + 1];

        int length = 0 + f(index + 1, prev_index, nums, dp);
        if (prev_index == -1 || nums[index] > nums[prev_index])
            length = max(length, 1 + f(index + 1, index, nums, dp));

        return dp[index][prev_index + 1] = length;
    }

    // Recursion
    // TC: O(2^N)
    // SC: O(N)
};

int main()
{

    return 0;
}