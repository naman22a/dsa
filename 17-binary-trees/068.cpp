#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct TreeNode;

// Morris Inorder Traversal
// TC: O(N)
// SC: O(1)
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *cur = root;

    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->val);
            cur = cur->right; // go to right subtree
        }
        // if left exists
        else
        {
            // go to the left
            TreeNode *prev = cur->left;
            // case for thread already made: prev->right != cur
            while (prev->right && prev->right != cur)
                // go to the right most node (in left subtree)
                prev = prev->right;

            // (right most node)->right will be NULL
            if (prev->right == NULL)
            {
                // create the thread
                prev->right = cur;
                cur = cur->left; // go back in the left subtree
            }

            // thread already exists (remove the thread)
            else
            {
                prev->right = NULL;          // cut/remove the thread
                inorder.push_back(cur->val); // take the value of node visited again by going upwards via the thread
                cur = cur->right;
            }
        }
    }

    return inorder;
}

// Morris Preorder Traversal
// TC: O(N)
// SC: O(1)
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    TreeNode *cur = root;

    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            preorder.push_back(cur->val);
            cur = cur->right; // go to right subtree
        }
        // if left exists
        else
        {
            // go to the left
            TreeNode *prev = cur->left;
            // case for thread already made: prev->right != cur
            while (prev->right && prev->right != cur)
                // go to the right most node (in left subtree)
                prev = prev->right;

            // (right most node)->right will be NULL
            if (prev->right == NULL)
            {
                // create the thread
                prev->right = cur;
                preorder.push_back(cur->val); // take the value of node before going to the left subtree
                cur = cur->left;              // go back in the left subtree
            }

            // thread already exists (remove the thread)
            else
            {
                prev->right = NULL; // cut/remove the thread
                cur = cur->right;
            }
        }
    }

    return preorder;
}

// Morris Postorder Traversal
// TC: O(N)
// SC: O(1)
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> postorder;
    TreeNode *cur = root;

    while (cur != NULL)
    {
        if (cur->right == NULL)
        {
            postorder.push_back(cur->val);
            cur = cur->left; // go to left subtree
        }
        // if right exists
        else
        {
            // go to the right
            TreeNode *next = cur->right;
            // case for thread already made: prev->left != cur
            while (next->left && next->left != cur)
                // go to the left most node (in left subtree)
                next = next->left;

            // (left most node)->left will be NULL
            if (next->left == NULL)
            {
                // create the thread
                next->left = cur;
                postorder.push_back(cur->val); // take the value of node before going to the right subtree
                cur = cur->right;              // go back in the right subtree
            }

            // thread already exists (remove the thread)
            else
            {
                next->left = NULL; // cut/remove the thread
                cur = cur->left;
            }
        }
    }

    reverse(postorder.begin(), postorder.end());

    return postorder;
}

// Q1:
// Leetcode 114: Flatten Binary Tree to Linked List

void flatten(TreeNode *root)
{
    return flatten_using_morris_traversal(root);
}

// TC: O(N)
// SC: O(1)
void flatten_using_morris_traversal(TreeNode *root)
{
    // Right Left Root -> Reverse Preorder(Root Left Right)

    TreeNode *cur = root;

    while (cur != NULL)
    {
        // if left subtree exists
        if (cur->left != NULL)
        {
            TreeNode *prev = cur->left;

            // go to right most node in the left subtree
            while (prev->right)
                prev = prev->right;

            // connect the rightmost node of the left subtree to the right subtree
            prev->right = cur->right;

            // move the left subtree to the right
            cur->right = cur->left;

            // set left to NULL
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

// TC: O(N)
// SC: O(N)
void flatten_using_stack(TreeNode *root)
{
    // edge case
    if (root == NULL)
        return;

    // iterative version of recursive solution
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();

        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);

        if (!st.empty())
            cur->right = st.top();
        cur->left = NULL;
    }
}

// TC: O(N)
// SC: O(H)
void flatten_using_recursion(TreeNode *root)
{
    // do Right Left Root -> Reverse Postorder Traversal
    TreeNode *prev = NULL;
    dfs(root, prev);
}

void dfs(TreeNode *node, TreeNode *prev)
{
    if (node == NULL)
        return;

    dfs(node->right, prev);
    dfs(node->left, prev);

    node->right = prev;
    node->left = NULL;
    prev = node;
}

int main()
{

    return 0;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};