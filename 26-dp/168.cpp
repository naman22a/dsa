#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Q1:
// Leetcode 1043: Partition Array for Maximum Sum
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        return maxSumAfterPartitioning_tabu(arr, k);
    }

    // TC: O(N.K)
    // SC: O(N)
    int maxSumAfterPartitioning_tabu(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        // base case
        dp[n] = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            int length = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            for (int j = index; j < min(n, index + k); j++)
            {
                length++;
                maxi = max(maxi, arr[j]);
                int sum = length * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[index] = maxAns;
        }

        return dp[0];
    }

    // TC: O(N.K)
    // SC: O(N) + O(N)
    int maxSumAfterPartitioning_memo(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, arr, k, dp);
    }

private:
    int f(int index, vector<int> &arr, int k, vector<int> &dp)
    {
        int n = arr.size();
        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int length = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = index; j < min(n, index + k); j++)
        {
            length++;
            maxi = max(maxi, arr[j]);
            int sum = length * maxi + f(j + 1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[index] = maxAns;
    }

    // Recursion
    // TC: O(exponential)
    // SC: O(stack space)
};

int main()
{

    return 0;
}