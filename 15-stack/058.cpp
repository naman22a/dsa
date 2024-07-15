#include <iostream>
using namespace std;

// Q1: N Stacks in an Array
/*
Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:
push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.
pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :
Type 1: for push(X, M) operation.
Type 2: for pop(M) operation.
*/

// SC: O(S+N)
class NStack
{
private:
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s]; // s -> size of array
        top = new int[n]; // n -> no of stacks
        next = new int[s];

        // initialize top
        for (int i = 0; i < n; i++)
            top[i] = -1;

        // initialize next
        for (int i = 0; i < s; i++)
            next[i] = i + 1;
        next[s - 1] = -1; // update last index of next

        // initialize freespot
        freespot = 0;
    }

    // TC: O(1)
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for stack overflow
        if (freespot == -1)
            return false;

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // insert element in array
        arr[index] = x;

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // TC: O(1)
    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for stack underflow error
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main()
{

    return 0;
}