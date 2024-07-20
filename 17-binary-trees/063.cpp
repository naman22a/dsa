#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node
{
    int data;
    Node *left, *right;
};

// Q1: Height of a Binary Tree
// Leetcode 104: Maximum Depth of Binary Tree
int maxDepth_using_dfs(TreeNode *root);
int maxDepth_using_bfs(TreeNode *root);

int maxDepth(TreeNode *root)
{
    return maxDepth_using_dfs(root);
}

// TC: O(N)
// SC: O(H), H is the height of the tree, which is going to be N in a dengenerate tree
int maxDepth_using_dfs(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = maxDepth_using_dfs(root->left);  // max left height
    int rh = maxDepth_using_dfs(root->right); // max right height

    return 1 + max(lh, rh);
}

// TC: O(N)
// SC: O(N/2), the leaf nodes are going to to be N/2 worst case in balanced tree
int maxDepth_using_bfs(TreeNode *root)
{
    // edge case
    if (root == NULL)
        return 0;

    queue<TreeNode *> q;
    q.push(root);

    int height = 0;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        // one level completed here
        height++;
    }

    return height;
}

// Q2:
// Leetcode 543: Diameter of Binary Tree
void dfs_diameterOfBinaryTree_using_brute_force(TreeNode *root, int &diameter);
int dfs_diameterOfBinaryTree_height(TreeNode *root, int &diameter);
int diameterOfBinaryTree_height(TreeNode *root);

int diameterOfBinaryTree(TreeNode *root)
{
    return diameterOfBinaryTree_height(root);
}

// TC: O(N)
// SC: O(H)
int diameterOfBinaryTree_height(TreeNode *root)
{
    int diameter = 0;
    dfs_diameterOfBinaryTree_height(root, diameter);
    return diameter;
}

int dfs_diameterOfBinaryTree_height(TreeNode *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int lh = dfs_diameterOfBinaryTree_height(root->left, diameter);
    int rh = dfs_diameterOfBinaryTree_height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

// TC: O(N^2)
// SC: O(H)
int diameterOfBinaryTree_using_brute_force(TreeNode *root)
{
    // Approach: DFS tree traversal + Height of Binary Tree question

    int diameter = 0;
    dfs_diameterOfBinaryTree_using_brute_force(root, diameter);
    return diameter;
}

void dfs_diameterOfBinaryTree_using_brute_force(TreeNode *root, int &diameter)
{
    if (root == NULL)
        return;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    diameter = max(diameter, lh + rh);

    dfs_diameterOfBinaryTree_using_brute_force(root->left, diameter);
    dfs_diameterOfBinaryTree_using_brute_force(root->right, diameter);
}

// Q3:
// Leetcode 110: Balanced Binary Tree
pair<bool, int> isBalanced_optimized(TreeNode *node);

bool isBalanced(TreeNode *root)
{
    return isBalanced_optimized(root).first;
}

// TC: O(N)
// SC: O(H)
pair<bool, int> isBalanced_optimized(TreeNode *node)
{
    if (node == NULL)
        return {true, 0};

    pair<bool, int> left = isBalanced_optimized(node->left);
    pair<bool, int> right = isBalanced_optimized(node->right);

    int lh = left.second;
    int rh = right.second;

    // do not add up this -1 into the height
    if (lh == -1 || rh == -1)
        return {false, -1};

    // condition for not balanced binary tree
    if (abs(lh - rh) > 1)
        return {false, -1};

    return {true, 1 + max(lh, rh)};
}

// TC: O(N^2)
// SC: O(H)
bool isBalanced_brute_force(TreeNode *node)
{
    if (node == NULL)
        return true;

    // improve this for optimized approach
    int lh = maxDepth(node->left);
    int rh = maxDepth(node->right);

    // condition for not balanced binary tree
    if (abs(lh - rh) > 1)
        return false;

    bool left = isBalanced_brute_force(node->left);
    bool right = isBalanced_brute_force(node->right);

    if (!left || !right)
        return false;

    return true;
}

// Q4: Identical Trees
// Leetcode 100: Same Tree

// TC: O(N)
// SC: O(H)
bool isSameTree(TreeNode *p, TreeNode *q)
{
    /* if (p == NULL && q == NULL)
        return true;

    if (p == NULL && q != NULL)
        return false;

    if (p != NULL && q == NULL)
        return false; */
    // can be replaced by above

    // base case
    if (p == NULL || q == NULL)
        return p == q;

    // check if values are equal
    if (p->val != q->val)
        return false;

    // check recursively if both trees are same
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return left && right;
}

// Q5: Sum Tree
/*
Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
*/
pair<bool, int> isSumTree_dfs(Node *root);

// TC: O(N)
// SC: O(H)
bool isSumTree(Node *root)
{
    return isSumTree_dfs(root).first;
}

pair<bool, int> isSumTree_dfs(Node *root)
{
    // base case: empty tree
    if (root == NULL)
        return {true, 0};

    // base case: leaf node
    if (root->left == NULL && root->right == NULL)
        return {true, root->data};

    pair<bool, int> left = isSumTree_dfs(root->left);
    pair<bool, int> right = isSumTree_dfs(root->right);

    int leftSum = left.second;
    int rightSum = right.second;

    if (leftSum == -1 || rightSum == -1)
        return {false, -1};

    if (root->data != leftSum + rightSum)
        return {false, -1};

    return {true, root->data + leftSum + rightSum};
}

int main()
{

    return 0;
}