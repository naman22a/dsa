#include <iostream>
using namespace std;

// define Macro with -> #define
// #define is a preprocessor directive

// define a constant using #define
// PI is replaced everywhere by 3.14
#define PI 3.14
// vs
// const double pi = 3.14; // Constant Variable
// disadvantages -> storage is used

// define sort of function using #define
#define sq(x) x *x

// Global variable
// share this variable in between functions

// i am global variable
int variable = 50;

// Inline functions
void func(int a, int b)
{
    a++;
    b++;
    cout << a << b << endl;
}

// call by reference to save memory
// inline to save time
inline int getMax(int &a, int &b)
{
    return (a > b) ? a : b;
}

// default arg -> "start"
void showArray(int arr[], int n, int start = 0)
{
    for (int i = start; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // Macros
    // A piece of code in a program which is replaced by value of macro
    {
        int r = 7;
        // using macro
        double area = PI * r * r;
        // PI = PI + 1; // compile time error
        cout << "Area: " << area << endl;

        // using macro function
        int n = 10;
        cout << sq(n) << endl;

        cout << sq(1 + 2) << endl;
        // as the value inside brackets is substitutied
        // -> 1 + 2 * 1 + 2
        // -> 1 + 2 + 2
        // -> 5

        cout << endl;
    }

    // Global variable
    // bad practice, prefer reference variables
    {
        // 1. using scope resolution operator

        // i am local variable
        int variable = 10;

        // local variable gets the preference
        cout << "Local variable: " << variable << endl;

        // global variable gets the preference by using scope resolution operator
        cout << "Global variable: " << ::variable << endl;

        cout << endl;

        // 2. using extern storage class
        {
            extern int variable; // kind of like python global keyword
            cout << "Global variable: " << variable << endl;
        }

        cout << "Local variable: " << variable << endl;

        cout << endl;
    }

    // Inline functions
    // are used to reduce the function calls overhead
    // the function call overhead happens in the function call stack, which wastes memory, as function call occupies memory in the function call stack
    // putting function call in function call stack, also wastes time
    // the function call is replaced by the actual code during the compile time
    // kind of similar to macros
    {
        int a = 1, b = 2;
        func(a, b);
        int ans;
        ans = getMax(a, b);

        cout << "Max: " << ans << endl;

        a += 3;
        b += 1;
        ans = getMax(a, b);

        cout << "Max: " << ans << endl;

        cout << endl;
    }

    // Default Arguments
    // always -> right most parameter
    {
        int arr[] = {1, 2, 3, 4, 5};
        int n = 5;

        showArray(arr, n);    // print whole array, as default value of starting index = 0
        showArray(arr, n, 2); // print from 2nd index

        cout << endl;
    }

    return 0;
}