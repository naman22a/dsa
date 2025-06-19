#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 120: Triangle
class Solution
{
public:
    // TC: O(N^2)
    // SC: O(N)
    // space optimization
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> front(n, 0);
        vector<int> cur(n, 0);

        // base case
        for (int j = 0; j < n; j++)
            front[j] = triangle[n - 1][j];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j + 1];

                cur[j] = min(down, diagonal);
            }
            front = cur;
        }

        return front[0];
    }

    // TC: O(N(N+1)/2) ~ O(N^2)
    // SC: O(N(N+1)/2) ~ O(N^2)
    int minimumTotal_tabu(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // base case
        for (int j = 0; j < n; j++)
            dp[n - 1][j] = triangle[n - 1][j];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }

    // TC: O(N(N+1)/2) ~ O(N^2)
    // SC: O(N) + O(N(N+1)/2) ~ O(N) + O(N^2)
    int minimumTotal_memo(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, dp);
    }

private:
    int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        int n = triangle.size();
        if (i == n - 1)
            return triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle, dp);
        int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    // Recursion
    // TC: O(2^(N(N+1)/2))
    // SC: O(N)
};

int main()
{

    return 0;
}