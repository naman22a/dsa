#include <iostream>
#include <vector>
using namespace std;

// Q1: Counts Subsets with Sum K
/*
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/

class Solution
{
public:
    // TC: O(N.target)
    // SC: O(target)
    // space optimized
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> prev(target + 1, 0);
        vector<int> cur(target + 1, 0);

        // base cases
        if (arr[0] == 0)
            prev[0] = 2; // pick or not pick
        else
            prev[0] = 1; // not pick

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1; // pick if within range

        for (int index = 1; index <= n - 1; index++)
        {
            cur[0] = (arr[index] == 0) ? 2 * prev[0] : prev[0];

            for (int sum = 0; sum <= target; sum++)
            {
                int not_pick = prev[sum];
                int pick = 0;
                if (arr[index] <= sum)
                    pick = prev[sum - arr[index]];

                cur[sum] = pick + not_pick;
            }
            prev = cur;
        }

        return prev[target];
    }

    // TC: O(N.target)
    // SC: O(N.target)
    int perfectSum_tabu(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // base cases
        if (arr[0] == 0)
            dp[0][0] = 2; // pick or not pick
        else
            dp[0][0] = 1; // not pick

        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1; // pick if within range

        for (int index = 1; index <= n - 1; index++)
        {
            for (int sum = 0; sum <= target; sum++)
            {
                int not_pick = dp[index - 1][sum];
                int pick = 0;
                if (arr[index] <= sum)
                    pick = dp[index - 1][sum - arr[index]];

                dp[index][sum] = pick + not_pick;
            }
        }

        return dp[n - 1][target];
    }

    // TC: O(N.target)
    // SC: O(N.target) + O(N)
    int perfectSum_memo(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, arr, dp);
    }

private:
    int f(int index, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (sum == 0 && arr[0] == 0)
                return 2; // include or exclude 0
            if (sum == 0 || sum == arr[0])
                return 1;
            return 0;
        }

        if (dp[index][sum] != -1)
            return dp[index][sum];

        int not_pick = f(index - 1, sum, arr, dp);
        int pick = 0;
        if (arr[index] <= sum)
            pick = f(index - 1, sum - arr[index], arr, dp);

        return dp[index][sum] = pick + not_pick;
    }

    // recursion
    // TC: O(2^N)
    // SC: O(N)
};

int main()
{

    return 0;
}