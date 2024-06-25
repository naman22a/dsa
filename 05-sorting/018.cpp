#include <iostream>
using namespace std;

void printArray(int arr[], int n);

// In-place sorting algorithm (no extra space/memory required)
// Stable Sorting Algorithm
// TC: O(N^2)
// SC: O(1)
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }

        // print passes
        printArray(arr, n);
    }
}

int main()
{
    int arr[] = {14, 9, 15, 12, 6, 8, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    cout << endl;
    insertion_sort(arr, n);
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