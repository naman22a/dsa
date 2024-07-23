#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Q1: Sum of nodes on the longest path from root to leaf node
void dfs_sumOfLongRootToLeafPath(Node *root, int length, int sum, int &maxLength, int &maxSum);

// TC: O(N)
// SC: O(H)
int sumOfLongRootToLeafPath(Node *root)
{
    int length = 0;
    int maxLength = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    dfs_sumOfLongRootToLeafPath(root, length, sum, maxLength, maxSum);

    return maxSum;
}

void dfs_sumOfLongRootToLeafPath(Node *root, int length, int sum, int &maxLength, int &maxSum)
{
    // base case
    if (root == NULL)
    {
        if (length > maxLength)
        {
            maxLength = length;
            maxSum = sum;
        }
        else if (length == maxLength)
            maxSum = max(maxSum, sum);
        return;
    }

    sum += root->data;

    dfs_sumOfLongRootToLeafPath(root->left, length + 1, sum, maxLength, maxSum);
    dfs_sumOfLongRootToLeafPath(root->right, length + 1, sum, maxLength, maxSum);
}

// Q2: LCA
// Leetcode 236: Lowest Common Ancestor of a Binary Tree
// TC: O(N)
// SC: O(H)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // base case:
    if (root == NULL)
        return NULL;

    // base case: we found the node we are searching for, so return the node
    if (root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // accept the non NULL value to backtrack upwards
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    // both left and right are not NULL so we found our result
    return root;
}

// Q3: K Sum Paths
// Leetcode 437: Path Sum III
int dfs_pathSum(TreeNode *root, long long targetSum, long long runningSum, unordered_map<long long, int> &prefixSum);

// TC: O(N)
// SC: O(N)
int pathSum(TreeNode *root, int targetSum)
{
    unordered_map<long long, int> prefixSum; // maps prefix sum to it's frequency/count
    prefixSum.insert({0, 1});
    return dfs_pathSum(root, targetSum, 0, prefixSum);
}

int dfs_pathSum(TreeNode *root, long long targetSum, long long runningSum, unordered_map<long long, int> &prefixSum)
{
    if (root == NULL)
        return 0;

    runningSum += root->val;

    int count = prefixSum.find(runningSum - targetSum) != prefixSum.end() ? prefixSum[runningSum - targetSum] : 0;
    prefixSum[runningSum]++;

    count += dfs_pathSum(root->left, targetSum, runningSum, prefixSum) + dfs_pathSum(root->right, targetSum, runningSum, prefixSum);

    prefixSum[runningSum]--;

    return count;
}

// Q4: Kth Ancestor in a Tree
Node *dfs_kthAncestor(Node *root, int &k, int node);

// TC: O(N)
// SC: O(H)
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = dfs_kthAncestor(root, k, node);
    // edge case: ans->data == node
    return (ans == NULL || ans->data == node) ? -1 : ans->data;
}

Node *dfs_kthAncestor(Node *root, int &k, int node)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == node)
        return root;

    Node *left = dfs_kthAncestor(root->left, k, node);
    Node *right = dfs_kthAncestor(root->right, k, node);

    // here we come back / backtrack / ans from left and right comming towards one node
    if (left != NULL && right == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX; // so it can't reach zero by decrementing recursive calls
            return root;
        }
        return left;
    }

    if (left == NULL && right != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX; // so it can't reach zero by decrementing recursive calls
            return root;
        }
        return right;
    }

    return NULL;
}

// Q5: Maximum sum of Non-adjacent nodes
pair<int, int> dfs(Node *root);

// TC: O(N)
// SC: O(H)
int getMaxSum(Node *root)
{
    // pair<int, int> -> sum including current node, sum excluding current node
    pair<int, int> ans = dfs(root);
    return max(ans.first, ans.second);
}

pair<int, int> dfs(Node *root)
{
    if (root == NULL)
        return {0, 0};

    pair<int, int> left = dfs(root->left);
    pair<int, int> right = dfs(root->right);

    pair<int, int> result;

    // maximum sum including all nodes at current level
    result.first = root->data + left.second + right.second;

    // maximum sum excluding all nodes at current level
    result.second = max(left.first, left.second) + max(right.first, right.second);

    return result;
}

int main()
{

    return 0;
}