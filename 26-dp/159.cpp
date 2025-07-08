#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Leetcode 1048: Longest String Chain

bool cmp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

class Solution
{
public:
    // TC: O((N^2).L + N.log(N)), L -> length of string
    // SC: O(N)
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        for (int i = 0; i <= n - 1; i++)
        {
            for (int prev = 0; prev <= i - 1; prev++)
            {
                if (checkPossible(words[i], words[prev]) && 1 + dp[prev] > dp[i])
                    dp[i] = 1 + dp[prev];
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }

private:
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;

        int first = 0, second = 0;
        while (first < s1.length())
        {
            if (s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
                first++;
        }

        if (first == s1.size() && second == s2.size())
            return true;
        return false;
    }
};

int main()
{

    return 0;
}