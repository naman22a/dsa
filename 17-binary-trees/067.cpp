#include <iostream>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

struct Node;

// Q1: Minimum time taken to BURN the Binary Tree from a Node
Node *bfsToMapParents(Node *root, unordered_map<Node *, Node *> &parentPointers, int target);
int bfs(unordered_map<Node *, Node *> parentPointers, Node *target);

// TC: O(N), -> O(N) + O(N)
// SC: O(N)
int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> parentPointers;
    Node *targetNode = bfsToMapParents(root, parentPointers, target);
    int time = bfs(parentPointers, targetNode);
    return time;
}

int bfs(unordered_map<Node *, Node *> parentPointers, Node *target)
{
    int time = 0;
    unordered_set<Node *> visited;

    queue<Node *> q;
    q.push(target);
    visited.insert(target);

    while (!q.empty())
    {
        int size = q.size();
        bool burned = false; // some node was burned
        for (int i = 0; i < size; i++)
        {

            Node *node = q.front();
            q.pop();

            if (node->left && visited.find(node->left) == visited.end())
            {
                burned = true;
                visited.insert(node->left);
                q.push(node->left);
            }
            if (node->right && visited.find(node->right) == visited.end())
            {
                burned = true;
                visited.insert(node->right);
                q.push(node->right);
            }

            if (parentPointers.find(node) != parentPointers.end() && visited.find(parentPointers[node]) == visited.end())
            {
                burned = true;
                visited.insert(parentPointers[node]);
                q.push(parentPointers[node]);
            }
        }

        // check if any nodes of this layer/level is burned
        if (burned)
            time++;
    }

    return time;
}

Node *bfsToMapParents(Node *root, unordered_map<Node *, Node *> &parentPointers, int target)
{
    queue<Node *> q;
    q.push(root);

    Node *result = NULL; // the node to start the burning
    while (!q.empty())
    {
        Node *node = q.front();
        if (node->data == target)
            result = node;
        q.pop();

        if (node->left)
        {
            parentPointers[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            parentPointers[node->right] = node;
            q.push(node->right);
        }
    }

    return result;
}

int main()
{

    return 0;
}

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