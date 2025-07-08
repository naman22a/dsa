#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 673: Number of Longest Increasing Subsequence
class Solution
{
public:
    // TC: O(N^2)
    // SC: O(N)
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxi = 1;

        for (int i = 0; i <= n - 1; i++)
        {
            for (int prev = 0; prev <= i - 1; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    count[i] = count[prev];
                }
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i])
                {
                    count[i] += count[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
                ans += count[i];
        }
        return ans;
    }
};

int main()
{

    return 0;
}