#include <iostream>
#include <vector>
using namespace std;

// TC: O(N + M)
// SC: O(1)
void f1(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        // some O(1) code
    }
    for (int i = 0; i < m; i++)
    {
        // some O(1) code
    }
}

// TC: O(N * M)
// SC: O(1)
void f2(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            // some O(1) code
        }
    }
}

// TC: O(N * N) -> O(N^2)
// SC: O(N) -> vector data structure used
void f3(int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            // some O(1) code
        }
    }
}

int main()
{

    return 0;
}