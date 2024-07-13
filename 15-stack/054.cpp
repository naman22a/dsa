#include <iostream>
#include <stack>
using namespace std;

// Stack using Array

template <class T>
class Stack_using_Array
{
private:
    int top;
    int size;
    T *arr;

public:
    Stack_using_Array(int size = 10)
    {
        this->top = -1;
        this->size = size;
        this->arr = (T *)malloc(sizeof(T) * size);
    }

    ~Stack_using_Array()
    {
        free(arr);
    }

    // i should not but still (bad practice)
    void print()
    {
        cout << "---" << endl;
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
        cout << "---" << endl;
    }

    bool isFull()
    {
        // top at last index of the array
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(T data)
    {
        if (isFull())
            cout << "Stack overflow error" << endl;
        else
        {

            top++;
            arr[top] = data;
        }
    }

    T pop()
    {
        if (isFull())
        {
            cout << "Stack underflow error" << endl;
            return T(); // default value of data type T
        }
        else
        {

            T popped = arr[top];
            top--;
            return popped;
        }
    }

    T stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow error" << endl;
            return T();
        }

        return arr[top];
    }

    T stackBottom()
    {
        if (isEmpty())
        {
            cout << "Stack underflow error" << endl;
            return T();
        }

        return arr[0];
    }

    // returns the element at a position
    /*
    position(i)  data  index
    1            60    2
    2            78    1
    3            4     0
    */
    T peek(int position)
    {
        // position + index = length of stack
        // length of stack = top + 1
        int index = top + 1 - position;
        if (index < 0)
            return T();
        else
            return arr[index];
    }
};

// Stack using Linked List
// (Dynamic stack with unlimited size)
// size is limited by the memory usage

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node() : data(T()), next(NULL) {}
    Node(T data) : data(data), next(NULL) {}
    Node(T data, Node *next) : data(data), next(next) {}
};

// perform insertion and deletion on linked list's head in O(1) time complexity
template <class T>
class Stack_using_LinkedList
{
    Node<T> *head;

    void insertAtHead(int data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    T deleteAtHead()
    {
        Node<T> *temp = head;
        T data = head->data;
        head = head->next;
        delete temp;
        return data;
    }

public:
    Stack_using_LinkedList()
    {
        head = NULL;
    }

    void print()
    {
        cout << "---" << endl;
        Node<T> *cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << endl;
            cur = cur->next;
        }
        cout << "---" << endl;
    }

    bool isFull()
    {
        // i am implementing a dynamic stack
        // so it is full when we can not allocate any more memory
        Node<T> *newNode = (Node<T> *)malloc(sizeof(Node<T>));
        return newNode == NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        if (isFull())
            cout << "stack overflow error" << endl;
        else
            insertAtHead(data);
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow error" << endl;
            return T();
        }
        else
            return deleteAtHead();
    }

    T stackTop()
    {
        return head->data;
    }

    T stackBottom()
    {
        Node<T> *last = head;
        while (last->next != NULL)
            last = last->next;
        return last->data;
    }

    T peek(int position)
    {
        Node<T> *cur = head;
        while (position - 1 > 0)
        {
            cur = cur->next;
            position--;
        }
        return cur->data;
    }
};

// Q1: 2 Stacks in an Array
// https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/

class TwoStacks
{
    // stack 1 insertion and deletion from left side
    // stack 2 insertion and deletion from right side
    // do not use n/2 logic, for space optimization

    int top1;
    int top2;
    int size;
    int *arr;

public:
    TwoStacks()
    {
        int size = 100; // given in question
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    ~TwoStacks()
    {
        delete[] arr;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        // space is available
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = x;
        }
        // else "Stack overflow error"
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        // space is available
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = x;
        }
        // else "Stack overflow error"
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 >= 0)
        {
            int popped = arr[top1];
            top1--;
            return popped;
        }
        else
            return -1;
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 < size)
        {
            int popped = arr[top2];
            top2++;
            return popped;
        }
        else
            return -1;
    }
};

int main()
{

    // Stack using STL
    {
        stack<int> s;

        s.push(1);
        s.push(2);
        s.push(3);

        s.pop();

        cout << "top: " << s.top() << endl; // 2

        cout << "is empty: " << s.empty() << endl;

        // traversal
        while (!s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }

        cout << "is empty: " << s.empty() << endl;
        cout << "size: " << s.size() << endl;
        cout << endl;
    }

    // Stack using Array
    {
        Stack_using_Array<int> s;

        s.push(10);
        s.push(20);
        s.push(30);

        s.print();
        cout << endl;

        s.pop();
        s.print();
        cout << endl;

        cout << "Empty: " << s.isEmpty() << endl;
        cout << "Full: " << s.isFull() << endl;

        cout << "Stack top: " << s.stackTop() << endl;
        cout << "Stack bottom: " << s.stackBottom() << endl;

        s.print();

        cout << "Peek(1): " << s.peek(1) << endl;
        cout << "Peek(2): " << s.peek(2) << endl;
        cout << endl;
    }

    // Stack using Linked List
    {
        Stack_using_LinkedList<int> s;

        s.push(10);
        s.push(20);
        s.push(30);

        s.print();
        cout << endl;

        s.pop();
        s.print();
        cout << endl;

        cout << "Empty: " << s.isEmpty() << endl;
        cout << "Full: " << s.isFull() << endl;

        cout << "Stack top: " << s.stackTop() << endl;
        cout << "Stack bottom: " << s.stackBottom() << endl;

        s.print();

        cout << "Peek(1): " << s.peek(1) << endl;
        cout << "Peek(2): " << s.peek(2) << endl;
        cout << endl;
    }

    return 0;
}