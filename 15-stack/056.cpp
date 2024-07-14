#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Q1:
// TC: O(N)
// SC: O(N)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int current = arr[i];
        while (st.top() >= current)
            st.pop();

        int smallest = st.top();
        result[i] = smallest;
        st.push(current);
    }

    return result;
}

// Q2:
// Leetcode 84: Largest Rectangle in Histogram
// TC: O(N)
// SC: O(N)
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;
    stack<pair<int, int>> st; // { index, height }

    for (int i = 1; i < n; i++)
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

int main()
{

    return 0;
}