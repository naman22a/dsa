#include <iostream>
using namespace std;

// Quick Sort
// In-place sorting algorithm
// Unstable Sorting Algorithm

// Worst Case
// TC: O(N^2)
// SC: O(N)

// Avg / Best Case
// TC: O(N.log(N))
// SC: O(N)

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];

    // finding the count of all elements less than or equal to pivot element
    int lessThanPivot = 0;
    for (int i = left + 1; i <= right; i++)
    {
        if (arr[i] <= pivot)
            lessThanPivot++;
    }

    // place pivot at its correct position
    int pivotIndex = left + lessThanPivot;
    swap(arr[pivotIndex], arr[left]);

    // move the elements less than pivot to left
    // move the elements greater than pivot to right
    int i = left;
    int j = right;

    while (i < pivotIndex && j > pivotIndex)
    {
        // element < pivot and in left part
        while (arr[i] <= pivot)
            i++;
        // element > pivot and in right part
        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void qs(int arr[], int left, int right)
{
    // base case
    if (left >= right)
        return;

    // processing
    int pivotIndex = partition(arr, left, right);

    // recurrence
    qs(arr, left, pivotIndex - 1);
    qs(arr, pivotIndex + 1, right);
}

void quick_sort(int arr[], int size)
{
    qs(arr, 0, size - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {3, 5, 1, 8, 2, 4};
    int size = 6;

    printArray(arr, size);
    quick_sort(arr, size);
    printArray(arr, size);

    return 0;
}