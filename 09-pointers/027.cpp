#include <iostream>
using namespace std;

void update(int **p)
{
    // no change (call by value)
    p = p + 1;

    // change in value of p(outside function wala)
    *p = *p + 1;

    // change in value of n
    // **p = **p + 1;
}

int main()
{
    // pointers to pointers
    {
        int n = 5;
        int *p = &n;    // pointer to integer
        int **ptr = &p; // pointer to pointer

        cout << "n: " << n << endl;
        cout << "&n: " << &n << endl;
        cout << "p: " << p << endl;
        cout << "&p: " << &p << endl;
        cout << "ptr: " << ptr << endl;
        cout << endl;
        cout << "*p: " << *p << endl;
        cout << "*ptr: " << *ptr << endl;
        cout << "**ptr: " << **ptr << endl;

        cout << endl;
    }

    // double pointer and functions
    {
        int n = 5;
        int *p = &n;
        int **p2 = &p;

        cout << "--- Before ---" << endl;
        cout << n << endl;
        cout << p << endl;
        cout << p2 << endl;

        update(p2);

        cout << "--- After ---" << endl;
        cout << n << endl;
        cout << p << endl;
        cout << p2 << endl;

        cout << endl;
    }

    return 0;
}