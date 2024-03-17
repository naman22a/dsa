#include <iostream>
using namespace std;

int sum(int n);
void fib(int n);
bool isPrime(int n);
int leetcode_1_subtractProductAndSum(int n);
int leetcode_2_hammingWeight(uint32_t n);

int main()
{
    // Bitwise Operators
    int a = 2;
    int b = 3;

    // 1. AND(&)
    cout << (a & b) << endl;

    // 2. OR(|)
    cout << (a | b) << endl;

    // 3. NOT(~)
    cout << (~a) << endl;

    // 4. XOR(^)
    cout << (a ^ b) << endl;

    // 5. Left shit(<<): double
    cout << (a << 1) << endl;
    cout << (a << 2) << endl;

    // 6. Right shit(>>): half
    cout << (a >> 2) << endl;

    cout << endl;
    cout << endl;

    // For loop question
    // 1. Sum of n natural numbers
    cout << sum(100) << endl;

    // 2. Fibonacci series up to n
    fib(10);

    // 3. Check whether a number is prime or not
    cout << isPrime(7) << endl;
    cout << isPrime(10) << endl;

    // Continue jump statement in for loop
    for (int i = 0; i < 5; i++)
    {
        cout << "HI " << i << endl;
        continue; // the code below continue is not reachable as it jumps into next iteration
        cout << "Hello " << i << endl;
    }

    cout << endl;
    cout << endl;

    // Variable Scope

    // global scope
    int x = 3; // x variable is defined for main block of code(inside main function)

    // new block(if block of code) of code
    if (true)
    {
        // local scope
        cout << x << endl;
        int x = 5;
        cout << x << endl;
        int y = 4;
        cout << y << endl;
    }

    cout << x << endl;
    // cout << y << endl; // will throw error

    cout << endl;
    cout << endl;

    // Operator Precedence => see table from ANSI C

    // LC questions
    uint32_t number = 00000000000000000000000000001011;
    cout << leetcode_2_hammingWeight(number) << endl;

    return 0;
}

// functions
int sum(int n)
{
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += i;
    }
    return total;
}

void fib(int n)
{
    int first = 0;
    int second = 1;

    // cout << first << " " << second << " ";
    printf("%d %d ", first, second);

    for (int i = 1; i <= n - 2; i++)
    {
        int newNumber = first + second;
        // cout << newNumber << " ";
        printf("%d ", newNumber);
        first = second;
        second = newNumber;
    }
    cout << endl;
}

bool isPrime(int n)
{
    bool prime = true;
    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            prime = false;
        }
    }
    return prime;
}

// Leet code questions
int leetcode_1_subtractProductAndSum(int n)
{
    int sum = 0, product = 1;
    int temp = n;

    while (temp != 0)
    {
        int digit = temp % 10;
        sum += digit;
        product *= digit;
        temp = temp / 10;
    }

    return product - sum;
}

// uint32_t => 32 bit binary number
int leetcode_2_hammingWeight(uint32_t n)
{
    int count = 0;

    while (n != 0)
    {
        // check if last bit is one(1)
        if (n & 1)
        // or
        // if (n & 1 == 1)
        {
            count++;
        }
        n = n >> 1;
    }

    return count;
}