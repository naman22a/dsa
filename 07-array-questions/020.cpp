#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>);

// Q1: Reverse The Array
/*
Problem statement
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.
Example:
We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0
based indexing so the subarray {5, 6} will be reversed and our
output array will be {1, 2, 3, 4, 6, 5}.
*/

// TC: O(N)
// SC: O(1)
// & -> vector<int> &arr -> pass by reference
void reverse(vector<int> &arr, int m)
{
    int left = m + 1; // after m => m + 1
    int right = arr.size() - 1;

    while (left <= right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Q2:
// Leetcode 88: Merge Sorted Array
// Actually the question is to "merge 2 sorted arrays"
// TC: O(N)
// SC: O(1)
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int last = m + n - 1;

    // merge in reverse order
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] < nums2[j])
        {
            nums1[last] = nums2[j];
            j--;
        }
        else
        {
            nums1[last] = nums1[i];
            i--;
        }
        last--;
    }

    // fill nums1 with left over elements of nums2
    while (j >= 0)
    {
        nums1[last] = nums2[j];
        j--;
        last--;
    }
}

// Q3:
// Leetcode 283: Move Zeroes
// TC: O(N)
// SC: O(1)
void moveZeroes(vector<int> &nums)
{
    int left = 0;
    int right = 0;

    while (right <= nums.size() - 1)
    {
        // when value is zero ignore it and move on
        if (nums[right] == 0)
        {
            right++;
        }
        // when value is non zero, then swap left and right pointers and increment them both
        else
        {
            swap(nums[left], nums[right]);
            left++;
            right++;
        }
    }
}

int main()
{
    {
        vector<int> arr = {1, 2, 3, 4, 5, 6};
        int m = 3;
        printArray(arr);
        reverse(arr, m);
        printArray(arr);
        cout << endl;
    }

    {
        vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
        int m = 3, n = 3;

        printArray(nums1);
        printArray(nums2);

        merge(nums1, m, nums2, n);

        printArray(nums1);
        printArray(nums2);
    }

    {
        vector<int> nums = {0, 1, 0, 3, 12};
        printArray(nums);
        moveZeroes(nums);
        printArray(nums);
    }

    return 0;
}

void printArray(vector<int> arr)
{
    for (auto e : arr)
        cout << e << " ";
    cout << endl;
}