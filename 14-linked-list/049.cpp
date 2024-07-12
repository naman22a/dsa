#include <iostream>
#include <vector>
using namespace std;

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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Q1: Sort 0s, 1s and 2s in Linked List
// TC: O(N)
// SC: O(1)
// use bucket sort (freq array wali trick)
Node *segregate(Node *head)
{
    Node *cur = head;
    vector<int> buckets(3);

    while (cur != NULL)
    {
        buckets[cur->data]++;
        cur = cur->next;
    }

    cur = head;

    int i = 0;
    while (cur != NULL)
    {
        while (buckets[i] > 0)
        {
            cur->data = i;
            buckets[i]--;
            cur = cur->next;
        }
        i++;
    }

    return head;
}

void insertAtTail(Node *&tail, Node *node)
{
    tail->next = node;
    tail = node;
}

// TC: O(N)
// SC: O(1)
Node *segregate_with_overwriting(Node *head)
{
    Node *zero = new Node(-1); // dummy node
    Node *zeroTail = zero;

    Node *one = new Node(-1); // dummy node
    Node *oneTail = one;

    Node *two = new Node(-1); // dummy node
    Node *twoTail = two;

    Node *cur = head;

    while (cur != NULL)
    {
        if (cur->data == 0)
            insertAtTail(zeroTail, cur);
        else if (cur->data == 1)
            insertAtTail(oneTail, cur);
        else
            insertAtTail(twoTail, cur);

        cur = cur->next;
    }

    // merge 3 linked list

    if (one->next != NULL)
        zeroTail->next = one->next;
    // edge case: when number of 1 nodes is zero
    else
        zeroTail->next = two->next;

    oneTail->next = two->next;
    twoTail->next = NULL;

    Node *newHead = zero->next;

    // free memory
    delete zero;
    delete one;
    delete two;

    return newHead;
}

// Q2:
// Leetcode 21: Merge Two Sorted Lists
// TC: O(N + M)
// SC: O(1)
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode;
    ListNode *tail = dummy;

    // case 1: list 1 length == list 2 length

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
        // or update tail here once
        // tail = tail->next;
    }

    // case 2: list 1 is longer
    if (list1 != NULL)
        tail->next = list1;

    // case 3: list 2 is longer
    if (list2 != NULL)
        tail->next = list2;

    return dummy->next;
}

// (extra)
// Q3:
// Leetcode 23: Merge k Sorted Lists

// helper: merge two sorted lists
ListNode *merge(ListNode *one, ListNode *two)
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

// TC: O(n x log(k))
// SC: O(n)
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    // split them(linked lists) into pairs of two then sort them and merge them back
    // kind of like merge sort algorithm
    // O(log(k))
    // merging => O(n)
    // so time complexity is O(n x log(k))

    // edge case: "lists" is empty
    if (lists.size() == 0)
        return NULL;

    while (lists.size() > 1)
    {
        vector<ListNode *> mergedLists;

        for (int i = 0; i < lists.size(); i += 2)
        {
            ListNode *l1 = lists[i];
            ListNode *l2 = (i + 1) < lists.size() ? lists[i + 1] : NULL;
            mergedLists.push_back(merge(l1, l2));
        }
        lists = mergedLists;
    }

    return lists[0];
};

int main()
{

    return 0;
}