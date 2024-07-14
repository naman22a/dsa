#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// Q1: Reverse a string using Stack
// TC: O(N)
// SC: O(N)
string reverse_string(string s)
{
    string temp;
    stack<char> st;

    for (char ch : s)
        st.push(ch);

    while (!st.empty())
    {
        char ch = st.top();
        st.pop();
        temp.push_back(ch);
    }

    return temp;
}

// Q2: Delete Middle element from Stack
/*
Given a stack, delete the middle element of the stack without using any additional data structure.
Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.
*/
void backtrack(stack<int> &s, int size, int count)
{
    // base case
    if (count == size / 2)
    {
        s.pop();
        return;
    }

    // processing 1
    int num = s.top();
    s.pop();

    // Recurrence
    backtrack(s, size, count + 1);

    // processing 2
    // add back the number which was popped earlier
    s.push(num);
}

// TC: O(N)
// SC: O(N)
void deleteMid(stack<int> &s, int sizeOfStack)
{
    backtrack(s, sizeOfStack, 0);
}

// Q3:
// Leetcode 20: Valid Parentheses

unordered_map<char, char> brackets = {
    {')', '('},
    {']', '['},
    {'}', '{'}};

bool isOpeningBracket(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}

// TC: O(N)
// SC: O(N)
bool isValid(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (isOpeningBracket(ch))
            st.push(ch);

        // closing bracket
        // as string only consists of opening and closing brackets
        else
        {
            // stack underflow error
            if (st.empty())
                return false;
            // not matching the brackets
            if (st.top() != brackets[ch])
                return false;
            else
                st.pop();
        }
    }

    // stack should be empty for valid case
    // as every bracket should have been popped with it's pair
    return st.empty();
}

// Q4: Insert an Element at the Bottom of a Stack
/*
You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack.
Note: Everywhere in this problem, the bottommost element of the stack is shown first while priniting the stack.
*/

void bottomBacktrack(stack<int> &st, int x)
{
    // base case
    if (st.empty())
    {
        st.push(x);
        return;
    }

    // remove
    int num = st.top();
    st.pop();

    // recursion
    bottomBacktrack(st, x);

    // insert back
    st.push(num);
}

stack<int> insertAtBottom_using_backtracking(stack<int> st, int x)
{
    bottomBacktrack(st, x);
    return st;
}

stack<int> insertAtBottom_using_stack(stack<int> st, int x)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    st.push(x);

    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }

    return st;
}

// TC: O(N)
// SC: O(N)
stack<int> insertAtBottom(stack<int> st, int x)
{
    return insertAtBottom_using_stack(st, x);
}

// Q5: Reverse a Stack using Recursion
// TC: O(N)
// SC: O(N)
void Reverse(stack<int> &St)
{
    // base case: empty stack is already reversed
    if (St.empty())
        return;

    // processing
    int top = St.top();
    St.pop();

    // recurrence
    Reverse(St);

    // cleanup
    St = insertAtBottom(St, top);
}

// Q6: Sort a Stack

// helper
void sortedInsert(stack<int> &s, int num)
{
    if (s.empty() || (!s.empty() && s.top() <= num))
    {
        s.push(num);
        return;
    }

    int popped = s.top();
    s.pop();

    sortedInsert(s, num);

    s.push(popped);
}

// TC: O(N^2)
// SC: O(N)
void sortStack(stack<int> &s)
{
    // base case: empty stack is already sorted
    if (s.empty())
        return;

    int num = s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s, num);
}

// Q7: Redundant Brackets
/*
Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.
A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets. For Example : ((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless.  While (a + (b*c)) does not have any pair of redundant brackets.
*/

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// TC: O(N)
// SC: O(N)
bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (char ch : s)
    {
        if (ch == '(' || isOperator(ch))
            st.push(ch);
        else if (ch == ')')
        {
            bool isRedundant = true;
            while (st.top() != '(')
            {
                if (isOperator(st.top()))
                    isRedundant = false;
                st.pop();
            }

            if (isRedundant)
                return true;
            st.pop(); // remove the openning bracket
        }
    }

    return false;
}

// Q8: Count the Reversals / Minimum Cost To Make String Valid
/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.
*/
// TC: O(N)
// SC: O(1)
int countRev(string s)
{
    // edge case: odd length, not possible to make pairs
    if (s.length() & 1)
        return -1;

    // remove valid strings from s
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '{')
            st.push(ch);
        else
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }

    // now stack contains invalid expression
    int close = 0; // close bracket count
    int open = 0;  // open bracket count
    while (!st.empty())
    {
        if (st.top() == '{')
            open++;
        else
            close++;
        st.pop();
    }

    int count = (close + 1) / 2 + (open + 1) / 2; // how ? idk, no one in the world knows 💀
    return count;
}

// TODO: prefix, infix, postfix conversions

int main()
{
    // Reverse a string using stack
    {
        string name = "abcd";
        cout << "original: " << name << endl;
        cout << "reversed: " << reverse_string(name) << endl;
    }

    return 0;
}