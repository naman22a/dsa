#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseKGroup_using_two_pointers(ListNode *head, int k);
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void show(Node *head);

// Q1:
// Leetcode 25: Reverse Nodes in k-Group

ListNode *reverseKGroup(ListNode *head, int k)
{
    return reverseKGroup_using_two_pointers(head, k);
}

ListNode *getKth(ListNode *current, int k)
{
    while (current != NULL && k > 0)
    {
        current = current->next;
        k--;
    }
    return current;
}

// TC: O(N)
// SC: O(1)
ListNode *reverseKGroup_using_two_pointers(ListNode *head, int k)
{
    ListNode *dummy = new ListNode;
    dummy->next = head;
    ListNode *groupPrevious = dummy; // the node just before the group

    while (true)
    {
        ListNode *kth = getKth(groupPrevious, k);

        // if kth node does not exists, then we don't have k elements to be reversed
        if (kth == NULL)
            break;

        // the node just after the group
        ListNode *groupNext = kth->next;

        // reversing the group
        ListNode *prev = kth->next;
        ListNode *current = groupPrevious->next;

        while (current != groupNext)
        {
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        // link the reversed list to the next group
        ListNode *temp = groupPrevious->next;
        groupPrevious->next = kth;
        groupPrevious = temp;
    }
    return dummy->next;
}

// Q2:
// Leetcode 141: Linked List Cycle
// TC: O(N)
// SC: O(1)
bool hasCycle(ListNode *head)
{
    // Floyd's Tortoise and Hare Algorithm: to detect cycle in a linked list
    // fast and slow pointer

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

// same as above question ig
// Q3: Check Linked List is Circular or not / Circularly Linked
/*
You are given the head of a linked list containing integers, You need to find out whether the given linked list is circular or not.
1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form a circle i.e. the next pointer of last node points to the first node.
2. An empty linked will also be considered as circular.
3. All the integers in the linked list are unique.
4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.
*/

bool isCircular(Node *head)
{
    return isCircular_using_iteration(head);
}

// TC: O(N)
// SC: O(1)
bool isCircular_using_iteration(Node *head)
{
    // edge case: empty list
    if (head == NULL)
        return head;

    Node *cur = head;
    do
        cur = cur->next;
    while (cur != head && cur != NULL);

    return cur == head;
}

// TC: O(N)
// SC: O(N)
bool isCircular_using_hashmap(Node *head)
{
    // edge case: empty list
    if (head == NULL)
        return head;

    unordered_map<Node *, bool> visited;

    Node *cur = head;
    while (cur != NULL)
    {
        if (visited.find(cur) != visited.end())
            return true;

        cur = cur->next;
        visited[cur] = true; // mark visited
    }

    return false;
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // fifth->next = NULL;
    fifth->next = head;

    cout << "circular: " << isCircular(head) << endl;

    return 0;
}

void show(Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " --> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}