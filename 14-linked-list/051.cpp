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

// Q1:
// Leetcode 2: Add Two Numbers
// TC: O(N)
// SC: O(N) or O(1), include or exclude output space as extra memory
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode;
    ListNode *cur = dummy; // kind of like a tail pointer

    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        int value1 = (l1 != NULL) ? l1->val : 0;
        int value2 = (l2 != NULL) ? l2->val : 0;

        int value = value1 + value2 + carry;

        // what if the number is a 2 digits number
        carry = value / 10;
        int digit = value % 10;

        // add digit to linked list
        cur->next = new ListNode(digit);

        // update pointers
        cur = cur->next;

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }

    // edge case: handle carry (end wala)
    if (carry == 1)
        cur->next = new ListNode(1);

    return dummy->next;
}

int main()
{

    return 0;
}