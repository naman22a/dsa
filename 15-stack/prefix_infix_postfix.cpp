#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool isOperand(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

unordered_map<char, int> priority = {
    {'^', 3},
    {'*', 2},
    {'/', 2},
    {'+', 1},
    {'-', 1},
    {'(', -1},
    {')', -1}};

// Q1: Infix to Postfix
// TC: O(N)
// SC: O(N)
string infixToPostfix(string s)
{
    int i = 0;
    stack<char> st;
    string ans;

    while (i < s.length())
    {
        char ch = s[i];
        // if operand, push it to the ans
        if (isOperand(ch))
            ans.push_back(ch);

        // is openning bracket
        else if (ch == '(')
            st.push(ch);

        // is closing bracket
        else if (ch == ')')
        {
            // keep popping out till stack.empty or openning bracket found
            while (!st.empty() && st.top() != '(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop(); // remove the openning bracket
        }

        // is operator
        else
        {
            while (!st.empty() && priority[ch] <= priority[st.top()])
            {
                ans.push_back(st.top());
                st.pop();
            }

            st.push(ch);
        }

        i++;
    }

    // if stack still contains some operators
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

// Q2: Infix to Prefix
// TC: O(N)
// SC: O(N)
string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    // swap openning and closing brackets
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {

            s[i] = ')';
            continue;
        }
        if (s[i] == ')')
        {
            s[i] = '(';
            continue;
        }
    }

    string ans = infixToPostfix(s);
    reverse(ans.begin(), ans.end());
    return ans;
}

// Q3: Postfix to Infix
// TC: O(N)
// SC: O(N)
string postfixToInfix(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // if operand
        if (isOperand(ch))
            st.push(string(1, ch));

        // if operator
        else
        {
            string exp1 = st.top();
            st.pop();
            string exp2 = st.top();
            st.pop();

            st.push("(" + exp2 + string(1, ch) + exp1 + ")");
        }
    }
    return st.top();
}

// Q4: Prefix to Infix
// TC: O(N)
// SC: O(N)
string prefixToInfix(string s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (isOperand(ch))
            st.push(string(1, ch));

        // is operator
        else
        {
            string exp1 = st.top();
            st.pop();
            string exp2 = st.top();
            st.pop();

            st.push("(" + exp1 + string(1, ch) + exp2 + ")");
        }
    }
    return st.top();
}

// Q5: Postfix to Prefix
// TC: O(N)
// SC: O(N)
string postfixToPrefix(string s)
{
    stack<string> st;
    for (auto ch : s)
    {
        if (isOperand(ch))
            st.push(string(1, ch));
        else
        {
            string exp1 = st.top();
            st.pop();
            string exp2 = st.top();
            st.pop();

            st.push(string(1, ch) + exp2 + exp1);
        }
    }
    return st.top();
}

// Q6: Prefix to Postfix
// TC: O(N)
// SC: O(N)
string prefixToPostfix(string s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (isOperand(ch))
            st.push(string(1, ch));
        else
        {
            string exp1 = st.top();
            st.pop();
            string exp2 = st.top();
            st.pop();

            st.push(exp1 + exp2 + string(1, ch));
        }
    }
    return st.top();
}

// Q7: Evaluation of Postfix expression
// Leetcode 150: Evaluate Reverse Polish Notation
// TC: O(N)
// SC: O(N)

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (string token : tokens)
    {
        // if operand
        if (token.size() > 1 || isdigit(token.at(0)))
        {
            st.push(stoi(token));
        }
        // if operator
        else
        {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();

            int result = 0;
            if (token == "+")
                result = first + second;
            if (token == "-")
                result = first - second;
            if (token == "*")
                result = first * second;
            if (token == "/")
                result = first / second;
            st.push(result);
        }
    }

    return st.top();
}

int main()
{

    // Infix to Postfix
    {
        string infix = "a+b*(c^d-e)";
        cout << "infix: " << infix << endl;
        string postfix = infixToPostfix(infix);
        cout << "postfix: " << postfix << endl;
        cout << endl;
    }

    // Infix to Prefix
    {
        string infix = "a+b*(c^d-e)";
        cout << "infix: " << infix << endl;
        string prefix = infixToPrefix(infix);
        cout << "prefix: " << prefix << endl;
        cout << endl;
    }

    // Postfix to Infix
    {
        string postfix = "abcd^e-*+";
        cout << "postfix: " << postfix << endl;
        string infix = postfixToInfix(postfix);
        cout << "infix: " << infix << endl;
        cout << endl;
    }

    // Prefix to Infix
    {
        string prefix = "+a*b-^cde";
        cout << "prefix: " << prefix << endl;
        string infix = prefixToInfix(prefix);
        cout << "infix: " << infix << endl;
        cout << endl;
    }

    // Postfix to Prefix
    {
        string postfix = "abcd^e-*+";
        cout << "postfix: " << postfix << endl;
        string prefix = postfixToPrefix(postfix);
        cout << "prefix: " << prefix << endl;
        cout << endl;
    }

    // Prefix to Postfix
    {
        string prefix = "+a*b-^cde";
        cout << "prefix: " << prefix << endl;
        string postfix = prefixToPostfix(prefix);
        cout << "postfix: " << postfix << endl;
        cout << endl;
    }

    return 0;
}
