#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1: Book Allocation Problem
// Leetcode 410: Split Array Largest Sum
/*
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.
4. You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

If the allocation of books is not possible, return -1.
*/

// helper function
int sum(vector<int> arr)
{
    int total = 0;
    for (auto num : arr)
        total += num;
    return total;
}

bool isValidSolution(vector<int> &arr, int n, int m, int solution)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int pages = arr[i];
        if (pageSum + pages <= solution)
            pageSum += pages;
        else
        {
            studentCount++;
            // if student count exceeds m (books left unallocated)
            // the value of no of pages should be less than the possible solution / guess / mid
            if (studentCount > m || pages > solution)
                return false;

            // start with new sum for new student
            pageSum = 0;
            pageSum += pages;
        }
    }

    return true;
}

int findPages(vector<int> &arr, int n, int m)
{
    int left = 0;
    int right = sum(arr);
    int ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (isValidSolution(arr, n, m, mid))
        {
            ans = mid;       // store the answer
            right = mid - 1; // search in left half
        }
        else
            left = mid + 1; // search in right half
    }

    return ans;
}

// same as the question above
// Q2: Painter's Partition Problem
// Leetcode 1482: Minimum Number of Days to Make m Bouquets
/*
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2
Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.
*/

int findLargestMinDistance(vector<int> &boards, int k)
{
    int left = 0;
    int right = sum(boards);
    int ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (isValidSolution(boards, boards.size(), k, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return ans;
}

// Q3: Aggressive Cows Problem
// Leetcode 1552: Magnetic Force Between Two Balls
/*
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Print the maximum possible minimum distance.

Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
*/

// TC: O(Nlog(N))
// SC: O(1) / O(N), for sorting, function call stack space during recursion

bool possibleSolution(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int position = stalls[0]; // last position

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - position >= mid)
        {
            cowCount++;
            if (cowCount == k)
                return true;
            position = stalls[i];
        }
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    // sorting
    sort(stalls.begin(), stalls.end());

    int largest = stalls[stalls.size() - 1];
    int smallest = stalls[0];

    int left = 0;
    int right = largest - smallest;
    int ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (possibleSolution(stalls, k, mid))
        {
            ans = mid;      // store the possible solution
            left = mid + 1; // search in right half to get the maximize the answer
        }
        else
            right = mid - 1;
    }

    return ans;
}

int main()
{

    return 0;
}