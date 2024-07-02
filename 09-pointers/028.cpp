#include <iostream>
using namespace std;

void update(int &n)
{
    n = 10;
}

int &func(int a)
{
    // the lifetime/visibility/scope of variables num and reference variable ans is limited to the block they are declared in, so this is a dangerous practice, the memory alloacted the the variables is cleared
    int num = a;
    int &ans = num;
    return ans;
}

// the same as above with pointer
// Function returning pointer
int *fun(int n)
{
    int *ptr = &n;
    return ptr;
}

int main()
{

    // Reference Variable
    // same memory, but different names
    {
        int x = 5;
        int &y = x; // reference variable
        cout << x << " " << y << endl;
        x++;
        cout << x << " " << y << endl;
        y++;
        cout << x << " " << y << endl;

        // Why reference variable
        // - pass by reference in functions
        int n = 5;
        cout << n << endl;
        update(n);
        cout << n << endl;

        // - return by reference
        // cout << func(n) << endl; // bad practice
        // cout << fun(n) << endl;  // bad practice
        // but is works somehow 🙃

        cout << endl;
    }

    // Statically Allocate Memory to an Array
    if (0)
    {
        int n;
        cin >> n;

        // This is know as variable length arrays (VLAs), not well supported but works sometimes
        // int arr[n]; // bad practice
        // The value of n is known at runtime, so the compiler can not statically allocate memory
        // the memory needs to allocated dynamically at runtime

        cout << endl;
    }

    // Dynamic Memory Allocation
    {
        char ch = 'q';
        cout << sizeof(ch) << endl;

        char *c = &ch;
        cout << sizeof(c) << endl;

        // 12 bytes are allocated
        // - int* -> 8 bytes for pointer in stack
        // - new int -> 4 bytes for int in heap
        int *n = new int;
        delete n; // free memory

        cout << endl;
    }

    // Dynamically Allocate Memory to an Array
    {
        int n;
        cout << "Enter n: ";
        cin >> n;

        // variable size array
        int *arr = new int[n];
        // 40 bytes in heap
        // 8 bytes in stack

        // input
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // display
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        delete[] arr; // free memory from an Array
    }

    return 0;
}