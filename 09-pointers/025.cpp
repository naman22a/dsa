#include <iostream>
using namespace std;

int main()
{
    // Basic pointers
    {
        int n = 5;

        cout << "The value of n is: " << n << endl;

        // address of operator -> &
        cout << "The address of n is: " << &n << endl;

        // pointer
        int *ptr = &n;
        cout << "The value of ptr is: " << ptr << endl;
        cout << "The value that ptr points to is: " << *ptr << endl;

        // pointers of different data types

        // double
        double d = 3.14;
        double *ptD = &d;
        cout << "Address: " << ptD << endl;
        cout << "Value: " << *ptD << endl;

        // size of pointers -> always 8 bytes
        cout << "Size of ptr: " << sizeof(ptr) << endl;
        cout << "Size of ptD: " << sizeof(ptD) << endl;

        // why do we need pointers
        /*
        - all types(data types) of pointers take the same memory of 8 bytes (manage memory efficiently while passing data in function args, as the data is copied over and takes more memory)
        - handling of arrays
        - call by reference
        - linked list, trees
        - dynamic memory allocation
        */

        cout << endl;
    }
    /*
        // Wild Pointer
        // it is a bad practice
        // use a NULL pointer to initialize a pointer
        if (0)
        {
            int *bad_ptr;

            // uninitialized pointer, no value is assigned
            // garbage value points to unknown address
            // it could be a valid or invalid location
            // reserved memory or not
            cout << (*bad_ptr) << endl; // will print garbage value

            cout << endl;
        }

        // NULL Pointer
        {
            int *ptr = NULL;      // points to nothing
            cout << ptr << endl;  // zero
            cout << *ptr << endl; // undefined behavior / segmentation fault

            cout << endl;
        }

        // Dangling Pointer
        if (0)
        {
            int *ptr = (int *)malloc(sizeof(int));
            free(ptr);
            // but the pointer still exists
            // the pointer still points to that address
            // very dangerous

            // to avoid always assign ptr to NULL
            ptr = NULL;

            // now try to access ptr
            *ptr = 5; // compile time error

            cout << endl;
        }
    */

    // Void Pointer
    {
        int n = 10;
        void *ptr = &n; // can be used on any data type

        printf("Address: %u\n", ptr);

        // void pointers cannot be dereferenced
        // printf("Value: %u", *ptr); -> compile time error

        // type cast the void pointer into integer pointer and then dereference it
        printf("Value: %u\n", *(int *)ptr);
        printf("\n");
    }

    // Value Access
    {
        int num = 5;
        int a = num;
        a++;

        cout << num << endl; // 5
        cout << a << endl;   // 6

        cout << endl;
    }

    {
        int num = 5;
        int *p = &num;

        cout << num << endl;
        (*p)++;
        cout << num << endl;
    }

    // copying a pointer
    {
        int num = 5;
        int *p = &num;

        int *q = p;

        cout << p << endl;
        cout << q << endl;

        (*p++);

        cout << p << endl;
        cout << q << endl;

        cout << endl;
    }

    // Pointer Arithmetic
    // -> new_address = current_address + i * size_of(data type)
    {
        int n = 5;
        int *p = &n;

        cout << p << endl;

        p++;
        // or
        // p = p + 1;

        cout << p << endl;

        cout << endl;
    }

    return 0;
}