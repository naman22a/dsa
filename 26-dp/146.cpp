#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1:
// Leetcode 115: Distinct Subsequences
class Solution
{
public:
    // TC: O(N.M)
    // SC: O(M)
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                    prev[j] = prev[j - 1] + prev[j];
                // else
                //     prev[j] = prev[j];
            }
        }

        return (int)prev[m];
    }

    // TC: O(N.M)
    // SC: O(2.M)
    int numDistinct_space_optimization(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m + 1, 0);
        vector<unsigned long long> cur(m + 1, 0);

        prev[0] = 1;
        cur[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    cur[j] = prev[j - 1] + prev[j];
                else
                    cur[j] = prev[j];
            }
            prev = cur;
        }

        return (int)prev[m];
    }

    // TC: O(N.M)
    // SC: O(N.M)
    int numDistinct_tabu(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // base cases
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return (int)dp[n][m];
    }

    // TC: O(N.M)
    // SC: O(N.M) + O(N + M)
    // shift to 1 based indexing
    int numDistinct_memo2(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }

private:
    int f2(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j == 0)
            return 1;
        if (i == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == t[j - 1])
            return dp[i][j] = f2(i - 1, j - 1, s, t, dp) + f2(i - 1, j, s, t, dp);
        else
            return dp[i][j] = f2(i - 1, j, s, t, dp);
    }

public:
    // TC: O(N.M)
    // SC: O(N.M) + O(N + M)
    int numDistinct_memo(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }

private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        else
            return dp[i][j] = f(i - 1, j, s, t, dp);
    }

    // TC: O(exponential)
    // SC: O(N + M)
};

int main()
{

    return 0;
}