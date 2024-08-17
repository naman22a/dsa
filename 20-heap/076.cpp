#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Q1: Kth Largest Sum Subarray
// You are given an array arr.You have to find the K - th largest sum of contiguous subarray within the array elements.In other words, overall subarrays, find the subarray with kth largest sum and return its sum of elements

// TC: O(N^2.log(N))
// SC: O(N^2)
int getKthLargest_brute_force(vector<int> &arr, int k)
{
    vector<int> sums; // SC: O(N^2)
    int n = arr.size();

    // TC: O(N^2)
    for (int i = 0; i <= n - 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= n - 1; j++)
        {
            sum += arr[j];
            sums.push_back(sum);
        }
    }

    // TC: O(N^2.log(N))
    sort(sums.begin(), sums.end());

    return sums[sums.size() - k];
}

// optimized using heap
// TC: O(N^2.log(N))
// SC: O(K)
int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i <= n - 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= n - 1; j++)
        {
            sum += arr[j];

            if (pq.size() < k)
                pq.push(sum);
            else if (sum > pq.top())
            {
                pq.pop();
                pq.push(sum);
            }
        }
    }

    return pq.top();
}

// Q2: Merge k Sorted Arrays
// Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array.

class Node
{
public:
    int data;
    int i, j; // matrix indices

    Node(int data, int i, int j) : data(data), i(i), j(j) {}
};

class CompareNodes
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// TC: O(N.log(K))
// SC: O(K)
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<Node *, vector<Node *>, CompareNodes> pq; // min heap

    // 1. insert k first elements of all arrays
    for (int i = 0; i < K; i++)
    {
        Node *temp = new Node(arr[i][0], i, 0);
        pq.push(temp);
    }

    vector<int> ans;

    // 2. merge arrays
    while (!pq.empty())
    {
        Node *cur = pq.top();
        ans.push_back(cur->data);
        pq.pop();

        int i = cur->i;
        int j = cur->j;

        if (j + 1 < arr[i].size())
        {
            Node *next = new Node(arr[i][j + 1], i, j + 1);
            pq.push(next);
        }
    }

    return ans;
}

// Q3:
// Leetcode 23: Merge k Sorted Lists

class Comparator
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

// TC: O(N.log(K))
// SC: O(K)
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int k = lists.size();
    priority_queue<ListNode *, vector<ListNode *>, Comparator> pq;

    // edge case
    if (k == 0)
        return NULL;

    // 1. starting k elements into the heap
    for (int i = 0; i < k; i++)
    {
        if (lists[i] != NULL)
            pq.push(lists[i]);
    }

    // 2. merge lists
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (!pq.empty())
    {
        ListNode *cur = pq.top();
        pq.pop();

        if (head == NULL)
        {

            head = cur;
            tail = cur;

            if (head->next != NULL)
                pq.push(head->next);
        }
        else
        {
            tail->next = cur;
            tail = cur;
            if (tail->next != NULL)
                pq.push(tail->next);
        }
    }

    return head;
}

int main()
{

    return 0;
}