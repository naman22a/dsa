#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// Queue using Arrays
class Queue_using_Array
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    Queue_using_Array(int size = 10)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Queue_using_Array()
    {
        delete[] arr;
    }

    void print()
    {
        for (int i = front + 1; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    void enqueue(int value)
    {
        if (isFull())
            cout << "Queue overflow error" << endl;
        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    int dequeue()
    {
        int value = -1;
        if (isEmpty())
            cout << "Queue underflow error" << endl;
        else
        {
            front++;
            value = arr[front];
        }

        return value;
    }

    int first()
    {
        if (isEmpty())
            return -1;
        return arr[front + 1];
    }

    int last()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    int peek(int position)
    {
        // check if queue is empty
        // check if position is out of bounds -> range -> [f + 1, r]
        if (isEmpty() || !(position >= front + 1 && position <= rear))
            return -1;

        return arr[front + position];
    }
};

// Circular Queue
// manages space efficiently
class CircularQueue
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    CircularQueue(int size = 5)
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

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void enqueue(int value)
    {
        if (isFull())
            cout << "Queue overflow error" << endl;
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = value;
        }
    }

    int dequeue()
    {
        int value = -1;

        if (isEmpty())
            cout << "Queue underflow error" << endl;
        else
        {
            front = (front + 1) % size;
            value = arr[front];
        }

        return value;
    }
};

// Queue using Linked List

class Node
{
public:
    int data;
    Node *next;
};

class Queue_using_Linked_List
{
    Node *front;
    Node *rear;

public:
    Queue_using_Linked_List()
    {
        front = NULL;
        rear = NULL;
    }

    bool isFull()
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        return newNode == NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void print()
    {
        Node *cur = front;

        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void enqueue(int value)
    {
        if (isFull())
            cout << "Queue overflow error" << endl;
        else
        {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->next = NULL;

            if (isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
    }

    int dequeue()
    {
        int value = -1;
        if (isEmpty())
            cout << "Queue underflow error" << endl;

        else
        {
            Node *temp = front;
            front = front->next;
            value = temp->data;
            free(temp);
        }
        return value;
    }
};

// Double Ended Queue / DEque
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
        Queue_using_Array q(5);
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

        q.enqueue(40);
        q.enqueue(50);
        // q.enqueue(60); // overflow error
        q.print();
        cout << "full: " << q.isFull() << endl;

        cout << "Peek(0): " << q.peek(0) << endl;
        cout << "Peek(1): " << q.peek(1) << endl;
        cout << "Peek(2): " << q.peek(2) << endl;
        cout << "Peek(3): " << q.peek(3) << endl;
        cout << "Peek(4): " << q.peek(4) << endl;
        cout << "Peek(5): " << q.peek(5) << endl; // invalid index, out of bounds, returns -1
        cout << "Peek(100): " << q.peek(100) << endl;

        cout << endl;
    }

    // Circular Queue
    {
        CircularQueue q(5);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);

        q.print();

        q.dequeue();
        q.dequeue();

        q.print();

        q.enqueue(4);
        q.enqueue(5);
        q.enqueue(6);
        // q.enqueue(7); // queue overflow error

        q.print();

        cout << endl;
    }

    // Queue using Linked List
    {
        Queue_using_Linked_List queue;

        queue.enqueue(34);
        queue.enqueue(22);
        queue.enqueue(1);

        queue.print();

        queue.dequeue();
        // queue.dequeue();
        // queue.dequeue();
        // queue.dequeue(); // underflow error

        queue.print();
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

    // Double Ended Queue
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
