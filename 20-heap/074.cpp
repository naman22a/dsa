#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// *NOTE: all follow 1 based indexing

class MaxHeap
{
    int *arr;
    int capacity;
    int size;

public:
    MaxHeap(int capacity = 100)
    {
        this->capacity = capacity;

        // implementation using static array
        this->arr = new int[this->capacity + 1]; // 1 index based array
        this->size = 0;
    }

    ~MaxHeap()
    {
        delete[] arr;
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // TC: O(log(N))
    // SC: O(1)
    void insert(int value)
    {
        if (size == capacity)
        {
            printf("Heap is full");
            return;
        }

        size++;
        arr[size] = value;
        int index = size;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                break;
        }

        // alternatively
        /*
        int parent = index / 2;
        while (index > 1 && arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
            parent = index / 2;
        }
        */
    }

    void remove()
    {
        if (size == 0)
        {
            printf("Heap is empty");
            return;
        }

        arr[1] = arr[size];
        size--;

        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // to check if left is in bounds -> "leftIndex < size"
            if (leftIndex < size && arr[index] < arr[leftIndex])
            {
                swap(arr[index], arr[leftIndex]);
                index = leftIndex;
            }

            else if (rightIndex < size && arr[index] < arr[rightIndex])
            {
                swap(arr[index], arr[rightIndex]);
                index = rightIndex;
            }
            else
                break;
        }
    }
};

// TC: O(log(N))
// SC: O(log(N))
void heapify(int arr[], int n, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

// TC: O(N)
// SC: O(log(N))
void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        heapify(arr, n, i);
}

// TC: O(N.log(N))
// SC: O(log(N))
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n; i > 1; i--)
    {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
    }
}

int main()
{
    // Heap: insertion and deletion
    {
        MaxHeap heap;
        heap.insert(10);
        heap.insert(20);
        heap.insert(30);
        heap.insert(40);

        heap.print();

        heap.remove();

        heap.print();
    }

    // Heap using STL
    {
        priority_queue<int> pq;                             // max heap
        priority_queue<int, vector<int>, greater<int>> pq2; // min heap

        pq.push(10);
        pq.push(30);
        pq.push(20);
        pq.push(40);

        cout << pq.top() << endl;
        pq.pop();
        cout << pq.top() << endl;
        cout << pq.empty() << endl;
        cout << pq.size() << endl;
    }

    return 0;
}