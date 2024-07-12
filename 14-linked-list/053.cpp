#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Q1:
// Leetcode 148: Sort List
// aka "Merge Sort in Linked List"

ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;

    while (fast != NULL && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return prev;
}

ListNode *mergeTwoSortedLists(ListNode *one, ListNode *two)
{
    ListNode *dummy = new ListNode;
    ListNode *tail = dummy;

    while (one != NULL && two != NULL)
    {
        if (one->val <= two->val)
        {
            tail->next = one;
            one = one->next;
        }
        else
        {
            tail->next = two;
            two = two->next;
        }
        tail = tail->next;
    }

    if (one != NULL)
        tail->next = one;

    if (two != NULL)
        tail->next = two;

    return dummy->next;
}

// TC: O(N.log(N))
// SC: O(log(N))
ListNode *sortList(ListNode *head)
{
    // base case: empty list or 1 node list is already sorted
    if (head == NULL || head->next == NULL)
        return head;

    // find middle using slow and fast pointers
    ListNode *mid = findMiddle(head);

    // split the linked list
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;

    // reccurence: sort left and right list
    left = sortList(left);
    right = sortList(right);

    // merge 2 sorted lists
    ListNode *result = mergeTwoSortedLists(left, right);

    return result;
}

Node *merge(Node *one, Node *two)
{
    Node *dummy = new Node(-1);
    Node *tail = dummy;

    while (one != NULL && two != NULL)
    {
        if (one->data <= two->data)
        {
            tail->bottom = one;
            tail = one;
            one = one->bottom;
        }
        else
        {
            tail->bottom = two;
            tail = two;
            two = two->bottom;
        }
        tail->next = NULL;
    }

    if (one != NULL)
        tail->bottom = one;

    if (two != NULL)
        tail->bottom = two;

    if (dummy->bottom != NULL)
        dummy->bottom->next = NULL;

    return dummy->bottom;
}

// Q2: Flatten a Linked List
// TC: O(M x N)
// SC: O(N)
Node *flatten(Node *root)
{
    // base case
    if (root == NULL || root->next == NULL)
        return root;

    // recurrence
    Node *mergedHead = flatten(root->next);

    // processing
    root = merge(root, mergedHead);

    return root;
}

int main()
{

    return 0;
}