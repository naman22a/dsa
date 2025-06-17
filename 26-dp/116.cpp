#include <iostream>
using namespace std;

class Solution
{
public:
    // TC: O(N)
    // SC: O(1)
    int climbStairs(int n)
    {
        if (n <= 1)
            return n;

        int first = 1;
        int second = 1;

        for (int i = 2; i <= n; i++)
        {
            int next = first + second;
            first = second;
            second = next;
        }

        return second;
    }

    // alternative methods
    // - matrix exponentiation -> O(log(N))
    // - Binet's Formula -> O(1)
};

int main()
{

    return 0;
}