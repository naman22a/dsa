#include <iostream>
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
class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
};
NodeValue largestBSTSubTreeHelper(Node *root);

// TC: O(N)
// SC: O(H)
int largestBst(Node *root)
{
    // post order traversal -> Left Right Root
    return largestBSTSubTreeHelper(root).maxSize;
}

NodeValue largestBSTSubTreeHelper(Node *root)
{
    // an empty tree is bst of size zero
    if (root == NULL)
        return NodeValue(INT_MAX, INT_MIN, 0);

    // get values from left and right subtree of current tree
    NodeValue left = largestBSTSubTreeHelper(root->left);
    NodeValue right = largestBSTSubTreeHelper(root->right);

    // condition for valid BST
    // current node is greater than max in left and smaller than min in right, it is a BST
    if (left.maxNode < root->data && root->data < right.minNode)
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);

    // otherwise return large number, so it can't be a valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int main()
{

    return 0;
}