#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Q1: Celebrity Problem
/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Return the index of the celebrity, if there is no celebrity return -1.
Note: Follow 0 based indexing.
*/
// TC: O(N)
// SC: O(N)
int celebrity(vector<vector<int>> &M, int n)
{
    // add all elements in the stack
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // If a knows b, discard "a" as celebrity knows no one
        if (M[a][b])
            st.push(b);

        // If a doesn't know b, discard "b" as b cannot be a celebrity
        else
            st.push(a);
    }

    // the remaining element in the stack is a potential candiate for celebrity
    // verify the element by using the 2 conditions

    int candidate = st.top();

    // knows no one(check row -> all should be zero)
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] != 0)
            return -1; // not found
    }

    // everyone knows celebrity, except celebrity (diagonal element)
    for (int i = 0; i < n; i++)
    {
        // skip diagonal element
        if (i == candidate)
            continue;

        if (M[i][candidate] != 1)
            return -1; // not found
    }

    return candidate;
}

// Q2: Max Rectangle in Binary Matrix with all 1's
// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.
#define MAX 1000

// helper function
int largestRectangleArea(int *heights, int n);

int maxArea(int M[MAX][MAX], int n, int m)
{
    // compute area for 1st row
    int area = largestRectangleArea(M[0], m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // update row(compute new row -> add previous row values)
            if (M[i][j] != 0)
                M[i][j] = M[i][j] + M[i - 1][j];
            else
                M[i][j] = 0;
        }

        // compute area
        area = max(area, largestRectangleArea(M[i], m));
    }

    return area;
}

int main()
{

    int n = 4, m = 4;
    int M[MAX][MAX] = {{0, 1, 1, 0},
                       {1, 1, 1, 1},
                       {1, 1, 1, 1},
                       {1, 1, 0, 0}};

    cout << "Area: " << maxArea(M, n, m) << endl;

    return 0;
}

int largestRectangleArea(int *heights, int n)
{
    int maxArea = 0;
    stack<pair<int, int>> st; // { index, height }

    for (int i = 0; i < n; i++)
    {
        int currentHeight = heights[i];
        int start = i; // to keep track of how much we can extend

        // can't be extended any more: st.top().second > currentHeight
        // decreasing wala case(heights in decreasing order)
        // pop with the stack, and extend the current height backwards
        while (!st.empty() && st.top().second > currentHeight)
        {
            int index = st.top().first;
            int height = st.top().second;
            int width = i - index;

            // remove element when heights are in decreasing order
            st.pop();

            maxArea = max(maxArea, height * width);
            start = index;
        }

        // push start as it is in case of increasing heights
        // push start(i - index) as it is in case of decreasing heights
        // the value of start is updated accordingly by the while loop above
        st.push({start, currentHeight});
    }

    // calculate area for remaining elements in the stack
    // they can be extended to the end of the histogram
    while (!st.empty())
    {
        int index = st.top().first;
        int height = st.top().second;
        st.pop();

        // (n - index) due to -> "they can be extended to the end of the histogram"
        int width = n - index;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}
