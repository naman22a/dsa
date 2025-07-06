#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(1)
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};

int main()
{

    return 0;
}