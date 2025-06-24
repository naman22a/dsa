#include <iostream>
#include <vector>
using namespace std;

// Q1: Count Partitions With Given Difference
/*
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d.

https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
*/

class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        // s1 - s2 = d
        // s1 > s2
        // s1 = total - s2
        // total - s2 - s2 = d
        // s2 = (total - d)/2
        // count the number of subsets with target = (total - d)/2

        // edge cases
        // (total - d) >= 0
        // (total - d) has to be even

        int total = 0;
        for (int i = 0; i < arr.size(); i++)
            total += arr[i];

        if ((total - d) < 0 || (total - d) % 2 == 1)
            return 0;

        return perfectSum(arr, (total - d) / 2);
    }

    // TC: O(N.target)
    // SC: O(target)
    // space optimized
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