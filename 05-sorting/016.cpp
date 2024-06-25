#include <iostream>
using namespace std;

void printArray(int arr[], int n);

// In-place sorting algorithm (no extra space/memory required)
// Unstable Sorting Algorithm
// TC: O(N^2)
// SC: O(1)
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }

        swap(arr[i], arr[mini]);

        // print passes
        printArray(arr, n);
    }
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    cout << endl;
    selection_sort(arr, n);
    cout << endl;
    printArray(arr, n);

    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}