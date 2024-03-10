#include <iostream>
using namespace std;

int main()
{
    // int n;
    // cin does not read " "(space), "\n"(new line character), "\t"(tab character)
    // cin >> n;

    // use cin.get()
    // when we enter "1 2" then it gets the first character(cin.get can read " ","\n","\t")
    // it only reads 1 as a character
    // '1' -> 49(in ascii)
    // so output will be 49 as "n" stores an integer only
    // n = cin.get();
    // cout << "The value of n is " << n << endl;

    // conditionals

    // check if a > b
    int a = 3, b = 2;

    if (a > b)
    {
        cout << "a is greater than b" << endl;
    }
    else
    {
        cout << "a is less than b" << endl;
    }

    // signum wala program (see 001.cpp)
    int n = 10;

    if (n > 0)
        cout << "+ve" << endl;
    else
    {
        if (n < 0)
            cout << "-ve" << endl;
        else
            cout << "zero" << endl;
    }

    // assignment inside if condition
    int x = 2;

    if ((x = -5))
    {
        cout << "(true)x: " << x << endl;
    }
    else
    {
        cout << "(false)x: " << x << endl;
    }

    cout << endl;
    cout << endl;

    // Loops

    // 1. While Loop
    int i = 1;
    n = 10;
    while (i <= n)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // 2. For Loop
    // 3. Do While Loop

    // Q: Sum of numbers till n
    // Q: Sum of numbers till n only of even numbers
    // Q: Check whether a number is prime or not

    cout << endl;
    cout << endl;

    // Patterns

    // Q:
    /*
    ***
    ***
    ***
    */

    n = 3;
    for (int rows = 1; rows <= n; rows++)
    {
        for (int cols = 1; cols <= n; cols++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    // Q:
    /*
    111
    222
    333
    */

    n = 3;
    for (int rows = 1; rows <= n; rows++)
    {
        for (int cols = 1; cols <= n; cols++)
        {
            cout << rows;
        }
        cout << endl;
    }

    return 0;
}