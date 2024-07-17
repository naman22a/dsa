#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// TODO: update this accordingly for Array and Circular Queue Implementation
// TODO: Implement Stack using Queue, Queue using Stack ... do these types of questions
// see this for different implementation of Queue
// https://github.com/naman22a/dsa-cwh/tree/main/4-Queue

class Queue_using_Array
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue_using_Array(int size = 10)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    ~Queue_using_Array()
    {
        delete[] arr;
    }

    void print()
    {
        cout << "---" << endl;
        for (int i = front; i <= rear - 1; i++)
            cout << arr[i] << endl;
        cout << "---" << endl;
    }

    bool isFull()
    {
        return rear == size;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }

        arr[rear] = value;
        rear++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // arr[front] = -1; // -1 denotes empty location // no need for this line actually
        front++;
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
    }

    int first()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int last()
    {
        if (isEmpty())
            return -1;
        return arr[rear - 1];
    }
};

class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int size = 10)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void enqueue(int value)
    {
        if (isFull())
            cout << "Queue is full" << endl;
        // push first element
        else if (front == -1)
            front = rear = 0;
        // to maintain cyclic nature
        else if (rear == size - 1 && front != 0)
            rear = 0;
        // normal flow
        else
            rear++;
        arr[rear] = value;
    }

    void dequeue()
    {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        // single element is present
        else if (front == rear)
            front = rear = -1;
        // to maintain cyclic nature
        else if (front == size - 1)
            front = 0;
        // normal flow
        else
            front++;
    }
};

// Queue using Linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next) : data(data), next(next) {}
};

// Queue using Linked List

class Queue_using_Linked_List
{
    Node *front = NULL;
    Node *rear = NULL;

public:
    bool isEmpty()
    {
        return front == NULL;
    }

    void show()
    {
        if (isEmpty())
            cout << "Queue is Empty" << endl;
        else
        {
            Node *p = front;
            while (p != NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data, NULL);
        if (newNode == NULL)
            cout << "Queue is Full" << endl;
        else
        {
            if (isEmpty())
                front = rear = newNode;
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            Node *ptr = front;
            front = front->next;
            int value = ptr->data;
            delete ptr;
            return value;
        }
    }
};

// Double ended Queue / Deque
// insertion and deletion from both ends

class DEQueue
{
    int size;
    int front;
    int rear;
    int *arr;

public:
    DEQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    ~DEQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    void show()
    {
        for (int i = front + 1; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void enqueueRear(int value)
    {
        if (isFull())
            cout << "Queue overflow error" << endl;
        else
        {
            rear += 1;
            arr[rear] = value;
        }
    }

    void enqueFront(int value)
    {
        if (isFull())
            cout << "Queue overflow error" << endl;
        else if (front == -1)
            cout << "Can not add item from front" << endl;
        else
        {
            arr[front] = value;
            front--;
        }
    }

    int dequeueFront()
    {
        if (isEmpty())
        {
            cout << "Queue underflow error" << endl;
            return -1;
        }
        else
        {
            front++;
            int x = arr[front];
            return x;
        }
    }

    int dequeueRear()
    {
        if (isEmpty())
        {
            cout << "Queue underflow error" << endl;
            return -1;
        }
        else
        {
            int x = arr[rear];
            rear--;
            return x;
        }
    }
};

int main()
{

    // Queue using STL
    {
        queue<int> q;
        q.push(10);
        q.push(20);
        q.push(30);

        cout << "size: " << q.size() << endl;

        while (!q.empty())
        {
            cout << q.front() << endl;
            q.pop();
        }

        cout << "empty: " << q.empty() << endl;
        cout << endl;
    }

    // Queue using Array
    {
        Queue_using_Array q;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        q.print();

        q.dequeue();
        q.print();

        cout << "empty: " << q.isEmpty() << endl;
        cout << "full: " << q.isFull() << endl;
        cout << "first: " << q.first() << endl;
        cout << "last: " << q.last() << endl;

        cout << endl;
    }

    // Queue using Linked List
    {
        Queue_using_Linked_List queue;

        queue.enqueue(34);
        queue.enqueue(22);
        queue.enqueue(1);

        queue.show();

        queue.dequeue();

        queue.show();
        cout << endl;
    }

    // Deque using STL
    {
        deque<int> q;

        q.push_back(56);
        q.push_back(11);
        q.push_back(32);
        q.push_back(44);

        for (auto e : q)
            cout << e << " ";
        cout << endl;

        q.pop_front();
        for (auto e : q)
            cout << e << " ";
        cout << endl;

        q.push_front(77);
        for (auto e : q)
            cout << e << " ";
        cout << endl;

        q.pop_back();
        for (auto e : q)
            cout << e << " ";
        cout << endl;

        cout << endl;
    }

    // Double ended Queue
    {
        DEQueue queue(10);

        queue.enqueueRear(56);
        queue.enqueueRear(11);
        queue.enqueueRear(32);
        queue.enqueueRear(44);

        queue.show();
        queue.dequeueFront();
        queue.show();
        queue.enqueFront(77);
        queue.show();
        queue.dequeueRear();
        queue.show();
        cout << endl;
    }

    return 0;
}
