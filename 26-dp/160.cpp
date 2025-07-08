#include <iostream>
#include <vector>
using namespace std;

// Q1: Longest Bitonic Subsequence

class Solution
{
public:
    // TC: O(N^2 + N^2 + N)
    // SC: O(N)
    int longestBitonicSequence(vector<int> &arr, int n)
    {
        // LIS
        vector<int> front(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int prev_index = 0; prev_index < i; prev_index++)
            {
                if (arr[prev_index] < arr[i])
                    front[i] = max(front[i], 1 + front[prev_index]);
            }
        }

        // LDS
        vector<int> back(n, 1);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev_index = n - 1; prev_index > i; prev_index--)
            {
                if (arr[prev_index] < arr[i])
                    back[i] = max(back[i], 1 + back[prev_index]);
            }
        }

        int maxi = -1;

        for (int i = 0; i < n; i++)
            maxi = max(maxi, front[i] + back[i] - 1);

        return maxi;
    }
};

int main()
{

    return 0;
}