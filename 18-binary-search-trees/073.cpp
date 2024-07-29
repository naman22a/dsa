#include <iostream>
#include <climits>
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

// Q1: Largest BST in a Binary Tree
struct Triplet
{
    int size;
    int largest;
    int smallest;

    Triplet(int size, int largest, int smallest) : size(size), largest(largest), smallest(smallest) {}
};
Triplet dfs(Node *root);

// TC: O(N)
// SC: O(H)
int largestBst(Node *root)
{
    // post order traversal -> Left Right Root
    return dfs(root).size;
}

Triplet dfs(Node *root)
{
    // an empty tree is bst of size zero
    if (root == NULL)
        return Triplet(0, INT_MIN, INT_MAX);

    // get values from left and right subtree of current tree
    Triplet left = dfs(root->left);
    Triplet right = dfs(root->right);

    // condition for valid BST
    // current node is greater than max in left and smaller than min in right, it is a BST
    if (left.largest < root->data && root->data < right.smallest)
        return Triplet(1 + left.size + right.size, max(root->data, right.largest), min(root->data, left.smallest));

    // otherwise return large number, so it can't be a valid BST
    return Triplet(max(left.size, right.size), INT_MAX, INT_MIN);
}

int main()
{

    return 0;
}