#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

// Q1:
// Leetcode 632: Smallest Range Covering Elements from K Lists

// TC: O(N.log(K)), -> O(K.log(K)) + O(N.log(K))
// SC: O(K), for heap
vector<int> smallestRange(vector<vector<int>> &nums)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int k = nums.size();

    // min heap (element, row, col)
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // create a min heap for starting elements of k arrays
    for (int i = 0; i < k; i++)
    {
        int element = nums[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        pq.push({element, i, 0});
    }

    int start = mini;
    int end = maxi;

    // processing ranges
    while (!pq.empty())
    {
        // fetch mini
        vector<int> cur = pq.top();
        pq.pop();
        mini = cur[0];

        // update range
        if (maxi - mini < end - start)
            start = mini, end = maxi;

        // check if next element exists
        int row = cur[1];
        int col = cur[2];
        int n = nums[row].size();
        if (col + 1 < n)
        {
            maxi = max(maxi, nums[row][col + 1]);
            pq.push({nums[row][col + 1], row, col + 1});
        }
        else
            break;
    }

    return {start, end};
}

// alternative representation of data in heap
// same approach

class Node
{
public:
    int data;
    int row, col;

    Node(int data, int row, int col) : data(data), row(row), col(col) {}
};

class Comparator
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// TC: O(N.log(K)), -> O(K.log(K)) + O(N.log(K))
// SC: O(K), for heap
vector<int> smallestRange_(vector<vector<int>> &nums)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int k = nums.size();

    // min heap
    priority_queue<Node *, vector<Node *>, Comparator> pq;

    // create a min heap for starting elements of k arrays
    for (int i = 0; i < k; i++)
    {
        int element = nums[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        pq.push(new Node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    // processing ranges
    while (!pq.empty())
    {
        // fetch mini
        Node *cur = pq.top();
        pq.pop();
        mini = cur->data;

        // update range
        if (maxi - mini < end - start)
            start = mini, end = maxi;

        // check if next element exists
        int n = nums[cur->row].size();
        if (cur->col + 1 < n)
        {
            maxi = max(maxi, nums[cur->row][cur->col + 1]);
            pq.push(new Node(nums[cur->row][cur->col + 1], cur->row, cur->col + 1));
        }
        else
            break;
    }

    return {start, end};
}

// Q2:
// Leetcode 295: Find Median from Data Stream
class MedianFinder
{
    // max heap
    priority_queue<int> small;

    // min heap
    priority_queue<int, vector<int>, greater<int>> large;

public:
    MedianFinder() {}

    // TC: O(log(N))
    void addNum(int num)
    {
        small.push(num);

        // make sure that every element in small is <= every element in large
        if (!small.empty() && !large.empty() && small.top() > large.top())
        {
            int value = small.top();
            small.pop();
            large.push(value);
        }

        // check balance
        if (small.size() > large.size() + 1)
        {
            int value = small.top();
            small.pop();
            large.push(value);
        }

        if (large.size() > small.size())
        {
            int value = large.top();
            large.pop();
            small.push(value);
        }
    }

    // TC: O(1)
    double findMedian()
    {
        if (small.size() > large.size())
            return small.top();
        if (small.size() < large.size())
            return large.top();
        else
            return (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Q3:
// Leetcode 767: Reorganize String
// TC: O(N), generally O(N.log(N)), here log(N) is 26
// SC: O(N), using a heap
string reorganizeString(string s)
{
    unordered_map<char, int> freq;
    for (auto ch : s)
        freq[ch]++;

    vector<pair<int, char>> heap;
    for (auto &item : freq)
    {
        char ch = item.first;
        int count = item.second;
        heap.push_back({count, ch});
    }

    priority_queue<pair<int, char>> pq(heap.begin(), heap.end());

    pair<int, char> prev = {-1, '#'}; // represents NULL
    string result;

    while (!pq.empty() || (prev.first != -1 && prev.second != '#'))
    {
        // can not find the solution
        if ((prev.first != -1 && prev.second != '#') && pq.empty())
            return "";

        // most frequent character except the previous character
        pair<int, char> p = pq.top();
        pq.pop();
        int count = p.first;
        char ch = p.second;

        result.push_back(ch);
        count -= 1;

        if (prev.first != -1 && prev.second != '#')
        {
            pq.push(prev);
            prev = {-1, '#'};
        }

        if (count > 0)
            prev = {count, ch};
    }

    return result;
}

int main()
{

    return 0;
}