#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Q1:
// Leetcode 1547: Minimum Cost to Cut a Stick
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        return minCost_tabu(n, cuts);
    }

    int minCost_tabu(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--)
        {
            for (int j = 1; j <= c; j++)
            {
                if (i > j)
                    continue;

                int mini = INT_MAX;
                for (int index = i; index <= j; index++)
                {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][index - 1] + dp[index + 1][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }

    // TC: O(C^3)
    // SC: O(C^2) + O(stack space)
    int minCost_memo(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return f(1, c, cuts, dp);
    }

private:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        for (int index = i; index <= j; index++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + f(i, index - 1, cuts, dp) + f(index + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    // Recursion
    // TC: O(exponential)
    // SC: O(stack space)
};

int main()
{

    return 0;
}