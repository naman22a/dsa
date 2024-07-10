#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Q1: Detect Cycle in Linked List
// Leetcode 141: Linked List Cycle
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

// Q2: Starting Node of loop in Linked List
// Leetcode 142: Linked List Cycle II
// TC: O(N)
// SC: O(1)
ListNode *detectCycle(ListNode *head)
{
    // 1. find the collision node
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // no loop
    if (fast == NULL || fast->next == NULL)
        return NULL;

    // 2. find the starting node
    ListNode *entry = head;
    while (entry != slow)
    {
        entry = entry->next;
        slow = slow->next;
    }

    // 3. return the loop starting node
    return entry;
}

// Q3: Remove Cycle from Linked List
// TC: O(N)
// SC: O(1)
void removeLoop(ListNode *head)
{
    // edge case
    if (head == NULL || head->next == NULL)
        return;

    // 1. check for collision of fast and slow pointers
    // check if there is a loop
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // no loop
    if (fast == NULL || fast->next == NULL)
        return;

    // 2. Find the node just before the starting node
    slow = head; // reuse slow, instead to making another pointer such as entry

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // slow and fast are now both at the start of the loop

    // 3. Find the node just before the start of the loop
    while (fast->next != slow)
        fast = fast->next;

    // the node just before loop node is stored in fast
    // 4. Make the node point to NULL
    fast->next = NULL;
}

int main()
{

    return 0;
}