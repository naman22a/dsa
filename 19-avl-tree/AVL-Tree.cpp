#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// AVL tree -> self balancing BST
// * not generally asked the implementation(code) of AVL tree
// * theory notes in copy

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    int height;

    TreeNode() : data(0), left(NULL), right(NULL), height(1) {}
    TreeNode(int data) : data(data), left(NULL), right(NULL), height(1) {}
    TreeNode(int data, TreeNode *left, TreeNode *right) : data(data), left(left), right(right), height(1) {}
};

class AVLTree
{

private:
    TreeNode *root;

public:
    AVLTree() : root(NULL) {}
    AVLTree(int data) : root(new TreeNode(data)) {}

private:
    // Helpers for balancing the tree
    int getHeight(TreeNode *node)
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(TreeNode *node)
    {
        if (node == NULL)
            return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    TreeNode *rightRotate(TreeNode *y)
    {
        // left subtree
        TreeNode *x = y->left;
        // left subtree ka right subtree
        TreeNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        // update heights
        // only heights of x and y are changed
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        // x is the new head
        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        // right subtree
        TreeNode *y = x->right;
        // right subtree ka left subtree
        TreeNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        // update heights
        // only heights of x and y are changed
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        // y is the new head
        return y;
    }

    // print
public:
    void bfs()
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
                TreeNode *cur = q.front();
                q.pop();

                level.push_back(cur->data);

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
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

    // insertion
public:
    void insert(int data)
    {
        root = insert_helper(root, data);
    }

private:
    TreeNode *insert_helper(TreeNode *node, int data)
    {
        // standard insertion in BST
        if (node == NULL)
            return new TreeNode(data);

        if (data < node->data)
            node->left = insert_helper(node->left, data);
        else
            node->right = insert_helper(node->right, data);

        // update height
        // update height from leaf node to upwards
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        // when 1st Left -> (bf > 1) (reason -> bf -> (left - right))

        // Left Left Case
        if (balanceFactor > 1 && data < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balanceFactor < -1 && data > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balanceFactor > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balanceFactor < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};

int main()
{
    AVLTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    tree.bfs();

    return 0;
}
