#include <iostream>
#include <climits>
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

// Q1:
// Leetcode 98: Validate Binary Search Tree
bool validateBST(TreeNode *root, long long int minVal, long long int maxVal);

bool isValidBST(TreeNode *root)
{
    return validateBST(root, LLONG_MIN, LLONG_MAX);
}

bool validateBST(TreeNode *root, long long int minVal, long long int maxVal)
{
    if (root == NULL)
        return true;

    // out of range
    if (root->val >= maxVal || root->val <= minVal)
        return false;

    return validateBST(root->left, minVal, root->val) && validateBST(root->right, root->val, maxVal);
}

// TC: O(N)
// SC: O(H)
// TODO
// Alternative approach, check inorder traversal is sorted or not, using two pointers, do not store the traversal in array

// Q2:
// Leetcode 230: Kth Smallest Element in a BST
// TC: O(N)
// SC: O(H)
int kthSmallest(TreeNode *root, int k)
{
    int result = 0;
    int count = 0;
    inorder(root, k, result, count);
    return result;
}

void inorder(TreeNode *root, int k, int &result, int &count)
{
    if (root == NULL)
        return;

    // inorder -> Left Root Right

    inorder(root->left, k, result, count);

    count++;
    if (k == count)
    {
        result = root->val;
        return;
    }

    inorder(root->right, k, result, count);
}

// TODO
// TC: O(N)
// SC: O(1)
// inorder traversal using morris traversal

// Q3: Kth Largest Element in a BST

// Q4: Inorder Successor/Predecessor in BST
// Leetcode 285: Inorder Successor in BST
TreeNode *inorderSucessor(TreeNode *root, TreeNode *p)
{
    TreeNode *successor = NULL;

    while (root != NULL)
    {
        if (p->val >= root->val)
            root = root->right;
        else
        {
            successor = root; // save possible successor
            root = root->left;
        }
    }

    return successor;
}

// Inorder Predecessor in BST

TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p)
{
    TreeNode *predecessor = NULL;

    while (root != NULL)
    {
        if (p->val >= root->val)
            root = root->left;
        else
        {
            predecessor = root; // save possible predecessor
            root = root->right;
        }
    }

    return predecessor;
}

// Q5:
// Leetcode 235: Lowest Common Ancestor of a Binary Search Tree
// TC: O(H)
// SC: O(1)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *current = root;

    // to continue to repeat, but current will never be null
    while (current != NULL)
    {
        // case 1: both p and q are greater than root
        // go to the right subtree to search
        if (p->val > current->val && q->val > current->val)
            current = current->right;
        // case 2: both p and q are less than root
        // go to the left subtree to search
        else if (p->val < current->val && q->val < current->val)
            current = current->left;
        // case 3: if the split occurs and we find LCA or not find it(which is null), so we return the result
        else
            return current;
    }

    // no need for return statement but for types, return NULL
    return NULL;
}

int main()
{

    return 0;
}