#include <iostream>
#include <vector>
using namespace std;

// Q1: Subset Sum Equals to K(Target)
/*
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum.

https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

class Solution
{
public:
    // TC: O(N.target)
    // SC: O(target)
    // space optimization
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        vector<bool> cur(sum + 1, false);
        prev[0] = cur[0] = true;

        // base cases
        prev[arr[0]] = true;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool not_take = prev[j];
                bool take = j >= arr[i] ? prev[j - arr[i]] : false;
                cur[j] = (not_take || take);
            }
            prev = cur;
        }

        return prev[sum];
    }

    // TC: O(N.target)
    // SC: O(N.target)
    bool isSubsetSum_tabu(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // base cases
        for (int i = 0; i <= n - 1; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool not_take = dp[i - 1][j];
                bool take = j >= arr[i] ? dp[i - 1][j - arr[i]] : false;
                dp[i][j] = (not_take || take);
            }
        }

        return dp[n - 1][sum];
    }

    // TC: O(N.target)
    // SC: O(N.target) + O(N)
    bool isSubsetSum_memo(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }

private:
    bool f(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (index == 0)
            return arr[index] == target;

        if (dp[index][target] != -1)
            return dp[index][target];

        bool not_take = f(index - 1, target, arr, dp);
        bool take = target >= arr[index] ? f(index - 1, target - arr[index], arr, dp) : false;

        return dp[index][target] = (not_take || take);
    }

    // Recursion
    // TC: O(2^N)
    // SC: O(N)
};

int main()
{

    return 0;
}