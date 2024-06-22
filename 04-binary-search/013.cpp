#include <iostream>
#include <vector>
using namespace std;

// Q1: First and Last position of an element in sorted array
/*
Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.
Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1.
2. 'arr' may contain duplicate elements.
Example:
Input: 'arr' = [0,1,1,5] , 'k' = 1
Output: 1 2
Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.
*/

int first_occurence(vector<int> &arr, int n, int k)
{
    int left = 0;
    int right = n - 1;
    int ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // *NOTE: only change in this condition
        if (arr[mid] == k)
        {
            ans = mid;
            // keep searching in left half, to get the left most element
            right = mid - 1;
        }
        // search in left half
        else if (arr[mid] > k)
            right = mid - 1;
        // search in right half
        else
            left = mid + 1;
    }

    return ans;
}

int last_occurence(vector<int> &arr, int n, int k)
{
    int left = 0;
    int right = n - 1;
    int ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // *NOTE: only change in this condition
        if (arr[mid] == k)
        {
            ans = mid;
            // keep searching in right half, to get the right most element
            left = mid + 1;
        }
        // search in left half
        else if (arr[mid] > k)
            right = mid - 1;
        // search in right half
        else
            left = mid + 1;
    }

    return ans;
}

// TC: O(log(N))
// SC: O(1)
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = first_occurence(arr, n, k);
    int last = last_occurence(arr, n, k);
    return {first, last};
}

// Q2: Find total number of occurences of 3 in the above problem
// don't count the number of 3's in the array using linear search
// Ans-> (last_index - first_index) + 1 (use binary search)

// Q3:
// Leetcode 852: Peak Index in a Mountain Array
// TC: O(log(N))
// SC: O(1)
int peakIndexInMountainArray(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        // in left half => search right half
        if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        // peak element
        // or
        // in right half(decreasing part)
        else
            right = mid;
    }

    return left; // or right
}

// Q4:
// Leetcode 724: Find Pivot Index
// TC: O(N)
// SC: O(1)
int sum(vector<int> &nums)
{
    int total = 0;
    for (auto num : nums)
        total += num;
    return total;
}
int pivotIndex(vector<int> &nums)
{
    // left + pivot + right = total;
    // => right = total - left - pivot
    int total = sum(nums);
    int leftSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int rightSum = total - leftSum - nums[i];
        if (leftSum == rightSum)
            return i;
        leftSum += nums[i];
    }

    return -1;
}

int main()
{
    {
        vector<int> arr = {1, 2, 3, 3, 5};
        int target = 3;

        cout << "First index: " << firstAndLastPosition(arr, arr.size(), target).first << endl;
        cout << "Last index: " << firstAndLastPosition(arr, arr.size(), target).second << endl;
    }

    {
        vector<int> arr = {0, 10, 5, 2};
        cout << "Peak: " << peakIndexInMountainArray(arr) << endl;
    }

    {
        vector<int> nums = {1, 7, 3, 6, 5, 6};
        cout << "Pivot: " << pivotIndex(nums) << endl;
    }

    return 0;
}