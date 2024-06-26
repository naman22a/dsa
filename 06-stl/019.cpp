#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// *NOTE: see this https://cplusplus.com/reference/stl/

int main()
{
    // 1. Array
    {
        int basic[] = {1, 2, 3};

        array<int, 4> arr = {1, 2, 3, 4}; // static array

        int size = arr.size();

        // iterate over an array
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " "; // or arr.at(i)
        cout << endl;
        // or
        for (auto element : arr)
            cout << element << " ";
        cout << endl;

        // element at index i using arr.at(i)
        cout << "Element at index 2: " << arr[2] << endl;
        cout << "Element at index 2: " << arr.at(2) << endl;

        // check if array is empty or not
        cout << "Array empty ?: " << arr.empty() << endl;

        // first and last element
        cout << "First: " << arr.front() << endl;
        cout << "Last: " << arr.back() << endl;

        cout << endl;
    }

    // 2. Vector: Dynamic Array
    {
        // when a vector is full then it doubles it's size to make space for the new elements
        vector<int> v; // size is zero by default

        cout << "Capacity: " << v.capacity() << endl; // 0

        // add elements to vector
        v.push_back(10);
        cout << "Capacity: " << v.capacity() << endl; // 1

        v.push_back(20);
        cout << "Capacity: " << v.capacity() << endl; // 2

        v.push_back(30);
        cout << "Capacity: " << v.capacity() << endl; // 4
        cout << "Size:     " << v.size() << endl;     // 3

        // access element
        cout << "Element at index 2: " << v[2] << endl;
        cout << "Element at index 2: " << v.at(2) << endl;

        // first and last element
        cout << "First: " << v.front() << endl;
        cout << "Last: " << v.back() << endl;

        // before
        for (auto e : v)
            cout << e << " ";
        cout << endl;

        // remove last element
        v.pop_back();

        // after
        for (auto e : v)
            cout << e << " ";
        cout << endl;

        // clear: remove all elements
        cout << "Size: " << v.size() << endl;
        v.clear();
        cout << "Size: " << v.size() << endl;

        // initialize
        // vector<int> a(length, initial_value) // default value of initial_value is zero
        vector<int> a(5, 1); // -> { 1, 1, 1, 1, 1 }
        for (auto e : a)
            cout << e << " ";
        cout << endl;

        // copy one vector into another
        vector<int> another(a);
        for (auto e : another)
            cout << e << " ";
        cout << endl;

        // iterator
        vector<int> v2 = {1, 2, 3, 4, 5};

        cout << "First: " << (*v2.begin()) << endl;
        cout << "Second: " << (*(v2.begin() + 1)) << endl;

        cout << endl;
    }

    // 3. DEque: Doubly Ended Queue -> insertion and deletion from both front and back
    {
        deque<int> d;

        // add elements
        d.push_back(10);
        d.push_front(20);

        // print
        for (int i : d)
            cout << i << " ";
        cout << endl;

        // remove elements
        // d.pop_back();
        d.pop_front();

        for (int i : d)
            cout << i << " ";
        cout << endl;

        d.push_back(30);
        d.push_back(40);

        for (int i : d)
            cout << i << " ";
        cout << endl;

        // access an element
        cout << "First index: " << d[1] << endl;
        cout << "First index: " << d.at(1) << endl;

        // first and last element
        cout << "First: " << d.front() << endl;
        cout << "Last: " << d.back() << endl;

        // empty
        cout << "Empty: " << d.empty() << endl;

        // size
        cout << "Size: " << d.size() << endl;

        // delete element from middle
        // d.erase(from, to);

        for (int i : d)
            cout << i << " ";
        cout << endl;
        d.erase(d.begin(), d.begin() + 1); // delete first element
        for (int i : d)
            cout << i << " ";
        cout << endl;

        // max_size: the memory allocated to the container, it remains constant throughout the execution of the program

        cout << endl;
    }

    // 4. List: Doubly Linked List
    {
        list<int> l;

        // most of the methods are same

        // add
        l.push_back(1);
        l.push_front(2);

        for (int e : l)
            cout << e << " ";
        cout << endl;

        // erase
        l.erase(l.begin());
        for (int e : l)
            cout << e << " ";
        cout << endl;

        // size
        cout << "Size: " << l.size() << endl;

        // copy
        list<int> c(l);

        // initialize
        list<int> c1(5, 100);

        for (int e : c1)
            cout << e << " ";
        cout << endl;
    }

    // 5. Stack: LIFO(Last in First out)
    {
        stack<int> s;

        // push
        s.push(1);
        s.push(2);
        s.push(3);

        // top
        cout << "Top: " << s.top() << endl;

        // pop
        s.pop();

        cout << "Top: " << s.top() << endl;

        // size
        cout << "Size: " << s.size() << endl;

        // empty
        cout << "Empty: " << s.empty() << endl;

        cout << endl;
    }

    // 6. Queue: FIFO(First in First out)
    {
        queue<int> q;

        // push
        q.push(1);
        q.push(2);
        q.push(3);

        // front and back
        cout << "First: " << q.front() << endl;
        cout << "Last: " << q.back() << endl;

        // pop
        q.pop();
        cout << "First: " << q.front() << endl;

        // size
        cout << "Size: " << q.size() << endl;

        cout << endl;
    }

    // 7. Priority Queue: Max or Min Heap
    // also comes from #include <queue>
    {
        // Max Heap
        // priority_queue<int> pq; // by default max heap
        // or
        priority_queue<int, vector<int>, less<int>> max_heap;

        // Min Heap
        priority_queue<int, vector<int>, greater<int>> min_heap;

        // push
        max_heap.push(1);
        max_heap.push(3);
        max_heap.push(2);
        max_heap.push(0);

        int n = max_heap.size(); // do not use max_heap.size() directly inside for loop, as it size keeps on changing as we pop elements from the max_heap
        for (int i = 0; i < n; i++)
        {
            // O(1)
            cout << max_heap.top() << " ";

            // O(log(N))
            max_heap.pop();
        }
        cout << endl;

        cout << "Empty: " << max_heap.empty() << endl;

        cout << endl;
    }

    // 8. Set: unique elements, it uses BST(binary search tree) under the hood
    // use #include <set> -> sorted order, avoid this O(log(N))
    // use #include <unordered_set> -> unsorted order, use this, O(1)
    {
        set<int> s;

        // insert
        // O(log(N))
        s.insert(5);
        s.insert(1);
        s.insert(6);
        s.insert(0);

        // print
        // it is in sorted order
        for (int e : s)
            cout << e << " ";
        cout << endl;

        // unique elements in a set
        s.insert(5);
        s.insert(5);
        s.insert(5);
        s.insert(5);

        for (int e : s)
            cout << e << " ";
        cout << endl;

        // O(log(N))
        // erase
        // s.erase(s.begin());     // delete first element

        set<int>::iterator it = s.begin();
        it++;
        s.erase(it); // delete second element

        for (int e : s)
            cout << e << " ";
        cout << endl;

        // O(log(N))
        // count: element present or not
        cout << "5 present ?: " << s.count(5) << endl;
        cout << "100 present ?: " << s.count(100) << endl;

        // O(log(N))
        // find: return iterator of the element found, if not found then returns the iterator -> s.end()
        set<int>::iterator itr = s.find(5);
        cout << "Value present at itr: " << (*itr) << endl;

        // print using iterator
        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << (*it) << " ";
        }
        cout << endl;

        cout << endl;
    }

    // 9. Hashmap / Map / Dictionary: Key Value pairs
    // map uses Red Black Tree / Balanced Tree under the hood O(log(N))
    // unordered_map uses Hashset under the hood O(1)
    {
        // map<key, value> m;
        map<int, string> m;

        // add values
        m.insert({1, "naman"});
        m[7] = "something else";
        m[2] = "arora";

        // print: sorted as we are using map and not using unordered_map
        for (auto &item : m)
            cout << "(key)" << item.first << " : " << item.second << "(value)" << endl;

        // *NOTE: only works in gcc version 7 and up
        // print: using structured bindings
        /*
        for (auto &[key, value] : m)
        {
            cout << key << " : " << value << endl;
        }
        */

        // count
        cout << "Find 7: " << m.count(7) << endl;

        // find
        map<int, string>::iterator it = m.find(7);
        cout << "Find 7: " << (*it).first << endl;
        cout << "Find 7: " << (*it).second << endl;

        // erase -> m.erase(key);
        m.erase(7);
        cout << "Find 7: " << m.count(7) << endl;

        cout << endl;
    }

    // 10. Algorithms
    {
        // binary search

        vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(6);
        v.push_back(7);

        cout << "Element 5 found ?: " << binary_search(v.begin(), v.end(), 5) << endl;
        cout << "Element 7 found ?: " << binary_search(v.begin(), v.end(), 7) << endl;

        // find the iterator of the element in binary search
        // lower bound
        cout << "Lower bound 6: " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
        // upper bound
        cout << "Lower bound 6: " << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;

        // max and min
        int a = 3, b = 5;
        cout << "Max(a, b): " << max(a, b) << endl;
        cout << "Min(a, b): " << min(a, b) << endl;

        // swap
        cout << a << " " << b << endl;
        swap(a, b);
        cout << a << " " << b << endl;

        // reverse
        string s = "abcd";
        cout << "String: " << s << endl;
        reverse(s.begin(), s.end());
        cout << "String(reversed): " << s << endl;

        // rotate
        vector<int> v2 = {1, 2, 3, 4, 5, 6};
        for (auto e : v2)
            cout << e << " ";
        cout << endl;

        rotate(v2.begin(), v2.begin() + 1, v2.end());

        for (auto e : v2)
            cout << e << " ";
        cout << endl;

        // sorting: based on intro sort -> quick sort, heap sort and insertion sort
        for (auto e : v2)
            cout << e << " ";
        cout << endl;

        sort(v2.begin(), v2.end());

        for (auto e : v2)
            cout << e << " ";
        cout << endl;

        cout << endl;
    }

    return 0;
}