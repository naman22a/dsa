#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1:
// Leetcode 583: Delete Operation for Two Strings

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int deletions = n - longestCommonSubsequence(word1, word2);
        int insertions = m - longestCommonSubsequence(word1, word2);
        return deletions + insertions;
    }

private:
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