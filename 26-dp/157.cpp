#include <iostream>
#include <vector>
using namespace std;

// Q1: Longest Increasing Subsequence using Binary Search
class Solution
{
public:
    // TC: O(N.log(N))
    // SC: O(N)
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> temp;
        temp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }

        return temp.size();
    }
};

int main()
{

    return 0;
}