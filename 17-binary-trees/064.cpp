#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
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
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

// Q1:
// Leetcode 103: Binary Tree Zigzag Level Order Traversal
// TC: O(N)
// SC: O(N)
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    // edge case
    if (root == NULL)
        return {};

    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);

    int rev = false;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        if (rev)
            reverse(level.begin(), level.end());
        result.push_back(level);

        rev = !rev; // toggle
    }

    return result;
}

// Q2: Boundary Traversal of Binary Tree
// Leetcode 545: Boundary of Binary Tree
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1 (on leetcode the problem is paid)
bool isLeaf(Node *node);
void addLeftBoundary(Node *root, vector<int> &result);
void addLeaves(Node *root, vector<int> &result);
void addRightBoundary(Node *root, vector<int> &result);

// TC: O(N)
// SC: O(N)
vector<int> boundary(Node *root)
{
    vector<int> result;

    // edge case
    if (!root)
        return result;

    if (!isLeaf(root))
        result.push_back(root->data);

    addLeftBoundary(root, result);
    addLeaves(root, result);
    addRightBoundary(root, result);

    return result;
}

bool isLeaf(Node *node)
{
    return node->left == NULL && node->right == NULL;
}

void addLeftBoundary(Node *root, vector<int> &result)
{
    Node *cur = root->left;

    while (cur)
    {
        if (!isLeaf(cur))
            result.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addLeaves(Node *root, vector<int> &result)
{
    if (isLeaf(root))
    {
        result.push_back(root->data);
        return;
    }

    if (root->left)
        addLeaves(root->left, result);
    if (root->right)
        addLeaves(root->right, result);
}

void addRightBoundary(Node *root, vector<int> &result)
{
    Node *cur = root->right;
    stack<int> temp;

    while (cur)
    {
        if (!isLeaf(cur))
            temp.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    while (!temp.empty())
    {
        result.push_back(temp.top());
        temp.pop();
    }
}

// Q3:
// Leetcode 987: Vertical Order Traversal of a Binary Tree
// TC: O(N.log(N))
// SC: O(N)
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        TreeNode *node = p.first;
        int vertical = p.second.first; // x
        int level = p.second.second;   // y

        nodes[vertical][level].insert(node->val);

        if (node->left)
            q.push({node->left, {vertical - 1, level + 1}});
        if (node->right)
            q.push({node->right, {vertical + 1, level + 1}});
    }

    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

// Q4: Top View of Binary Tree
// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// TC: O(N.log(N))
// SC: O(N)
vector<int> topView(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    // mapping between vertical -> node value
    map<int, int> mapping; // indicates the top most node or first node in the vertical
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int vertical = it.second;

        // not already visited line/vertical
        if (mapping.find(vertical) == mapping.end())
            mapping[vertical] = node->data;

        if (node->left)
            q.push({node->left, vertical - 1});
        if (node->right)
            q.push({node->right, vertical + 1});
    }

    for (auto it : mapping)
        ans.push_back(it.second);

    return ans;
}

// Q5: Bottom View of Binary Tree
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// TC: O(N.log(N))
// SC: O(N)
vector<int> bottomView(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    // mapping between vertical -> node value
    map<int, int> mapping; // indicates the bottom most node or last node in the vertical
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int vertical = it.second;

        // keeping updating the mapping, so the most lastest / last value of the vertical is stored in it
        mapping[vertical] = node->data;

        if (node->left)
            q.push({node->left, vertical - 1});
        if (node->right)
            q.push({node->right, vertical + 1});
    }

    for (auto it : mapping)
        ans.push_back(it.second);

    return ans;
}

// Q6: Left View of Binary Tree
vector<int> leftView(Node *root)
{
    // edge case
    if (root == NULL)
        return {};

    vector<int> result;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if (i == 0)
                result.push_back(node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return result;
}

// Q7: Right View of Binary Tree
vector<int> rightSideView_using_BFS(TreeNode *root);
vector<int> rightSideView_using_DFS(TreeNode *root);
void dfs(TreeNode *node, int level, vector<int> &result);

vector<int> rightSideView(TreeNode *root)
{
    return rightSideView_using_BFS(root);
}

// using BFS
// TC: O(N)
// SC: O(N/2)
vector<int> rightSideView_using_BFS(TreeNode *root)
{
    // edge case
    if (root == NULL)
        return {};

    vector<int> result;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        int last;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            last = node->val;
        }

        result.push_back(last);
    }

    return result;
}

// using DFS
// TC: O(N)
// SC: O(H)
vector<int> rightSideView_using_DFS(TreeNode *root)
{
    vector<int> result;
    dfs(root, 0, result);
    return result;
}

void dfs(TreeNode *node, int level, vector<int> &result)
{
    if (node == NULL)
        return;

    // visiting the level for the first time, add this node
    if (level == result.size())
        result.push_back(node->val);

    // order of the calls matter
    // do right one first because right view of binary tree
    dfs(node->right, level + 1, result);
    dfs(node->left, level + 1, result);
}

// TODO
// Q7: Diagonal Traversal of Binary Tree

int main()
{

    return 0;
}