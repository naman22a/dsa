#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 416: Partition Equal Subset Sum
class Solution
{
public:
    // TC: O(N.target) + O(N)
    // SC: O(target)
    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        if (totalSum & 1)
            return false;

        int target = totalSum / 2;
        return isSubsetSum(nums, target);
    }

private:
    // TC: O(N.target)
    // SC: O(target)
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        vector<bool> cur(sum + 1, false);
        prev[0] = cur[0] = true;

        // base cases
        if (arr[0] < sum)
            prev[arr[0]] = true;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool not_take = prev[j];
                bool take = j >= arr[i] ? prev[j - arr[i]] : false;
                cur[j] = (not_take || take);
            }
            prev = cur;
        }

        return prev[sum];
    }
};

int main()
{

    return 0;
}