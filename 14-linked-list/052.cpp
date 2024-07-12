#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Q1:
// Leetcode 138: Copy List With Random Pointer
// TC: O(N)
// SC: O(N)
Node *copyRandomList(Node *head)
{
    // we will do this solution in 2 passes
    // first pass:
    //          - create a copy of the nodes present in the linked list (no linking)
    //          - create hashmap(original node -> new node)
    // second pass:
    //          - pointer connections

    unordered_map<Node *, Node *> original_to_new;
    original_to_new.insert({NULL, NULL}); // edge case

    // first pass
    Node *current = head;
    while (current != NULL)
    {
        Node *copy = new Node(current->val); // deep copy node
        original_to_new[current] = copy;
        current = current->next;
    }

    // second pass
    current = head;
    while (current != NULL)
    {
        Node *copy = original_to_new[current];
        copy->next = original_to_new[current->next];
        copy->random = original_to_new[current->random];

        current = current->next;
    }

    return original_to_new[head];
}

int main()
{

    return 0;
}