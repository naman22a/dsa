#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Leetcode 368: Largest Divisible Subset
class Solution
{
public:
    // TC: O(N^2 + N)
    // SC: O(N)
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int last_index = 0;

        sort(nums.begin(), nums.end());

        int maxi = 1;
        for (int i = 0; i <= n - 1; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev <= i - 1; prev++)
            {
                // small change in this line here
                // same as print LIS
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                last_index = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[last_index]);

        int i = 1;
        while (hash[last_index] != last_index)
        {
            last_index = hash[last_index];
            temp.push_back(nums[last_index]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

int main()
{

    return 0;
}