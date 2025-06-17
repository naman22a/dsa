#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Q1: Frog Jump
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

https://www.geeksforgeeks.org/problems/geek-jump/1
*/

class Solution
{
public:
    // space optimization
    int minCost(vector<int> &height)
    {
        int n = height.size();
        int prev = 0;
        int prev2 = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            int left = prev + abs(height[i] - height[i - 1]);
            int right = i > 1 ? prev2 + abs(height[i] - height[i - 2]) : INT_MAX;
            int curi = min(left, right);
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }

    int minCost_tabulation(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1);

        dp[0] = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            int right = i > 1 ? dp[i - 2] + abs(height[i] - height[i - 2]) : INT_MAX;
            dp[i] = min(left, right);
        }

        return dp[n - 1];
    }

    int minCost_memoization(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1);
        return f(n - 1, height, dp);
    }

private:
    int f(int index, vector<int> &height, vector<int> &dp)
    {
        if (index == 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int left = f(index - 1, height, dp) + abs(height[index] - height[index - 1]);
        int right = index > 1 ? f(index - 2, height, dp) + abs(height[index] - height[index - 2]) : INT_MAX;

        return dp[index] = min(left, right);
    }
};

int main()
{

    return 0;
}