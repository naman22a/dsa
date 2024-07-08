#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Array
{
private:
    T *arr = NULL; // base address

public:
    int used_size;
    int capacity; // total size

    Array(int capacity = 10)
    {
        this->capacity = capacity;
        this->used_size = 0;
        this->arr = (T *)malloc(capacity * sizeof(T));
        // this->arr = new T[capacity];
    }

    ~Array()
    {
        // free the allocated memory
        free(arr);
        arr = NULL;
        // delete[] arr;
    }

    // TC: O(N)
    void print()
    {
        for (int i = 0; i < used_size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // TC: O(1)
    void set(int index, T value)
    {
        // check if index is in bounds
        if (index >= 0 && index < capacity)
            arr[index] = value;
        else
        {
            cout << "Index out of bounds" << endl;
            exit(1);
        }
    }

    // TC: O(1)
    T get(int index)
    {
        // check if index is in bounds
        if (index >= 0 && index < capacity)
            return arr[index];
        else
        {
            cout << "Index out of bounds" << endl;
            return T(); // Return default value of T
        }
    }

    // TC: O(N)
    // preserve order while insertion
    bool insert(int index, T value)
    {
        // if array is full
        if (used_size >= capacity)
        {
            cout << "Array is full" << endl;
            exit(1);
        }

        // check if index is out of bounds
        if (index < 0 || index >= capacity)
        {
            cout << "Index out of bounds" << endl;
            exit(1);
        }

        // move elements
        for (int i = used_size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index] = value;
        used_size++;
    }

    // TC: O(N)
    T remove(int index)
    {
        // no more elements in the array
        if (used_size == 0)
        {
            cout << "No element present in the array" << endl;
            return T();
        }

        // check if index is out of bounds
        if (index < 0 || index >= used_size)
        {
            cout << "Index out of bounds" << endl;
            exit(1);
        }

        T removed = arr[index];

        // move the elements
        for (int i = index; i < used_size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        used_size--;
        return removed;
    }

    void push_back(T value)
    {
        this->insert(used_size, value);
    }

    T pop_back()
    {
        return this->remove(used_size - 1);
    }

    void push_front(T value)
    {
        this->insert(0, value);
    }

    T pop_front()
    {
        return this->remove(0);
    }

    // linear search
    // TC: O(N)
    int find(T target)
    {
        for (int i = 0; i < used_size; i++)
        {
            if (arr[i] == target)
                return i;
        }

        return -1;
    }

    // reverse linear search
    // TC: O(N)
    int rfind(T target)
    {
        for (int i = used_size - 1; i >= 0; i--)
        {
            if (arr[i] == target)
                return i;
        }

        return -1;
    }

    // max
    // TC: O(N)
    T max()
    {
        int highest = arr[0];
        for (int i = 0; i < used_size; i++)
        {
            if (arr[i] > highest)
                highest = arr[i];
        }
        return highest;
    }

    // min
    // TC: O(N)
    T min()
    {
        int lowest = arr[0];
        for (int i = 0; i < used_size; i++)
        {
            if (arr[i] < lowest)
                lowest = arr[i];
        }
        return lowest;
    }

    // TC: O(N)
    void reverse()
    {
        int left = 0, right = used_size - 1;
        while (left <= right)
            swap(arr[left++], arr[right--]);
    }
};

int main()
{
    // get and set
    if (0)
    {
        Array<int> arr;

        arr.set(0, 10);
        arr.set(1, 20);
        arr.print();
        cout << "Value at index 0: " << arr.get(0) << endl;

        cout << endl;
    }

    // insert
    if (0)
    {
        Array<int> arr;

        arr.set(0, 7);
        arr.set(1, 8);
        arr.set(2, 12);
        arr.set(3, 27);
        arr.set(4, 88);
        arr.used_size = 5;

        arr.print();

        arr.insert(3, 45);
        arr.insert(3, 459);
        arr.insert(3, 305);
        arr.insert(3, 915);
        arr.insert(3, 1005);
        // arr.insert(3, 8205); // array is full, as default arr capacity is 10 (defined in the constructor)

        arr.print();

        cout << endl;
    }

    // remove
    if (0)
    {
        Array<int> arr;
        arr.insert(0, 7);
        arr.insert(1, 4);
        arr.insert(2, 3);

        arr.print();
        int removed = arr.remove(5);
        cout << "Remove element: " << removed << endl;
        arr.print();

        cout << endl;
    }

    // push_back, pop_back, push_front, pop_front
    if (0)
    {
        Array<int> arr;
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);

        arr.print();

        arr.pop_back();

        arr.print();

        arr.push_front(100);

        arr.print();

        arr.pop_front();

        arr.print();

        cout << endl;
    }

    // max and min
    if (0)
    {
        Array<int> arr;
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(40);
        arr.push_back(50);

        cout << "Max: " << arr.max() << endl;
        cout << "Min: " << arr.min() << endl;
    }

    // Linear search
    if (0)
    {
        Array<int> arr;
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(30);
        arr.push_back(40);
        arr.push_back(50);

        arr.print();

        cout << "First occurrence: " << arr.find(30) << endl;
        cout << "Last occurrence: " << arr.rfind(30) << endl;
    }

    // reverse
    if (0)
    {
        Array<int> arr;
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(40);
        arr.push_back(50);

        arr.print();
        arr.reverse();
        arr.print();
    }

    return 0;
}
