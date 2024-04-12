#include <iostream>
using namespace std;

// =============== Switch Case ===============

// "Switch case" is equivalent to "nested if else" aka "if, else if, else" ladder
void switch_case()
{
    // int num = 2;
    // char ch = '1';
    char ch = 'a';
    int num = 1;

    // switch (num)
    // switch (ch)
    // switch (num)
    // switch ('4')
    switch (1)
    {
    case 1: // only int and char are allowed inside the case (value):
        cout << "first" << endl;
        // break; // optional
        // if break is not there then all the statements below will also execute regardless of the condition
        // break;
    case 2:
        cout << "second" << endl;
        // break;
    case 3:
        cout << "third" << endl;
        // break;
    // case '1':
    case '4':
        switch (num)
        {
        case '4':
            cout << "nested switch" << endl;
            break;

        default:
            break;
        }
        cout << "character one" << endl;
        // break;
        // if this break is removed then default case will also be executed

        // default case is optional
    default:
        cout << "idk, this is the default case" << endl;
        break;
    }

    // NOTE: cases can be written like this also
    /*
    case constant_value: {
        statements
    }
    the curly brackets are optional
    */

    // NOTE: when inside infinite loop and using a switch case inside of it then to exit out of that infinite loop we use exit()
    // exit() => terminated the c++ program

    // continue in switch statement
    // continue inside switch case is not valid as it is a conditional not a loop, so it can't jump to the next iteration
}

void calculator()
{
    // input a, b, operation
    // operations: +, -, *, /, %

    while (true)
    {

        cout << "============== Menu ==============" << endl;
        cout << endl;
        cout << "1. Addtion" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulo" << endl;
        cout << "6. Quit" << endl;
        cout << endl;

        int a, b;

        cout << "Enter the value of the first number: ";
        cin >> a;

        cout << "Enter the value of the second number: ";
        cin >> b;

        cout << endl;

        int operation;
        cout << "Enter option(1 - 6): ";
        cin >> operation;

        switch (operation)
        {
        case 1:
            cout << "The addition of " << a << " and " << b << " is " << (a + b) << endl;
            break;

        case 2:
            cout << "The subtraction of " << a << " and " << b << " is " << (a - b) << endl;
            break;
        case 3:
            cout << "The multiplication of " << a << " and " << b << " is " << (a * b) << endl;
            break;
        case 4:
            cout << "The division of " << a << " and " << b << " is " << ((float)a / b) << endl;
            break;
        case 5:
            cout << "The modulo of " << a << " and " << b << " is " << (a % b) << endl;
            break;
        case 6:
            cout << "Bye Bye" << endl;
            exit(0); // exits the c++ program
            break;

        default:
            cout << "Invalid option, try again" << endl;
            break;
        }
    }
}

void currency_denomination(int amount)
{
    // Rs 100
    // Rs 50
    // Rs 20
    // Rs 1

    // e.g: 1330 => 13 x 100 + 1 x 20 + 10 x 1

    int num = 1;
    int note = 0;

    switch (num)
    {
    case 1:
        note = amount / 100;
        amount = amount - (100 * note);
        cout << "Rs 100: " << note << endl;
    case 2:
        note = amount / 50;
        amount = amount - (50 * note);
        cout << "Rs 50: " << note << endl;
    case 3:
        note = amount / 20;
        amount = amount - (20 * note);
        cout << "Rs 20: " << note << endl;
    case 4:
        note = amount / 1;
        amount = amount - (1 * note);
        cout << "Rs 1: " << note << endl;
    }
}

// =============== Functions ===============

// power
int power(int base, int exponent)
{
    int ans = 1;

    for (int i = 1; i <= exponent; i++)
    {
        ans = ans * base;
    }

    return ans;
}

// even odd
bool isEven(int n)
{
    return !(n % 2);
}

bool isOdd(int n)
{
    return (n & 1);
}

// nCr
// input n, r
// output value of nCr

int factorial(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

float nCr(int n, int r)
{
    return (float)factorial(n) / (factorial(r) * factorial(n - r));
}

// print counting from 1 to n

// function declaration / function protype / function signature
void print_counting(int n);

void print_counting(int n)
{
    // function body
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

// is prime
bool isPrime(int n)
{
    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// A.P
// An = (3*n + 7)
// input n
// output nth term in A.P
int ap(int n)
{
    return (3 * n + 7);
}

// input a, b
// output total number of set bits in a and b
int set_bits(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
            count++;

        n = n >> 1;
    }
    return count;
}

int total_set_bits(int a, int b)
{
    return set_bits(a) + set_bits(b);
}

// fibonacci (start with 0 and 1)
// input n
// output nth fibonacci term
// 0 1 1 2 3 5 8 13 21 ...
int fibonacci(int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int first = 0;
    int second = 1;
    int newTerm;

    for (int i = 2; i < n; i++)
    {
        newTerm = first + second;
        first = second;
        second = newTerm;
    }

    return newTerm;
}

// pass by value and pass by reference

// pass by value
void dummy(int n)
{
    n++;
    cout << "n inside the function is " << n << endl;
}

int main()
{
    int a = 2, b = 3;
    cout << power(a, b) << endl;

    cout << isEven(2) << endl;
    cout << isOdd(3) << endl;

    cout << nCr(8, 0) << endl;
    cout << nCr(8, 2) << endl;

    // function call
    print_counting(10);

    cout << isPrime(47) << endl;
    cout << isPrime(34) << endl;

    cout << total_set_bits(2, 3) << endl;

    cout << fibonacci(7) << endl;

    cout << endl;

    // pass by value

    int n = 3;
    cout << "n outside the function before calling is " << n << endl;
    dummy(n); // the value of n(arguments) is copied to over to the function parameters
    // it creates a new n in memory, thus no effect on the original n

    // in pass by reference we pass the memory address of the variable or by passing the variable as a reference

    cout << "n outside the function after calling is " << n << endl;

    return 0;
}