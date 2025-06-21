#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 2035: Partition Array Into Two Arrays to Minimize Sum Difference

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(nums.begin(), nums.end());
        int totalSum = 0;

        for (int i = 0; i < n; i++)
            totalSum += arr[i];

        vector<bool> prev(totalSum + 1, false);
        prev[0] = true;

        if (arr[0] <= totalSum)
            prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            vector<bool> cur(totalSum + 1, false);
            cur[0] = true;

            for (int target = 1; target <= totalSum; target++)
            {
                bool notTaken = prev[target];
                bool taken = false;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];

                cur[target] = notTaken || taken;
            }

            prev = cur;
        }

        int mini = 1e9;
        for (int i = 0; i <= totalSum; i++)
        {
            if (prev[i] == true)
            {
                int diff = abs(i - (totalSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};

int main()
{

    return 0;
}