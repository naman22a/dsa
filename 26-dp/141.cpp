#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1: Longest Common Substring
/*
You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

class Solution
{
public:
    // TC: O(N.M)
    // SC: O(2.M)
    // space optimization
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m + 1, 0);
        vector<int> cur(m + 1, 0);

        // no need for base casse as already initialized with zeroes
        // base case
        for (int j = 0; j <= m - 1; j++)
            prev[j] = 0;

        int ans = 0;
        for (int index1 = 1; index1 <= n; index1++)
        {
            for (int index2 = 1; index2 <= m; index2++)
            {
                if (s1[index1 - 1] == s2[index2 - 1])
                {
                    cur[index2] = 1 + prev[index2 - 1];
                    ans = max(ans, cur[index2]);
                }
                else
                    cur[index2] = 0;
            }
            prev = cur;
        }

        return ans;
    }
};

int main()
{

    return 0;
}