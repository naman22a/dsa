#include <iostream>
using namespace std;

template <class T>
class DynamicArray
{
private:
    T *arr = NULL; // base address
    int used_size;
    int capacity; // total size

    void increase_capacity()
    {
        if (this->capacity == 0)
            this->capacity = 1;
        else
            this->capacity = this->capacity * 2;

        // reallocate the memory
        this->arr = (int *)realloc(this->arr, sizeof(int) * this->capacity);
    }

    void decrease_capacity()
    {
        this->capacity = this->capacity / 2;

        // reallocate the memory
        this->arr = (int *)realloc(this->arr, sizeof(int) * this->capacity);
    }

    // TC: O(N)
    // preserve order while insertion
    bool insert(int index, T value)
    {
        // if array is full
        if (used_size >= capacity)
        {
            increase_capacity();
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

        if (used_size * 2 == capacity)
            decrease_capacity();

        return removed;
    }

public:
    DynamicArray(int capacity = 0)
    {
        this->capacity = capacity;
        this->arr = (int *)malloc(sizeof(int) * this->capacity);
        this->used_size = 0;
    }

    ~DynamicArray()
    {
        free(arr);
        arr = NULL;
    }

    int size()
    {
        return used_size;
    }

    int max_size()
    {
        return capacity;
    }

    void print()
    {
        for (int i = 0; i < used_size; i++)
            cout << arr[i] << " ";
        cout << endl;
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
};

int main()
{
    DynamicArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    arr.print();

    cout << "Size: " << arr.size() << endl;
    cout << "Max Size: " << arr.max_size() << endl;

    arr.pop_back();
    arr.pop_back();

    arr.print();

    cout << "Size: " << arr.size() << endl;
    cout << "Max Size: " << arr.max_size() << endl;

    return 0;
}