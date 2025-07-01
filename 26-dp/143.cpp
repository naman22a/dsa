#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Q1:
// Leetcode 1312: Minimum Insertion Steps to Make a String Palindrome
class Solution
{
public:
    int minInsertions(string s)
    {
        return s.size() - longestPalindromeSubseq(s);
    }

private:
    int longestPalindromeSubseq(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return longestCommonSubsequence(s, rev);
    }

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
};

int main()
{

    return 0;
}