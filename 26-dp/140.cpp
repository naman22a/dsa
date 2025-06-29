#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Q1: Print Longest Common Subsequence

// TC: O(N.M) + O(N + M)
// SC: O(N.M)
string lcs(string text1, string text2)
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

    int length = dp[n][m];
    int index = length - 1;
    string s = "";
    for (int i = 0; i < length; i++)
        s += '$';

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            s[index] = text1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i = i - 1;
        }
        else
        {
            j = j - 1;
        }
    }

    return s;
}

int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";

    cout << "The Longest Common Subsequence is " << lcs(s1, s2);

    return 0;
}