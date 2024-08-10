#include <iostream>
using namespace std;

// Q1:
// Leetcode 509: Fibonacci Number

// 1. Pure Recursion
// TC: O(2^n)
// SC: O(N)
int fib_recursion(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib_recursion(n - 1) + fib_recursion(n - 2);
}

// 2. Recursion + Memoization
// TC: O(N)
// SC: O(N)

// 3. Tabulation
// TC: O(N)
// SC: O(N)

// 4. Tabulation with Space Optimization
int fib_iteratively(int n)
{
    if (n == 0 || n == 1)
        return n;

    int first = 0;
    int second = 1;

    int next;

    for (int i = 2; i <= n; i++)
    {
        next = first + second;
        first = second;
        second = next;
    }

    return next;
}

int fib(int n)
{
    return fib_iteratively(n);
}

// Q2:
// Leetcode 70: Climbing Stairs

// it is actually a dynamic programming question
// it will not pass all the test cases
int climbStairs(int n)
{
    // base case
    if (n < 0)
        return 0;

    // base case
    if (n == 0)
        return 1;

    // recurrence relation
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// Q3: Say Digits
// i/p -> 412
// o/p -> Four One Two

string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void sayDigits(int n)
{
    // base condition
    if (n == 0)
        return;

    int digit = n % 10;
    n = n / 10;

    sayDigits(n);

    cout << digits[digit] << " ";
}

// Extra Questions

// Q4: Print Fibonacci Series
void fib_recursive(int n)
{
    static int first = 0, second = 1, next;

    if (n > 0)
    {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;

        fib_recursive(n - 1);
    }

    cout << endl;
}

void fib_series(int n)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    if (n == 2)
    {
        cout << 0 << " " << 1 << endl;
        return;
    }

    cout << 0 << " " << 1 << " ";
    fib_recursive(n - 2);
}

// Q5: Tower of Hanoi
void hanoi(int n, char src, char dest, char aux)
{
    if (n == 1)
    {
        cout << "Move 1 disk from " << src << " to " << dest << endl;
        return;
    }
    hanoi(n - 1, src, aux, dest);
    cout << "Move " << n << " disks from " << src << " to " << dest << endl;
    hanoi(n - 1, aux, dest, src);
}

int main()
{
    {
        int n = 412;
        sayDigits(n);
        cout << endl;

        cout << endl;
    }

    {
        int n = 5;
        fib_series(n);
        cout << endl;
    }

    {
        int n = 3;
        hanoi(n, 'A', 'C', 'B');
    }

    return 0;
}