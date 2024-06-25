#include <iostream>
using namespace std;

void printArray(int arr[], int n);
bool ascending(int a, int b) { return a < b; }
bool descending(int a, int b) { return a > b; }

// Unstable Sorting Algorithm
// TC: O(N^2)
// SC: O(1)
void selection_sort(int arr[], int n, bool (*comparator)(int, int))
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            // if (arr[j] < arr[mini])
            if (comparator(arr[j], arr[mini]))
                mini = j;
        }

        swap(arr[i], arr[mini]);
    }
}

int main()
{
    int arr[] = {5, 4, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    selection_sort(arr, n, &ascending);
    printArray(arr, n);
    selection_sort(arr, n, &descending);
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