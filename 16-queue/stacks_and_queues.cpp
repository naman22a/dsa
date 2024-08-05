#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Q1:
// Leetcode 225: Implement Stack using Queues

// using 2 Queues
// SC: O(N)
class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    // TC: O(N)
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    // TC: O(1)
    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    // TC: O(1)
    int top()
    {
        return q1.front();
    }

    // TC: O(1)
    bool empty()
    {
        return q1.empty();
    }
};

// using 1 Queue
// SC: O(N)
class MyStack_
{
private:
    queue<int> q;

public:
    MyStack_() {}

    // TC: O(N)
    void push(int x)
    {
        int size = q.size();

        q.push(x);

        // reverse the rest of the queue
        for (int i = 1; i <= size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // TC: O(1)
    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    // TC: O(1)
    int top()
    {
        return q.front();
    }

    // TC: O(1)
    bool empty()
    {
        return q.empty();
    }
};

// Q2:
// Leetcode 232: Implement Queue using Stacks

// optimized for pop operations
// SC: O(N)
class MyQueue_
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue_() {}

    // TC: O(N)
    void push(int x)
    {
        // s1 --> s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // add element in s1
        s1.push(x);

        // s2 --> s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // TC: O(1)
    int pop()
    {
        int x = s1.top();
        s1.pop();
        return x;
    }

    // TC: O(1)
    int peek()
    {
        return s1.top();
    }

    // TC: O(1)
    bool empty()
    {
        return s1.empty();
    }
};

// optimized for push operations
// SC: O(N)
class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    // TC: O(1)
    void push(int x)
    {
        s1.push(x);
    }

    // TC: O(N)
    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    // TC: O(N)
    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // TC: O(1)
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{

    return 0;
}