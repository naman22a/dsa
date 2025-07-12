#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 1277: Count Square Submatrices with All Ones
class Solution
{
public:
    // TC: O(N.M)
    // SC: O(N.M)
    int countSquares(vector<vector<int>> &matrix)
    {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<int>> dp(ROWS, vector<int>(COLS, 0));

        for (int j = 0; j < COLS; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 0; i < ROWS; i++)
            dp[i][0] = matrix[i][0];

        for (int i = 1; i < ROWS; i++)
        {
            for (int j = 1; j < COLS; j++)
            {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
        }

        int sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
                sum += dp[i][j];
        }
        return sum;
    }
};

int main()
{

    return 0;
}