#include <iostream>
#include <vector>
using namespace std;

// Leetcode 714: Best Time to Buy and Sell Stock with Transaction Fee
class Solution
{
public:
    // TC: O(N.2)
    // SC: O(4)
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> ahead(2, 0);
        vector<int> cur(2, 0);

        // base case
        ahead[0] = 0;
        ahead[1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                    profit = max(-prices[i] + ahead[0], 0 + ahead[1]);
                else
                    profit = max(prices[i] - fee + ahead[1], 0 + ahead[0]);
                cur[canBuy] = profit;
            }
            ahead = cur;
        }

        return ahead[1];
    }
};

int main()
{

    return 0;
}