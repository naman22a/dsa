#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// Q1:
// Leetcode 132: Palindrome Partitioning II
class Solution
{
public:
    int minCut(string s)
    {
        return minCut_tabu(s);
    }

    // TC: O(N^2)
    // SC: O(N)
    int minCut_tabu(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // base case

        for (int i = n - 1; i >= 0; i--)
        {
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }

    // TC: O(N^2)
    // SC: O(N) + O(N)
    int minCut_memo(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp) - 1;
    }

private:
    int f(int i, string &s, vector<int> &dp)
    {
        int n = s.size();
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + f(j + 1, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

    bool isPalindrome(int i, int j, string &s)
    {
        int left = i, right = j;
        while (left <= right)
        {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}