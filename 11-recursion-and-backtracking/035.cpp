#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(int arr[], int low, int mid, int high)
{
    vector<int> temp;

    // [left ... mid]
    // [mid+1 ... high]
    int left = low;
    int right = mid + 1;

    // common
    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    // elements left in first array (left)
    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    // elements left in second array (right)
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mS(int arr[], int left, int right)
{
    // base case
    if (left == right)
        return;

    int mid = left + (right - left) / 2;

    mS(arr, left, mid);      // sort left part
    mS(arr, mid + 1, right); // sort right part

    // merge the 2 sorted arrays
    mergeArrays(arr, left, mid, right);
}

// Not In-place sorting algorithm
// Stable Sorting Algorithm
// TC: O(N.log(N))
// SC: O(N), temp array in mergeArrays function
void mergeSort(int arr[], int size)
{
    mS(arr, 0, size - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = 7;

    printArray(arr, size);
    mergeSort(arr, size);
    printArray(arr, size);

    return 0;
}