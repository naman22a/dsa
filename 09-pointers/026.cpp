#include <iostream>
using namespace std;

void print(int *);
int sum(int[], int n);

int main()
{
    // Array Pointer Arithmetic
    {
        int arr[10] = {1, 2, 3, 4, 5};
        cout << "Address of first block is: " << arr << endl;
        // or
        cout << "Address of first block is: " << &arr << endl;
        // or
        cout << "Address of first block is: " << &arr[0] << endl;

        cout << "Value at first block of memory is: " << arr[0] << endl;
        cout << "Value at first block of memory is: " << *arr << endl;       // 1 -> *(arr + 0)
        cout << "Value at first block of memory is: " << *(arr + 1) << endl; // 2
        cout << "Value at first block of memory is: " << *arr + 1 << endl;   // 1 + 1

        // *NOTE: arr[i] = *(arr + i)
        // *NOTE: i[arr] = *(i + arr) = *(arr + i) = arr[i]

        cout << "The value 1st index: " << arr[1] << endl;
        cout << "The value 1st index: " << 1 [arr] << endl;

        cout << endl;
    }

    // Differences b/w Pointers and Array
    {
        int arr[10] = {1, 2, 3};
        cout << "Size of arr: " << sizeof(arr) << endl;

        int *ptr1 = &arr[0];
        cout << "Size of ptr1: " << sizeof(ptr1) << endl;

        int *ptr2 = arr;
        cout << "Size of ptr2: " << sizeof(ptr2) << endl;

        cout << endl;
    }

    // Size
    {
        int arr[10] = {1, 2, 3};
        int size = sizeof(arr) / sizeof(arr[0]);
        cout << "Capacity of array is: " << size << endl;

        cout << endl;
    }

    // Content of symbol table can not be changed
    {
        int arr[10] = {1, 2, 3};
        // arr = arr + 1; // results in error

        int *ptr = arr;
        ptr++; // it works, here we are changing the value stored in ptr
        // the mapping in symbol table can not altered

        cout << endl;
    }

    // Charatcer Arrays
    {
        int arr[] = {1, 2, 3, 4, 5};
        char s[] = "naman";

        cout << arr << endl; // gives base address
        cout << s << endl;   // prints the string
        // reason for above is cout is differently implemented for character arrays and normal arrays

        char *c = &s[0];
        cout << c << endl; // still prints the string

        // werid stuff
        char temp = 'z';
        char *p = &temp;

        cout << p << endl; // still tries to print a string, prints characters until it finds a null character the garbage values 💀

        char ch[6] = "abcde";
        // char *c = "abcde"; // risky, bad practice, it stores string in temporary array

        cout << endl;
    }

    // Pointers and Functions
    {
        int value = 5;
        int *p = &value;

        cout << "Before function call: " << value << endl;
        print(p);
        cout << "After function call: " << value << endl;

        int arr[] = {1, 2, 3, 4, 5};
        cout << "Sum: " << sum(arr, 5) << endl; // 1 + 2 + 3 + 4 + 5 = 15

        // int arr[] in function parameter is same as int* arr

        cout << "Sum: " << sum(arr + 3, 2) << endl; // 4 + 5 = 9

        cout << endl;
    }

    return 0;
}

void print(int *p)
{
    cout << p << endl;
    cout << *p << endl;
    (*p)++;
    cout << *p << endl;
}

// int sum(int arr[], int n)
// or
int sum(int *arr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}