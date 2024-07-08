#include <iostream>
using namespace std;

// Singly Linked List

class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList() : head(NULL) {}

    SinglyLinkedList(int data)
    {
        head = new Node(data);
        // cout << head->data << endl;
        // cout << head->next << endl;
    }

    // 1. Traversal

    // TC: O(N)
    // SC: O(1)
    void print()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " --> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // 2. Insertion

    // TC: O(1)
    // SC: O(1)
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // TC: O(N), could have kept track of tail(Node*) pointer to make the insertion O(1)
    // SC: O(1)
    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);

        Node *current = head;
        while (current->next != NULL)
            current = current->next;
        // now current holds the last node

        current->next = newNode;
        newNode->next = NULL; // it as already set by the Node's constructor btw 🙃
    }

    // TC: O(N)
    // SC: O(1)
    void insertAtPosition(int data, int position)
    {
        // edge case: insert at head
        // for insertion previous node is required, so our general code fails this edge case
        if (position == 1)
        {
            this->insertAtHead(data);
            return;
        }

        Node *newNode = new Node(data);

        // travel to (position - 1)th node
        Node *current = head;

        int i = 1;
        while (i < position - 1)
        {
            current = current->next;
            i++;
        }

        // now the current node holds the (postion - 1)th node
        newNode->next = current->next;
        current->next = newNode;
    }

    // 3. Deletion

    // TC: O(1)
    // SC: O(1)
    void deleteAtHead()
    {
        Node *current = head;
        head = head->next;
        delete current;
    }

    // TC: O(N)
    // SC: O(1)
    void deleteAtTail()
    {
        Node *current = head;

        // move current to second last node
        while (current->next->next != NULL)
            current = current->next;

        // now current is pointing to second last node
        Node *temp = current->next;
        current->next = NULL;
        delete temp;
    }

    // delete at position
    // TC: O(N)
    // SC: O(1)
    void deleteAtPosition(int position)
    {
        // edge case: deletion at head
        if (position == 1)
        {
            this->deleteAtHead();
            return;
        }

        // travel to (position - 1)th node
        Node *current = head;

        int i = 1;
        while (i < position - 1)
        {
            current = current->next;
            i++;
        }

        // now the current points to (position - 1)th node
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // delete at value
    // TC: O(N)
    // SC: O(1)
    void deleteAtValue(int data)
    {
        Node *current = head;

        // edge case: deletion at head
        if (current->data == data)
        {
            this->deleteAtHead();
            return;
        }

        while (current != NULL || current->next->data != data)
            current = current->next;

        // now the current points to (position - 1)th node
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
};

// Doubly Linked List

class DoublyNode
{
public:
    int data;
    DoublyNode *prev; // previous
    DoublyNode *next;

    DoublyNode() : data(0), prev(NULL), next(NULL) {}
    DoublyNode(int data) : data(data), prev(NULL), next(NULL) {}
};

class DoublyLinkedList
{
private:
    DoublyNode *head;

public:
    DoublyLinkedList() : head(NULL) {}
    DoublyLinkedList(int data)
    {
        head = new DoublyNode(data);
    }

    // TC: O(N)
    // SC: O(1)
    void print()
    {
        DoublyNode *current = head;
        cout << "NULL <--> ";
        while (current != NULL)
        {
            cout << current->data << " <--> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // TC: O(N)
    // SC: O(1)
    int size()
    {
        DoublyNode *current = head;
        int length = 0;

        while (current != NULL)
        {
            current = current->next;
            length++;
        }

        return length;
    }

    // TC: O(1)
    // SC: O(1)
    void insertAtHead(int data)
    {
        DoublyNode *newNode = new DoublyNode(data);
        newNode->next = head;
        newNode->prev = NULL; // ik the constructor has already set this, but still

        head->prev = newNode;
        head = newNode;
    }

    // TC: O(N)
    // SC: O(1)
    void insertAtTail(int data)
    {
        DoublyNode *newNode = new DoublyNode(data);

        DoublyNode *current = head;

        while (current->next != NULL)
            current = current->next;

        // now current points to last node
        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
    }

    // TC: O(N)
    // SC: O(1)
    void insertAtPosition(int data, int position)
    {
        // edge case
        if (position == 1)
        {
            this->insertAtHead(data);
            return;
        }

        DoublyNode *current = head;
        int i = 1;
        while (i < position - 1)
        {
            current = current->next;
            i++;
        }

        // edge case
        if (current->next == NULL)
        {
            this->insertAtTail(data);
            return;
        }

        DoublyNode *newNode = new DoublyNode(data);
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }

    // TC: O(1)
    // SC: O(1)
    void deleteAtHead()
    {
        DoublyNode *current = head;
        current->next->prev = NULL;
        head = current->next;
        current->next = NULL;
        delete current;
    }

    // TC: O(N)
    // SC: O(1)
    void deleteAtPosition(int position)
    {
        // edge case
        if (position == 1)
        {
            this->deleteAtHead();
            return;
        }

        DoublyNode *current = head;
        DoublyNode *previous = NULL;

        int i = 1;
        while (i < position)
        {
            previous = current;
            current = current->next;
            i++;
        }

        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;

        delete current;
    }
};

// Circular Linked List
// tail pointer can used to access the first node also ( head = tail->next )
// so will we implement the circular linked list only using a single tail pointer

class CircularLinkedList
{
private:
    Node *tail;

public:
    CircularLinkedList() : tail(NULL) {}

    // 1. Traversal

    void print()
    {
        if (tail == NULL)
        {
            cout << "List is Empty " << endl;
            return;
        }

        Node *current = tail->next;
        do
        {
            cout << current->data << " --> ";
            current = current->next;
        } while (current != tail->next);

        cout << "Back to start" << endl;
    }

    // 2. Insertion

    void insertAtValue(int node, int data)
    {
        Node *newNode = new Node(data);

        if (tail == NULL)
        {
            tail = newNode;
            newNode->next = tail;
            return;
        }

        // assume that node is present in the linked list
        Node *current = tail->next;
        do
        {
            if (current->data == node)
            {
                newNode->next = current->next;
                current->next = newNode;

                // update tail if we inserted after the last node
                if (current == tail)
                    tail = newNode;

                return;
            }
            current = current->next;
        } while (current != tail->next);

        // node not found
        // avoid memory leak
        delete newNode;
    }

    // 3. Deletion

    void deleteAtValue(int value)
    {
        // empty list
        if (tail == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        // assuming that value exists in the linked list
        Node *prev = tail;
        Node *cur = prev->next;

        while (cur->data != value)
        {
            prev = prev->next;
            cur = cur->next;
        }

        prev->next = cur->next;

        // edge case: 1 node
        if (cur == prev)
            tail = NULL;

        // edge case: >= 2 nodes
        else if (cur == tail)
            tail = prev;

        cur->next = NULL;
        delete cur;
    }
};

int main()
{
    // Singly Linked List
    {
        SinglyLinkedList list(10);

        // 1. Traversal

        list.print();

        // 2. Insertion

        // insert at head
        list.insertAtHead(12);
        list.print();

        // insert at tail
        list.insertAtTail(40);
        list.print();

        // insert at position
        list.insertAtPosition(20, 3);
        list.insertAtPosition(100, 1);
        list.insertAtPosition(99, 6);
        list.print();

        // 3. Deletion

        // delete at head
        list.deleteAtHead();
        list.print();

        // delete at tail
        list.deleteAtTail();
        list.print();

        // delete at position
        list.deleteAtPosition(3);
        list.print();

        // delete at value
        list.deleteAtValue(12);
        list.print();

        cout << endl;
    }

    // Doubly Linked List
    {
        DoublyLinkedList list(10);

        // 1. Traversal
        list.print();

        // 2. Find length / size
        cout << "Length: " << list.size() << endl;

        // 3. Insertion

        list.insertAtHead(20);
        list.insertAtHead(30);
        list.print();

        list.insertAtTail(40);
        list.print();

        list.insertAtPosition(50, 3);
        list.print();

        // 3. Deletion

        list.deleteAtPosition(3);
        list.print();
    }

    // Circular Linked List
    {
        CircularLinkedList list;

        list.insertAtValue(10010, 10);
        list.insertAtValue(10, 20);
        list.insertAtValue(20, 30);
        list.print();

        list.deleteAtValue(30);
        list.deleteAtValue(20);
        list.print();
    }

    return 0;
}