#include <iostream>
#include <vector>
#include <stack>
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

// Q1: Merge 2 BSTs

// Optimized
// TC: O(N + M)
// SC: O(log(N) + log(M)) or O(H1 + H2)

// 1. Flatten both BSTs to Sorted Linked Lists(could also use Doubly Linked Lists(DLLs))
// 2. Merge 2 sorted Linked Lists
// 3. Sorted Linked list -> Balanced BST
//      - for this step ensure that Space Complexity should not exceed O(H1 + H2)

Node *merge(Node *root1, Node *root2)
{
}

// Brute Force Optimized(as i am using BST iterator to reduce space complexity)
// it has the same time and space complexity as optimized solution above
// TC: O(N + M)
// SC: O(log(N) + log(M)), assuiming balanced BST

// 1. store BST inorder traversal for both BST's in 2 arrays
// 2. Merge 2 sorted arrays
// 3. Construct BST from inorder traversal (from question "Balance a Binary Search Tree")

class BSTIterator
{
private:
    stack<Node *> st;

public:
    // SC: O(H)
    BSTIterator(Node *root)
    {
        pushAll(root);
    }

    // TC: O(1)
    int next()
    {
        Node *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    // TC: O(1)
    bool hasNext()
    {
        return !st.empty();
    }

private:
    void pushAll(Node *node)
    {
        while (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
    }
};

vector<int> mergeIterators(BSTIterator *one, BSTIterator *two);
Node *sortedListToBST(vector<int> &values, int start, int end);

// TC: O(N + M)
// SC: O(N + M)
Node *merge_brute_force(Node *root1, Node *root2)
{
    BSTIterator *one = new BSTIterator(root1);
    BSTIterator *two = new BSTIterator(root2);

    vector<int> mergedList = mergeIterators(one, two);

    // free dynamically allocated BSTIterators
    delete one;
    delete two;

    return sortedListToBST(mergedList, 0, mergedList.size() - 1);
}

vector<int> mergeIterators(BSTIterator *one, BSTIterator *two)
{
    vector<int> merged;

    int val1 = one->hasNext() ? one->next() : INT_MAX;
    int val2 = two->hasNext() ? two->next() : INT_MAX;

    while (val1 != INT_MAX || val2 != INT_MAX)
    {
        if (val1 < val2)
        {
            merged.push_back(val1);
            val1 = one->hasNext() ? one->next() : INT_MAX;
        }
        else
        {
            merged.push_back(val2);
            val2 = two->hasNext() ? two->next() : INT_MAX;
        }
    }

    return merged;
}

Node *sortedListToBST(vector<int> &values, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    Node *root = new Node(values[mid]);
    root->left = sortedListToBST(values, start, mid - 1);
    root->right = sortedListToBST(values, mid + 1, end);
    return root;
}

int main()
{

    return 0;
}