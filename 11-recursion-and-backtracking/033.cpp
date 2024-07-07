#include <iostream>
using namespace std;

// Q1: Array is Sorted ?
bool isSorted(int *arr, int size)
{
    // base case
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;
    else
        return isSorted(arr + 1, size - 1);
}

// Q2: Sum of elements in an Array using recursion
int sum(int arr[], int size)
{
    // base case
    if (size == 0)
        return 0;

    return arr[0] + sum(arr + 1, size - 1);
}

// Q3: Linear Search using Recursion

int linear_search(int arr[], int size, int target)
{
    if (size == 0)
        return -1;

    if (arr[0] == target)
        return 0;

    int index = linear_search(arr + 1, size - 1, target);

    if (index == -1)
        return -1;

    return 1 + index;
}

// Q4: Binary Search using Recursion
int bs(int arr[], int target, int left, int right)
{
    // base case
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return bs(arr, target, mid + 1, right); // search right half
    else
        return bs(arr, target, left, mid - 1); // search left half
}

int binary_search(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    return bs(arr, target, left, right);
}

int main()
{
    // Array is sorted
    {
        int arr[] = {2, 4, 6, 9, 11, 13};
        int size = 6;

        cout << "Sorted: " << isSorted(arr, size) << endl;
        int arr2[] = {2, 4, 9, 6, 101, 13};
        size = 6;

        cout << "Sorted: " << isSorted(arr2, size) << endl;

        cout << endl;
    }

    // Sum of Array
    {
        int arr[] = {3, 2, 5, 1, 6};
        int size = 5;

        cout << "Sum: " << sum(arr, size) << endl;
        cout << endl;
    }

    //  Linear Search using Recursion
    {
        int arr[] = {3, 5, 1, 2, 6};
        int size = 5;
        int target = 2;

        cout << "Element found at index: " << linear_search(arr, size, target) << endl;
        cout << endl;
    }

    // Binary Search using recursion
    {
        int arr[] = {2, 4, 6, 10, 14, 16};
        int size = 6;
        int target = 10;

        cout << "Element found at index: " << binary_search(arr, size, target) << endl;
        cout << endl;
    }

    return 0;
}