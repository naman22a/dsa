#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1:
// Leetcode 72: Edit Distance
class Solution
{
public:
    // TC: O(N.M)
    // SC: O(2.M)
    int minDistance(string word1, string word2)
    {
        return minDistance_space_optimization(word1, word2);
    }

    // TC: O(N.M)
    // SC: O(2.M)
    int minDistance_space_optimization(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0);
        vector<int> cur(m + 1, 0);

        // base cases
        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for (int i = 1; i <= n; i++)
        {
            cur[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    cur[j] = 0 + prev[j - 1];
                else
                {
                    int insert_operation = 1 + cur[j - 1];
                    int delete_operation = 1 + prev[j];
                    int replace_operation = 1 + prev[j - 1];
                    cur[j] = min({insert_operation, delete_operation, replace_operation});
                }
            }
            prev = cur;
        }

        return prev[m];
    }

    // TC: O(N.M)
    // SC: O(N.M)
    int minDistance_tabu(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base cases
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                else
                {
                    int insert_operation = 1 + dp[i][j - 1];
                    int delete_operation = 1 + dp[i - 1][j];
                    int replace_operation = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min({insert_operation, delete_operation, replace_operation});
                }
            }
        }

        return dp[n][m];
    }

    // TC: O(N.M)
    // SC: O(N.M) + O(N + M)
    int minDistance_memo(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, word1, word2, dp);
    }

private:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (i == 0)
            return j;
        if (j == 0)
            return i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i - 1] == word2[j - 1])
            return dp[i][j] = 0 + f(i - 1, j - 1, word1, word2, dp);
        else
        {
            int insert_operation = 1 + f(i, j - 1, word1, word2, dp);
            int delete_operation = 1 + f(i - 1, j, word1, word2, dp);
            int replace_operation = 1 + f(i - 1, j - 1, word1, word2, dp);
            return dp[i][j] = min({insert_operation, delete_operation, replace_operation});
        }
    }

    // TC: O(exponential)
    // SC: O(N + M)
};

int main()
{

    return 0;
}