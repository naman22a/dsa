#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 494: Target Sum
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return countPartitions(nums, target);
    }

private:
    int countPartitions(vector<int> &arr, int d)
    {
        int total = 0;
        for (int i = 0; i < arr.size(); i++)
            total += arr[i];

        if ((total - d) < 0 || (total - d) % 2 == 1)
            return 0;

        return perfectSum(arr, (total - d) / 2);
    }

    // TC: O(N.target)
    // SC: O(target)
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> prev(target + 1, 0);
        vector<int> cur(target + 1, 0);

        // base cases
        if (arr[0] == 0)
            prev[0] = 2; // pick or not pick
        else
            prev[0] = 1; // not pick

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1; // pick if within range

        for (int index = 1; index <= n - 1; index++)
        {
            cur[0] = (arr[index] == 0) ? 2 * prev[0] : prev[0];

            for (int sum = 0; sum <= target; sum++)
            {
                int not_pick = prev[sum];
                int pick = 0;
                if (arr[index] <= sum)
                    pick = prev[sum - arr[index]];

                cur[sum] = pick + not_pick;
            }
            prev = cur;
        }

        return prev[target];
    }
};

int main()
{

    return 0;
}