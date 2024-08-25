#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// Q1: Maximum Frequency Number
// given an array of integers that contain numbers in random order. He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.
// If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.
// For example,
// For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.

// TC: O(N)
// SC: O(N)
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> freq;
    int maxFreqNum = arr[n - 1];

    for (int i = n - 1; i >= 0; --i)
    {
        int num = arr[i];
        freq[num]++;

        if (freq[num] > freq[maxFreqNum])
            maxFreqNum = num;
    }

    return maxFreqNum;
}

int main()
{
    // using map STL
    {
        // creation
        unordered_map<string, int> m; // implemented via hashtable

        // insertion
        // pair<string, int> p = {"Hello", 3};
        // or
        // pair<string, int> p = make_pair("Hello", 3);
        // or
        pair<string, int> p("Hello", 3);
        m.insert(p);
        // or
        m["World"] = 2;

        // updation
        m["World"] = 4;

        // searching
        cout << m["Hello"] << endl;
        cout << m.at("Hello") << endl;

        // cout << freq.at("unknown_key") << endl; // throws error
        cout << m["unknown_key"] << endl;    // returns zero, it creates a entry of the key with zero
        cout << m.at("unknown_key") << endl; // now it will return zero, as it is placed after the square brackets wali line

        // size
        cout << m.size() << endl;

        // to check presence
        cout << m.count("Hello") << endl;
        cout << (m.find("Hello") != m.end()) << endl; // alternative

        // delete/remove
        m.erase("Hello");
        cout << m.count("Hello") << endl; // check deleted
        cout << m.size() << endl;

        // traverse
        for (auto i : m)
        {
            string key = i.first;
            int value = i.second;
            cout << key << " : " << value << endl;
        }

        // traverse using iterators
        unordered_map<string, int>::iterator it = m.begin();
        while (it != m.end())
        {
            string key = it->first;
            int value = it->second;
            cout << key << " : " << value << endl;
            it++;
        }

        // *NOTE: using map for sorted hashmap, implemented via BST
    }

    return 0;
}