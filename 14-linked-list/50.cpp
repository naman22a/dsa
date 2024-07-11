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
// Leetcode 234: Palindrome Linked List
// TC: O(N)
// SC: O(1)
bool isPalindrome(ListNode *head)
{
    // 1. Find middle of the linked list
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
        slow = slow->next, fast = fast->next->next;

    ListNode *middle = slow;

    // now we can use a similar approach to array/string palindrome
    // but we can't go back in a linked list
    // so we reverse the linked list after the middle pointer

    // 2. Reverse the second half
    ListNode *prev = NULL;
    while (middle != NULL)
    {
        ListNode *temp = middle->next;
        middle->next = prev;
        prev = middle;
        middle = temp;
    }

    // 3. Check Palindrome
    ListNode *left = head;
    ListNode *right = prev; // head of the new reversed linked list

    while (right != NULL)
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

int main()
{

    return 0;
}