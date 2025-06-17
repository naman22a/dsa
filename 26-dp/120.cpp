#include <iostream>
#include <vector>
using namespace std;

// Q1
// Leetcode 213: House Robber II

class Solution
{
private:
    int house_robber(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += prev2;

            int not_take = 0 + prev;
            int cur = max(take, not_take);
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        return max(house_robber(temp1), house_robber(temp2));
    }
};

int main()
{

    return 0;
}