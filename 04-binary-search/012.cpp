#include <iostream>
using namespace std;

// TC: O(log(N)), here log is of base 2
// SC: O(1)
int binary_search(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        // *NOTE: declaring mid inside for loop does not require extra memory space(O(N)), as it optimized automatically by the compiler
        // int mid = (left + right) / 2; // do not use, it causes integer overflow
        int mid = left + (right - left) / 2; // to avoid integer overflow

        // element found
        if (arr[mid] == target)
            return mid;
        // search in the right half
        else if (arr[mid] < target)
            left = mid + 1;
        // search in the left half
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int even[] = {2, 4, 6, 8, 12, 18};
    int odd[] = {3, 8, 11, 14, 16};

    cout << "Even: " << binary_search(even, 6, 6) << endl;
    cout << "Odd: " << binary_search(odd, 5, 14) << endl;

    return 0;
}