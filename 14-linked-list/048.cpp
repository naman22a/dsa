#include <iostream>
#include <unordered_set>
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
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Q1:
// Leetcode 83: Remove Duplicates from Sorted List
// TC: O(N)
// SC: O(1)
ListNode *deleteDuplicates(ListNode *head)
{
    // edge case: empty List
    if (head == NULL)
        return NULL;

    ListNode *cur = head;

    while (cur->next != NULL)
    {
        if (cur->val == cur->next->val)
        {
            ListNode *temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }
        else
            cur = cur->next;
    }

    return head;
}

// Q2:
// Leetcode 1836: Remove Duplicates from an Unsorted List

// TC: O(N)
// SC: O(N)
Node *removeDuplicates(Node *head)
{
    // edge case
    if (head == NULL)
        return NULL;

    unordered_set<int> visited;
    Node *cur = head;

    visited.insert(cur->data);

    while (cur != NULL && cur->next != NULL)
    {
        if (visited.find(cur->next->data) != visited.end())
        {
            Node *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else
        {
            visited.insert(cur->next->data);
            cur = cur->next;
        }
    }

    return head;
}

int main()
{

    return 0;
}