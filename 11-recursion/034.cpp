#include <iostream>
#include <string>
using namespace std;

// Q1: Reverse a string using Recursion
void rs(string &s, int left, int right)
{
    // base condition
    if (left > right)
        return;

    // processing
    swap(s[left], s[right]);

    // recurrence relation
    rs(s, left + 1, right - 1);
}

void reverse_string(string &s)
{
    rs(s, 0, s.size() - 1);
}

void reverse_string_alt(string &s, int i = 0)
{
    if (i >= s.size() / 2)
        return;

    swap(s[i], s[s.size() - i - 1]);
    reverse_string_alt(s, i + 1);
}

// Q2: Check Palindrome using Recursion
bool checkPalindrome(string s, int left, int right)
{
    if (left > right)
        return true;

    if (s[left] != s[right])
        return false;

    return checkPalindrome(s, left + 1, right - 1);
}

// Q3: Calculate power using recursion
// with fast exponentiation
int power(int base, int exponent)
{
    // base condition
    if (exponent == 0)
        return 1;

    // base condition
    if (exponent == 1)
        return base;

    int ans = power(base, exponent / 2);

    // odd
    if (exponent & 1)
        return base * ans * ans;

    // even
    return ans * ans;
}

// without fast exponentiation
int power_(int base, int exponent)
{
    if (exponent == 0)
        return 1;

    return base * power(base, exponent - 1);
}

// Q4: Recursive Bubble sort
void bubble_sort(int arr[], int size)
{
    // base case: already sorted
    if (size == 0 || size == 1)
        return;

    // place the largest element at the end by adjacent swap
    for (int i = 0; i <= size - 2; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    // recurrence
    bubble_sort(arr, size - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // Reverse string
    {
        string name = "abcde";

        cout << "Original: " << name << endl;
        reverse_string(name);
        cout << "Reverse: " << name << endl;
        cout << endl;
    }

    // Check Palindrome
    {
        string name = "naman";
        cout << "Palindrome: " << checkPalindrome(name, 0, name.size() - 1) << endl;
        cout << endl;
    }

    // Power
    {
        int base = 2;
        int exponent = 10;

        cout << "Power: " << power(base, exponent) << endl;
        cout << endl;
    }

    // Recursive Bubble sort
    {
        int arr[] = {2, 5, 1, 6, 9};
        int size = 5;

        printArray(arr, size);
        bubble_sort(arr, size);
        printArray(arr, size);

        cout << endl;
    }

    return 0;
}