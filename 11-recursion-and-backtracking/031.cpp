#include <iostream>
using namespace std;

int factorial(int n)
{
    // base condition/case
    if (n == 0)
        return 1;

    // recurrence relation
    // or
    // recursive relation
    return n * factorial(n - 1);
}

int powerOfTwo(int n)
{
    if (n == 0)
        return 1;

    return 2 * powerOfTwo(n - 1);
}

void counting(int n)
{
    if (n == 0)
        return;

    counting(n - 1);
    cout << n << " ";
}

void reverse_counting(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    reverse_counting(n - 1);
}

int main()
{
    // Factorial
    {
        int n = 5;
        cout << "Factorial: " << factorial(n) << endl;

        cout << endl;
    }

    // Power of Two
    {
        int n = 10;
        cout << "Power of Two: " << powerOfTwo(n) << endl;
        cout << endl;
    }

    // Print Counting
    {
        int n = 20;
        counting(n);
        cout << endl;

        reverse_counting(n);
        cout << endl;
    }

    return 0;
}