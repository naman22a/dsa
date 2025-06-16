#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// recursion
// TC: O(2^N)
// SC: O(N)
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// memoization
int solve(int n, unordered_map<int, int> &dp)
{
    if (n <= 1)
        return n;

    if (dp.find(n) != dp.end())
        return dp[n];

    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}

// TC: O(N)
// SC: O(N) + O(N)
int fib_memo_with_hashmap(int n)
{
    unordered_map<int, int> dp;
    return solve(n, dp);
}

int solve2(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = solve2(n - 1, dp) + solve2(n - 2, dp);
    return dp[n];
}

// TC: O(N)
// SC: O(N) + O(N)
int fib_memo_with_hashtable(int n)
{
    vector<int> dp(n + 1, -1);
    return solve2(n, dp);
}

// tabulation

// TC: O(N)
// SC: O(N)
int fib_tabulation(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// space optimization

// TC: O(N)
// SC: O(1)
int fib_space_optimization(int n)
{
    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int main()
{

    // fibonacci series
    // 0 1 1 2 3 5 8 13 21
    // 0 1 2 3 4 5 6 7  8  (indices)
    cout << fib(8) << endl;
    cout << fib_memo_with_hashmap(8) << endl;
    cout << fib_memo_with_hashtable(8) << endl;
    cout << fib_tabulation(8) << endl;

    return 0;
}