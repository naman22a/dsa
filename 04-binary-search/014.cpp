#include <iostream>
#include <vector>
using namespace std;

// Q1: Find Pivot in an array(sorted and rotated)
// TC: O(log(N))
// SC: O(1)
int findPivot(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        // one first line
        if (arr[mid] >= arr[0])
            left = mid + 1;
        else
            right = mid;
    }

    return left; // or right
}

// Q2:
// Leetcode 33: Search in Rotated Sorted Array

// helper function
int binary_search(vector<int> &arr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// helper function (i am using function overloading here)
int findPivot(vector<int> arr)
{
    int left = 0;
    int n = arr.size();
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= arr[0])
            left = mid + 1;
        else
            right = mid;
    }

    return left; // or right
}

// TC: O(log(N))
// SC: O(1)
int search(vector<int> &arr, int n, int k)
{
    int pivot = findPivot(arr);

    // search on the second line
    if (arr[pivot] <= k && k <= arr[n - 1])
        return binary_search(arr, pivot, n - 1, k);
    // search on the first line
    else
        return binary_search(arr, 0, pivot - 1, k);
}

// Q3:
// Leetcode 69: Sqrt(x)

int sqrtInteger(int x)
{
    // edge case
    if (x == 0 || x == 1)
        return x;

    // search space 0 to x
    int left = 0;
    int right = x;

    int ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // to avoid integer overflow
        // mid*mid == x -> mid == x / mid
        if (mid == x / mid)
            return mid;
        // search in right part
        else if (mid < x / mid)
        {
            ans = mid;
            left = mid + 1;
        }
        // search in left part
        else
            right = mid - 1;
    }

    return ans;
}

// Q4: Finding the float(decimal) part in Square Root
double morePrecision(int n, int precision, int tempSolution)
{
    double factor = 1;
    double ans = tempSolution;

    for (int i = 0; i < precision; i++)
    {
        // it becomes 0.1
        // it becomes 0.01
        // ...
        factor = factor / 10;

        for (double j = ans; j * j < n; j += factor)
            ans = j;
    }

    return ans;
}

int main()
{
    {
        int arr[] = {7, 9, 1, 2, 3};
        int n = sizeof(arr) / sizeof(arr[0]);

        cout << "Pivot index: " << findPivot(arr, n) << endl;
        cout << "Pivot value: " << arr[findPivot(arr, n)] << endl;
    }

    {
        vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
        int n = arr.size();
        int target = 0;

        cout << "Element found at index: " << search(arr, n, target) << endl;
    }

    {
        int x = 35;
        cout << "sqrt: " << sqrtInteger(x) << endl;
    }

    {
        int n = 37;
        int tempSol = sqrtInteger(37);
        cout << "Answer: " << morePrecision(n, 3, tempSol) << endl;
    }

    return 0;
}