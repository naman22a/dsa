#include <iostream>
using namespace std;

void printArray(int arr[], int n);

// In-place sorting algorithm (no extra space/memory required)
// Stable Sorting Algorithm
// TC: O(N^2)
// SC: O(1)
void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        bool swapped = false;

        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        // print passes
        printArray(arr, n);

        if (swapped == false)
            break;
    }
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    cout << endl;
    bubble_sort(arr, n);
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