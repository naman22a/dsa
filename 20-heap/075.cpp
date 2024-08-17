#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Q1: Kth Smallest Element in an Array
// Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct. Note:-  l and r denotes the starting and ending index of the array.

// TC: O(N.log(K))
// SC: O(k)
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;

    // TC: O(K.log(K))
    int i = l;
    while (i < k)
    {
        pq.push(arr[i]);
        i++;
    }

    // TC: O(N.log(K))
    for (int i = l + k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

// Q2:
// Leetcode 215: Kth Largest Element in an Array

int findKthLargest_using_sorting(vector<int> &nums, int k);
int findKthLargest_using_max_heap(vector<int> &nums, int k);

int findKthLargest(vector<int> &nums, int k)
{
    return findKthLargest_using_max_heap(nums, k);
}

// TC: O(N.log(N))
// SC: O(N), for sorting
int findKthLargest_using_sorting(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

// TC: O(N + K.log(N)), to heapify and remove k elements from the heap
// SC: O(N), to store the elements in the heap
int findKthLargest_using_max_heap(vector<int> &nums, int k)
{
    // heapify
    priority_queue<int> pq(nums.begin(), nums.end());

    int result = nums[0];
    while (k--)
    {
        result = pq.top();
        pq.pop();
    }

    return result;
}

// Q3: Is Binary Tree Max Heap

bool isCBT(struct Node *root, int i, int nodeCount)
{
    if (root == NULL)
        return true;

    if (i >= nodeCount)
        return false;

    bool left = isCBT(root->left, 2 * i + 1, nodeCount);
    bool right = isCBT(root->right, 2 * i + 2, nodeCount);

    return left && right;
}

bool isMaxOrderProperty(struct Node *root)
{
    // if leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // if only left child
    if (root->left != NULL && root->right == NULL)
        return root->data > root->left->data;

    // else both left and right exists

    bool left = isMaxOrderProperty(root->left);
    bool right = isMaxOrderProperty(root->right);

    return (root->data > max(root->left->data, root->right->data)) && left && right;
}

int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return 1 + left + right;
}

// TC: O(N)
// SC: O(H)
bool isHeap(struct Node *tree)
{
    int count = countNodes(tree);
    return isCBT(tree, 0, count) && isMaxOrderProperty(tree);
}

// Similar question
// Leetcode 958: Check Completeness of a Binary Tree

// Q4: Merge two binary Max heaps

void heapify(vector<int> &arr, int n, int index)
{
    // for 0 based indexing
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

// TC: O((N + M).log(N + M))
// SC: O(N + M)
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // 1. merge 2 arrays -> O(N + M)
    vector<int> merged(n + m);

    int i = 0;
    while (i < n)
    {
        merged[i] = a[i];
        i++;
    }
    int j = 0;
    while (j < m)
    {
        merged[i + j] = b[j];
        j++;
    }

    // 2. build heap using merged array (for 0 based indexing) -> O((N + M).log(N + M))
    int size = merged.size();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(merged, size, i);

    return merged;
}

// Q5: Minimum Cost of ropes
// There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.

// TC: O(N.log(N))
// SC: O(N)
long long minCost(long long arr[], long long n)
{
    long long cost = 0;

    // build vector
    vector<int> ropes(n);
    for (int i = 0; i < n; i++)
        ropes[i] = arr[i];

    // heapify
    priority_queue<long long, vector<long long>, greater<long long>> pq(ropes.begin(), ropes.end());

    while (pq.size() > 1)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        cost += first + second;
        pq.push(first + second);
    }

    return cost;
}

// Q6: Convert BST to Min Heap

void inorder(struct Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;

    inorder(root->left, traversal);
    traversal.push_back(root->data);
    inorder(root->right, traversal);
}

void fillPreOrder(struct Node *root, vector<int> &traversal, int &i)
{
    if (root == NULL)
        return;

    root->data = traversal[i];
    i++;

    fillPreOrder(root->left, traversal, i);
    fillPreOrder(root->right, traversal, i);
}

// TC: O(N)
// SC: O(H)
void convertToMinHeap(struct Node *root)
{
    vector<int> traversal;
    inorder(root, traversal);
    int index = 0;
    fillPreOrder(root, traversal, index);
}

// Q7: Convert BST to Max Heap

void fillPostOrder(struct Node *root, vector<int> &traversal, int &i)
{
    if (root == NULL)
        return;

    fillPostOrder(root->left, traversal, i);
    fillPostOrder(root->right, traversal, i);

    root->data = traversal[i];
    i++;
}

// TC: O(N)
// SC: O(H)
void convertToMaxHeap(struct Node *root)
{
    vector<int> traversal;
    inorder(root, traversal);
    int index = 0;
    fillPostOrder(root, traversal, index);
}

int main()
{

    return 0;
}