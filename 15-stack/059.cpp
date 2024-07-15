#include <iostream>
#include <stack>
using namespace std;

// Q1:
// Leetcode 155: Min Stack
class MinStack
{
private:
    stack<int> st;
    stack<int> minStack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        val = minStack.empty() ? val : min(val, minStack.top());
        minStack.push(val);
    }

    void pop()
    {
        st.pop();
        minStack.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{

    return 0;
}