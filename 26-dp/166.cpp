#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1: Evaluate Boolean Expression to True
// https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

class Solution
{
public:
    int countWays(string &s)
    {
        return countWays_memo(s);
    }

    int countWays_memo(string &s)
    {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return f(0, n - 1, 1, s, dp);
    }

private:
    int f(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;

        if (i == j)
        {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        int ways = 0;

        for (int index = i + 1; index <= j - 1; index += 2)
        {
            int left_true = f(i, index - 1, 1, s, dp);
            int left_false = f(i, index - 1, 0, s, dp);
            int right_true = f(index + 1, j, 1, s, dp);
            int right_false = f(index + 1, j, 0, s, dp);

            if (s[index] == '&')
            {
                if (isTrue)
                {
                    ways += left_true * right_true;
                }
                else
                {
                    ways += (left_true * right_false) + (left_false * right_true) + (left_false * right_false);
                }
            }
            else if (s[index] == '|')
            {
                if (isTrue)
                {
                    ways += (left_true * right_true) + (left_true * right_false) + (left_false * right_true);
                }
                else
                {
                    ways += right_false * left_false;
                }
            }
            // XOR
            else
            {
                if (isTrue)
                    ways += (left_false * right_true) + (left_true * right_false);
                else
                    ways += (left_false * right_false) + (left_true * right_true);
            }
        }

        return dp[i][j][isTrue] = ways;
    }

    // Recursion
    // TC: O(exponential)
    // SC: O(stack space)
};

int main()
{

    return 0;
}