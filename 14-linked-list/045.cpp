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
void show(ListNode *head);
ListNode *reverseList_iteratively(ListNode *head);

// Q1:
// Leetcode 206: Reverse Linked List
ListNode *reverseList(ListNode *head)
{
    return reverseList_iteratively(head);
}

// TC: O(N)
// SC: O(1)
ListNode *reverseList_iteratively(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *next;

    while (cur != NULL)
    {
        next = cur->next; // store a pointer pointing to next node

        cur->next = prev; // point back from current node
        // move prev and cur one step ahead

        prev = cur;
        cur = next;
        // no need to move next as it will be moved to next position in the next iteration of the loop
    }

    return prev;
}

// TC: O(N)
// SC: O(N)
ListNode *reverseList_recursively(ListNode *head)
{
    // smaller probelms
    // a linked list with 0 / 1 node is already reversed (base case)
    // a linked list with 2 nodes (solve in processing)

    // base case
    if (head == NULL || head->next == NULL)
        return head;

    // recurrence
    ListNode *newHead = reverseList_recursively(head->next);

    // processing
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

// Q2:
// Leetcode 876: Middle of the Linked List
// TC: O(N)
// SC: O(1)
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    {
        ListNode *head = new ListNode(1);
        ListNode *second = new ListNode(2);
        ListNode *third = new ListNode(3);
        ListNode *fourth = new ListNode(4);
        ListNode *fifth = new ListNode(5);

        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
        fifth->next = NULL;

        show(head);
        head = reverseList(head);
        show(head);

        cout << endl;
    }

    {
        ListNode *head = new ListNode(1);
        ListNode *second = new ListNode(2);
        ListNode *third = new ListNode(3);
        ListNode *fourth = new ListNode(4);
        ListNode *fifth = new ListNode(5);

        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
        fifth->next = NULL;

        show(head);

        cout << "Middle: " << middleNode(head)->val << endl;
    }

    return 0;
}

void show(ListNode *head)
{
    ListNode *cur = head;
    while (cur != NULL)
    {
        cout << cur->val << " --> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}