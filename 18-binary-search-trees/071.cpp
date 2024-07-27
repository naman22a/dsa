#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Q:
// Leetcode 173. Binary Search Tree Iterator
class BSTIterator_
{
private:
    stack<TreeNode *> st;

public:
    // SC: O(H)
    BSTIterator_(TreeNode *root)
    {
        pushAll(root);
    }

    // TC: O(1)
    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    // TC: O(1)
    bool hasNext()
    {
        return !st.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
    }
};

// Q1: Two Sum in BST
// Leetcode 653: Two Sum IV - Input is a BST
bool findTarget_brute_force(TreeNode *root, int k);
void findTarget_brute_force_dfs(TreeNode *root, vector<int> &traversal);
bool findTarget_iterator(TreeNode *root, int k);

// helper
class BSTIterator
{
private:
    stack<TreeNode *> st;
    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse = true;

public:
    // SC: O(H)
    BSTIterator(TreeNode *root, bool reverse)
    {
        this->reverse = reverse;
        pushAll(root);
    }

    // TC: O(1)
    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(!reverse ? temp->right : temp->left);
        return temp->val;
    }

    // TC: O(1)
    bool hasNext()
    {
        return !st.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            st.push(node);
            node = !reverse ? node->left : node->right;
        }
    }
};

bool findTarget(TreeNode *root, int k)
{
    return findTarget_iterator(root, k);
}

// TC: O(N)
// SC: O(2.H)
bool findTarget_iterator(TreeNode *root, int k)
{
    if (root == NULL)
        return false;

    BSTIterator *leftIterator = new BSTIterator(root, false);
    BSTIterator *rightIterator = new BSTIterator(root, true);

    int left = leftIterator->next();
    int right = rightIterator->next();

    while (left < right)
    {
        int sum = left + right;
        if (sum == k)
            return true;
        else if (sum < k)
            left = leftIterator->next();
        else
            right = rightIterator->next();
    }

    return false;
}

// TC: O(2.N)
// SC: O(N + H)
bool findTarget_brute_force(TreeNode *root, int k)
{
    vector<int> traversal;
    findTarget_brute_force_dfs(root, traversal);

    int left = 0;
    int right = traversal.size() - 1;

    while (left < right)
    {
        int sum = traversal[left] + traversal[right];

        if (sum == k)
            return true;
        else if (sum > k)
            right--;
        else
            left++;
    }

    return false;
}

void findTarget_brute_force_dfs(TreeNode *root, vector<int> &traversal)
{
    if (root == NULL)
        return;

    findTarget_brute_force_dfs(root->left, traversal);
    traversal.push_back(root->val);
    findTarget_brute_force_dfs(root->right, traversal);
}

// Q2: Flatten BST To A Sorted List
/*
You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.
Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.
*/
// Same question as "Flatten Binary Tree to Linked List"
// TC: O(N)
// SC: O(H)
Node *flattenBST(Node *root)
{
}

// Q3:
// Leetcode 1382: Balance a Binary Search Tree
void inorderTraversal(TreeNode *root);
TreeNode *createBalancedBSTFromSortedArray(vector<int> &values, int start, int end);

// TC: O(N)
// SC: O(N)
TreeNode *balanceBST(TreeNode *root)
{
    // using property of BST -> inorder is sorted
    vector<int> values;
    inorderTraversal(root, values);
    return createBalancedBSTFromSortedArray(values, 0, values.size() - 1);
}

void inorderTraversal(TreeNode *root, vector<int> &values)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, values);
    values.push_back(root->val);
    inorderTraversal(root->right, values);
}

TreeNode *createBalancedBSTFromSortedArray(vector<int> &values, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    TreeNode *node = new TreeNode(values[mid]);
    node->left = createBalancedBSTFromSortedArray(values, start, mid - 1);
    node->right = createBalancedBSTFromSortedArray(values, mid + 1, end);
    return node;
}

// Q4:
// Leetcode 1008: Construct Binary Search Tree from Preorder Traversal
// TC: O(3.N)
// SC: O(H)
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    // using logic of range [INT_MIN, INT_MAX] from Valid BST
    // we can just need the upper bound for this problem
    // every thing to the left will be smaller than 8
    // use the above property to find the elements in preorder which belong to the left subtree
    // Root Left Right
    // on left side it is upper bound
    // on right side it is lower bound
    int i = 0;
    return build(preorder, i, INT_MAX);
}

TreeNode *build(vector<int> &preorder, int &i, int bound)
{
    if (i == preorder.size() || preorder[i] > bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[i]);
    i++;
    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound); // previous bound
    return root;
}

int main()
{

    return 0;
}