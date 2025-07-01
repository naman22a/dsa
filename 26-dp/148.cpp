#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1:
// Leetcode 44: Wildcard Matching
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return isMatch_space_optimization(s, p);
    }

    // TC: O(N.M)
    // SC: O(2.M)
    bool isMatch_space_optimization(string s, string p)
    {
        int n = p.size();
        int m = s.size();
        // vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);

        // base cases
        prev[0] = true;
        for (int j = 1; j <= m; j++)
            prev[j] = false;

        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            // for every row you are assigning the (0th)first column's value
            cur[0] = flag;

            // cur is current row's column
            // and that cur's 0th row has to be assigned everytime

            for (int j = 1; j <= m; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    cur[j] = prev[j - 1];
                else if (p[i - 1] == '*')
                    cur[j] = prev[j] || cur[j - 1];
                else
                    cur[j] = false;
            }
            prev = cur;
        }

        return prev[m];
    }

    // TC: O(N.M)
    // SC: O(N.M)
    bool isMatch_tabu(string s, string p)
    {
        int n = p.size();
        int m = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base cases
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
            dp[0][j] = false;
        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }

    // TC: O(N.M)
    // SC: O(N.M) + O(N + M)
    // 1 based indexing
    bool isMatch_memo(string s, string p)
    {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, p, s, dp);
    }

private:
    // s1 -> pattern
    // s2 -> string to be matched
    bool f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return true;
        if (i == 0 && j > 0)
            return false;

        if (j == 0 && i > 0)
        {
            for (int k = 1; k <= i; k++)
            {
                if (s1[k - 1] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        else if (s1[i - 1] == '*')
            return dp[i][j] = f(i - 1, j, s1, s2, dp) || f(i, j - 1, s1, s2, dp);
        else
            return dp[i][j] = false;
    }

    // TC: O(exponential)
    // SC: O(N + M)
};

int main()
{

    return 0;
}