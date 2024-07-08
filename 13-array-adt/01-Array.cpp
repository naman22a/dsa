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

    // binary search
    // TC: O(log(N))
    int binary_search(T target)
    {
        int left = 0;
        int right = used_size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
                return mid;

            else if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    // TC: O(N)
    void reverse()
    {
        int left = 0, right = used_size - 1;
        while (left <= right)
            swap(arr[left++], arr[right--]);
    }

    // TC: O(N^2)
    void selection_sort()
    {
        for (int i = 0; i <= used_size - 2; i++)
        {
            int mini = i;
            for (int j = i; j <= used_size - 1; j++)
            {
                if (arr[j] < arr[mini])
                    mini = j;
            }
            swap(arr[i], arr[mini]);
        }
    }

    // TC: O(N^2)
    void bubble_sort()
    {
        for (int i = 0; i <= used_size - 2; i++)
        {
            for (int j = 0; j < used_size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }

    // TC: O(N^2)
    void insertion_sort()
    {
        for (int i = 0; i < used_size; i++)
        {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                j--;
            }
        }
    }

    // merge sort
private:
    void merge_sort_divide(int left, int right)
    {
        if (left == right)
            return;

        int mid = left + (right - left) / 2;

        merge_sort_divide(left, mid);
        merge_sort_divide(mid + 1, right);
        merge_sort_merge(left, mid, right);
    }

    void merge_sort_merge(int low, int mid, int high)
    {
        vector<T> temp;

        // [low ... mid]
        // [mid+1 ... high]
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // elements still left in the left
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // elements still left in the right
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // copy elements into the array
        for (int i = low; i <= high; i++)
            this->arr[i] = temp[i - low];
    }

public:
    // TC: O(N.log(N))
    // SC: O(2N), -> O(N) for recursive call stack and another O(N) for temporary array
    void merge_sort()
    {
        merge_sort_divide(0, used_size - 1);
    }

    // Quick Sort: Divide and Conquer Algorithm
private:
    int partition(int left, int right)
    {
        int pivot = arr[left];
        int i = left;
        int j = right;

        while (i < j)
        {
            while (arr[i] <= pivot && i <= right - 1)
                i++;

            while (arr[j] > pivot && j >= left + 1)
                j--;

            if (i < j)
                swap(arr[i], arr[j]);
        }

        swap(arr[left], arr[j]);
        return j;
    }

    void qs(int left, int right)
    {
        if (left < right)
        {
            int partitionIndex = partition(left, right);
            qs(left, partitionIndex - 1);
            qs(partitionIndex + 1, right);
        }
    }

public:
    // TC: O(N.log(N))
    // SC: O(N), for recursive call stack
    void quick_sort()
    {
        qs(0, used_size - 1);
    }

    // TODO: add radix sort, heap sort, count sort etc.
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

    // binary search
    if (0)
    {
        Array<int> arr;

        // array should be sorted
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(40);
        arr.push_back(50);

        arr.print();

        // *NOTE: first and last occurrence can also be found out using binary search in a sorted array
        cout << "Element found at index: " << arr.binary_search(50) << endl;
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

    // sorting

    // selection sort
    if (0)
    {
        Array<int> arr;
        arr.push_back(50);
        arr.push_back(40);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(10);

        arr.print();
        arr.selection_sort();
        arr.print();
    }

    // bubble sort
    if (0)
    {
        Array<int> arr;
        arr.push_back(50);
        arr.push_back(40);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(10);

        arr.print();
        arr.bubble_sort();
        arr.print();
    }

    // insertion sort
    if (0)
    {
        Array<int> arr;
        arr.push_back(50);
        arr.push_back(40);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(10);

        arr.print();
        arr.insertion_sort();
        arr.print();
    }

    // merge sort
    {
        Array<int> arr;
        arr.push_back(50);
        arr.push_back(40);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(10);

        arr.print();
        arr.merge_sort();
        arr.print();
    }

    // quick sort
    if (0)
    {
        Array<int> arr;
        arr.push_back(50);
        arr.push_back(40);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(10);

        arr.print();
        arr.quick_sort();
        arr.print();
    }

    return 0;
}
