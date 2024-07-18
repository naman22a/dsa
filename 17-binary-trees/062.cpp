#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void printVector(vector<vector<int>> arr);

// Binary Tree Node
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

// Creation / Building a Binary Tree
TreeNode *buildTree(TreeNode *root)
{
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    root = new TreeNode(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << ": " << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

// Binary Tree Traversals

// 1. DFS (Depth First Search)
// TC: O(N), N is number of nodes in the binary tree
// SC: O(N), O(N) is worst case space complexity in case of a dengenrate tree, it is actually height of the tree
// SC: O(H), H is the height of the binary tree
// for all

// a. Preorder Traversal (Root Left Right)
void preorder(TreeNode *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// b. Inorder Traversal (Left Root Right)
void inorder(TreeNode *node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// c. Postorder Traversal (Left Right Root)
void postorder(TreeNode *node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

// the above 3 using iteration

// a. Preorder Traversal (Root Left Right)
void ipreorder(TreeNode *root)
{
    if (root == NULL)
        return;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        cout << node->data << " ";
        if (node->right != NULL)
            st.push(node->right);
        if (node->left != NULL)
            st.push(node->left);
    }
    cout << endl;
}

// b. Inorder Traversal (Left Root Right)
void iinorder(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;

            node = st.top();
            st.pop();

            cout << node->data << " ";
            node = node->right;
        }
    }

    cout << endl;
}

// c. Postorder Traversal (Left Right Root)
// using 2 stacks
void ipostorder2(TreeNode *root)
{
    if (root == NULL)
        return;

    TreeNode *node = root;

    stack<TreeNode *> one;
    stack<TreeNode *> two;
    one.push(node);

    while (!one.empty())
    {
        node = one.top();
        one.pop();
        two.push(node);

        if (node->left != NULL)
            one.push(node->left);
        if (node->right != NULL)
            one.push(node->right);
    }

    while (!two.empty())
    {
        cout << two.top()->data << " ";
        two.pop();
    }
    cout << endl;
}

// c. Postorder Traversal (Left Right Root)
// using a single stack
void ipostorder(TreeNode *root)
{
    TreeNode *cur = root;
    stack<TreeNode *> st;

    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left; // keep on going left
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
                cur = temp;
        }
    }

    cout << endl;
}

// 2. BFS (Breadth first search) / Level Order Traversal

// TC: O(N)
// SC: O(N)
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        vector<int> level;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            // add children of this node to the queue
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            level.push_back(node->data);
        }

        result.push_back(level);
    }

    return result;
}

// Create Tree from Level Order Traversal
void buildFromLevelOrder(TreeNode *&root)
{
    queue<TreeNode *> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new TreeNode(data);

    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new TreeNode(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new TreeNode(rightData);
            q.push(temp->right);
        }
    }
}

// Q1: Count Leaves in Binary Tree
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// can use any dfs traversal to solve this question
// preorder, inorder, postorder
// i have used preorder
void dfs(Node *root, int &count)
{
    // base case
    if (root == NULL)
        return;

    // leaf node
    if (root->left == NULL && root->right == NULL)
        count++;

    // backtracking / recurrence
    dfs(root->left, count);
    dfs(root->right, count);
}

int countLeaves(Node *root)
{
    int cnt = 0;
    dfs(root, cnt);
    return cnt;
}

int main()
{
    // Binary Tree Representation
    {
        TreeNode *root = new TreeNode(5);

        root->left = new TreeNode(6);
        root->right = new TreeNode(7);

        root->left->left = new TreeNode(8);
        root->left->right = new TreeNode(9);
        root->left->right->left = new TreeNode(1);

        preorder(root);
        cout << endl;
        cout << endl;
    }

    // Creation / Building a Binary Tree
    if (0)
    {
        TreeNode *root = NULL;
        root = buildTree(root);
    }

    // DFS
    {
        TreeNode *root = new TreeNode(1);

        root->left = new TreeNode(2);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->left->right->left = new TreeNode(6);

        root->right = new TreeNode(3);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(8);
        root->right->right->left = new TreeNode(9);
        root->right->right->right = new TreeNode(10);

        // preorder
        preorder(root);
        cout << endl;
        ipreorder(root);
        cout << endl;

        // inorder
        inorder(root);
        cout << endl;
        iinorder(root);
        cout << endl;

        // postorder
        postorder(root);
        cout << endl;
        ipostorder2(root);
        ipostorder(root);
        cout << endl;

        cout << endl;
    }

    // BFS
    {
        TreeNode *root = new TreeNode(1);

        root->left = new TreeNode(2);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->left->right->left = new TreeNode(6);

        root->right = new TreeNode(3);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(8);
        root->right->right->left = new TreeNode(9);
        root->right->right->right = new TreeNode(10);

        printVector(levelOrder(root));

        cout << endl;
    }

    // Create Tree from Level Order Traversal
    {
        // input: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
        TreeNode *root = NULL;
        buildFromLevelOrder(root);
        printVector(levelOrder(root));
        // output:
        /*
        1
        3 5
        7 11 17
        */
    }

    return 0;
}

void printVector(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}