#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Q1:
// Leetcode 1143: Longest Common Subsequence
class Solution
{
public:
    // TC: O(N.M)
    // SC: O(2.M)
    // space optimization
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0);
        vector<int> cur(m + 1, 0);

        // base case
        for (int j = 0; j <= m - 1; j++)
            prev[j] = 0;

        for (int index1 = 1; index1 <= n; index1++)
        {
            for (int index2 = 1; index2 <= m; index2++)
            {
                if (text1[index1 - 1] == text2[index2 - 1])
                    cur[index2] = 1 + prev[index2 - 1];
                else
                    cur[index2] = 0 + max(prev[index2], cur[index2 - 1]);
            }
            prev = cur;
        }

        return prev[m];
    }

    // TC: O(N.M)
    // SC: O(N.M)
    int longestCommonSubsequence_tabu(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base case
        for (int j = 0; j <= m - 1; j++)
            dp[0][j] = 0;
        for (int i = 0; i <= n - 1; i++)
            dp[i][0] = 0;

        for (int index1 = 1; index1 <= n; index1++)
        {
            for (int index2 = 1; index2 <= m; index2++)
            {
                if (text1[index1 - 1] == text2[index2 - 1])
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                else
                    dp[index1][index2] = 0 + max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }

        return dp[n][m];
    }

    // TC: O(N.M)
    // SC: O(N.M) + O(N + M)
    int longestCommonSubsequence_memo_with_index_shifting(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f2(n, m, text1, text2, dp);
    }

private:
    int f2(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (index1 == 0 || index2 == 0)
            return 0;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (text1[index1 - 1] == text2[index2 - 1])
            return dp[index1][index2] = 1 + f2(index1 - 1, index2 - 1, text1, text2, dp);

        return dp[index1][index2] = 0 + max(f2(index1 - 1, index2, text1, text2, dp),
                                            f2(index1, index2 - 1, text1, text2, dp));
    }

public:
    // TC: O(N.M)
    // SC: O(N.M) + O(N + M)
    int longestCommonSubsequence_memo(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, text1, text2, dp);
    }

private:
    int f(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (index1 < 0 || index2 < 0)
            return 0;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (text1[index1] == text2[index2])
            return dp[index1][index2] = 1 + f(index1 - 1, index2 - 1, text1, text2, dp);

        return dp[index1][index2] = 0 + max(f(index1 - 1, index2, text1, text2, dp),
                                            f(index1, index2 - 1, text1, text2, dp));
    }

    // Recursion
    // TC: O(O(2^(N + M))), n is length of text1, m is length of text2
    // SC: O(N + M)
};

int main()
{

    return 0;
}