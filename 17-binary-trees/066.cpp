#include <iostream>
#include <vector>
#include <unordered_map>
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
// Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal

TreeNode *build(vector<int> &preorder, unordered_map<int, int> &inorder_map, int &index, int i, int j);

// TC: O(N)
// SC: O(N)
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    /*
    1. Preorder: The first element of preorder traversal is always root node
    2. Inorder: when we remove the root node value from inorder traversal array, then the array is partiationed into to parts, then we can use those indices to slice the above preorder array to perform this operation recursively to consturct the binary tree
    (unique value are present in the array, given in the question)
    */

    // build hashmap for constant look up times
    unordered_map<int, int> inorder_map; // value -> index
    for (int i = 0; i < inorder.size(); i++)
        inorder_map[inorder[i]] = i;

    int index = 0;
    return build(preorder, inorder_map, index, 0, inorder.size() - 1);
}

TreeNode *build(vector<int> &preorder, unordered_map<int, int> &inorder_map, int &index, int i, int j)
{
    // base case
    // edge case: no nodes given to construct a binary tree
    if (i > j)
        return NULL;

    // create the root element
    TreeNode *root = new TreeNode(preorder[index]);

    // find the element at which partitation occurs
    int split = inorder_map[preorder[index]];
    index++;

    // pass indices to recursive functions to make sort of subarrays of preorder and inorder
    root->left = build(preorder, inorder_map, index, i, split - 1);
    root->right = build(preorder, inorder_map, index, split + 1, j);

    return root;
}

// Q2:
// Leetcode 106: Construct Binary Tree from Inorder and Postorder Traversal
TreeNode *build_(vector<int> &postorder, unordered_map<int, int> &inorder_map, int &index, int i, int j);

// TC: O(N)
// SC: O(N)
TreeNode *buildTree_post(vector<int> &inorder, vector<int> &postorder)
{
    // build hashmap for constant look up times
    unordered_map<int, int> inorder_map; // value -> index
    for (int i = 0; i < inorder.size(); i++)
        inorder_map[inorder[i]] = i;

    int index = postorder.size() - 1;
    return build_(postorder, inorder_map, index, 0, inorder.size() - 1);
}

TreeNode *build_(vector<int> &postorder, unordered_map<int, int> &inorder_map, int &index, int i, int j)
{
    // base case
    // edge case: no nodes given to construct a binary tree
    if (i > j)
        return NULL;

    // create the root element
    TreeNode *root = new TreeNode(postorder[index]);

    // find the element at which partitation occurs
    int split = inorder_map[postorder[index]];
    index--;

    // pass indices to recursive functions to make sort of subarrays of postorder and inorder
    // Note: right subtree is built before the left subtree since we are decreasing index
    root->right = build_(postorder, inorder_map, index, split + 1, j);
    root->left = build_(postorder, inorder_map, index, i, split - 1);

    return root;
}

int main()
{

    return 0;
}