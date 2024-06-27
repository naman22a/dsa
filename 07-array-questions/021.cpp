#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printArray(vector<int> arr);

// Q1:
// Leetcode 189: Rotate Array

// TC: O(N)
// SC: O(N)
void rotate_using_circular_array_concept(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp(n);

    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}

// helper function
void reverse_array(vector<int> &arr, int left, int right)
{
    while (left < right)
        swap(arr[left++], arr[right--]);
}

// TC: O(N)
// SC: O(1)
void rotate_using_reverse_array_pattern(vector<int> &nums, int k)
{
    int n = nums.size();

    // k could be greater than the length of the array, so we can reduce the rotations
    k = k % n;

    // reverse whole array
    reverse_array(nums, 0, n - 1);

    // reverse the first half
    reverse_array(nums, 0, k - 1);

    // reverse the second half
    reverse_array(nums, k, n - 1);
}

void rotate(vector<int> &nums, int k)
{
    return rotate_using_reverse_array_pattern(nums, k);
}

// Q2:
// Leetcode 1752: Check if Array Is Sorted and Rotated
// TC: O(N)
// SC: O(1)
bool check(vector<int> &nums)
{
    int n = nums.size();
    int pairs = 0;

    // starts i = 1 to avoid index out of bound error, when doing nums[i-1]
    // Check if the array is non-decreasing
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            pairs++;
    }

    // check last element with first element (cyclic)
    // Check if the last element is greater than the first element
    if (nums[n - 1] > nums[0])
        pairs++;

    // If the count of violations is less than or equal to 1, return true
    return pairs <= 1;
}

// Q3: Sum Of Two Arrays
/*
You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.

1. The length of each array is greater than zero.

2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.

3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.
*/
// TC: O(N)
// SC: O(1)
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;

    int carry = 0;
    vector<int> ans;

    while (i >= 0 && j >= 0)
    {
        int x = a[i];
        int y = a[j];

        int sum = x + y + carry;
        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);

        i--;
        j--;
    }

    // first case: a.size() > b.size()
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);

        i--;
    }

    // second case: b.size() > a.size()
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);

        j--;
    }

    // third case
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    // because we a pushing elements at the start of the ans array
    // reverse the array
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    {
        vector<int> a = {9, 9, 9};
        vector<int> b = {9, 9, 9};
        printArray(a);
        printArray(b);

        vector<int> ans = findArraySum(a, a.size(), b, b.size());
        printArray(ans);
    }

    return 0;
}

void printArray(vector<int> arr)
{
    for (auto e : arr)
        cout << e << " ";
    cout << endl;
}