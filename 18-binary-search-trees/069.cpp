#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int data) : data(data), left(NULL), right(NULL) {}
    TreeNode(int data, TreeNode *left, TreeNode *right) : data(data), left(left), right(right) {}
};

class BST
{
    TreeNode *root;

public:
    BST() : root(NULL) {}
    BST(int data) : root(new TreeNode(data)) {}

    // BFS / Level Order Traversal
    void print();

    // Search in BST

    // TC: O(log(N)), log base 2
    // SC: O(1)
    TreeNode *searchBST(int target)
    {
        TreeNode *cur = root;
        while (cur != NULL && cur->data != target)
            cur = target < cur->data ? cur->left : cur->right;
        return cur;
    }

    // Insert in BST

    // TC: O(log(N))
    // SC: O(1)
    void insert(int value)
    {
        // edge case
        if (root == NULL)
        {
            root = new TreeNode(value);
            return;
        }

        TreeNode *cur = root;

        while (true)
        {
            if (cur->data <= value)
            {
                if (cur->right != NULL)
                    cur = cur->right;
                else
                {
                    cur->right = new TreeNode(value);
                    break;
                }
            }
            else
            {
                if (cur->left != NULL)
                    cur = cur->left;
                else
                {
                    cur->left = new TreeNode(value);
                    break;
                }
            }
        }
    }

public:
    // Delete in BST

    // TC: O(H)
    // SC: O(1)
    void *remove(int target)
    {
        if (root == NULL)
            return NULL;

        if (root->data == target)
            return deleteNode(root);

        TreeNode *current = root;

        while (current != NULL)
        {
            if (current->data > target)
            {
                if (current->left != NULL && current->left->data == target)
                {
                    current->left = deleteNode(current->left);
                    break;
                }
                else
                    current = current->left;
            }
            else
            {
                if (current->right != NULL && current->right->data == target)
                {
                    current->right = deleteNode(current->right);
                    break;
                }
                else
                    current = current->right;
            }
        }
    }

private:
    TreeNode *deleteNode(TreeNode *node)
    {
        // edge case
        if (node->left == NULL)
        {
            TreeNode *rightSubTree = node->right;
            delete node;
            return rightSubTree;
        }

        // edge case
        if (node->right == NULL)
        {
            TreeNode *leftSubTree = node->left;
            delete node;
            return leftSubTree;
        }

        TreeNode *rightChild = node->right;
        TreeNode *lastRight = findLastRight(node->left);
        lastRight->right = rightChild;
        TreeNode *leftChild = node->left;
        delete node;
        return leftChild;
    }

    TreeNode *findLastRight(TreeNode *node)
    {
        TreeNode *cur = node;
        while (cur->right != NULL)
            cur = cur->right;
        return cur;
    }

public:
    // Min and Max in BST

    int min()
    {
        TreeNode *cur = root;
        while (cur->left != NULL)
            cur = cur->left;
        return cur->data;
    }

    int max()
    {
        TreeNode *cur = root;
        while (cur->right != NULL)
            cur = cur->right;
        return cur->data;
    }
};

int main()
{
    BST bst;

    // Insert in BST
    bst.insert(8);
    bst.insert(5);
    bst.insert(4);
    bst.insert(7);
    bst.insert(6);
    bst.insert(12);
    bst.insert(10);
    bst.insert(14);
    bst.insert(13);

    bst.print();
    cout << endl;
    cout << endl;

    // Search in BST
    int target = 10;
    TreeNode *found = bst.searchBST(target);
    cout << "Value found at node: " << (found ? found->data : -1) << endl;
    cout << endl;
    cout << endl;

    // Delete in BST

    bst.print();
    bst.remove(10);
    cout << endl;
    bst.print();

    // Min and Max in BST

    cout << "Min: " << bst.min() << endl;
    cout << "Max: " << bst.max() << endl;

    return 0;
}

void BST::print()
{
    if (root == NULL)
        return;

    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            level.push_back(node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        result.push_back(level);
    }

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
