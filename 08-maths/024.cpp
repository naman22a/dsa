#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// TC: O(sqrt(N))
// SC: O(1)
bool isPrime(int n)
{
    // check is n is divisible in the range [2, n-1]
    // for (int i = 2; i <= n - 1; i++)

    // optimization
    // check is n is divisible in the range [2, sqrt(n)]
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Q1:
// Leetcode 204: Count Primes

// TC: O(O(N*log(log(N))))
// SC: O(N)
int countPrimes_using_sieve_of_eratosthenes(int n)
{
    int count = 0;
    vector<bool> prime(n + 1, true);

    // mark 0 and 1 as not prime
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            // mark all numbers in ith's table as not prime
            for (int j = 2 * i; j < n; j = j + i)
                prime[j] = 0;
        }
    }

    return count;
}

// results in TLE
// TC: O(N.sqrt(N))
// SC: O(1)
int countPrimes_using_trial_division(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
        isPrime(i) && count++;
    return count;
}

int countPrimes(int n)
{
    return countPrimes_using_trial_division(n);
}

// Q2: GCD / HCF
int gcd(int a, int b)
{
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

// Q3: Modular Exponentiation
/*
You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
*/

// TC: O(log(N)), N -> length of vector b
// SC: O(1)
int modularExponentiation(int x, int n, int m)
{
    int result = 1;

    while (n > 0)
    {
        // odd
        if (n & 1)
            result = ((long long)result * (x % m)) % m;
        x = (((long long)(x) % m) * (x % m)) % m;
        n = n >> 1; // divide by 2
    }

    return result;
}

// Q3:
// TODO
// Leetcode 372: Super Pow

int main()
{
    // is prime
    {
        cout << "Is Prime ?: " << isPrime(10) << endl;
        cout << "Is Prime ?: " << isPrime(23) << endl;
        cout << "Is Prime ?: " << isPrime(1) << endl;
        cout << "Is Prime ?: " << isPrime(-100) << endl;
        cout << "Is Prime ?: " << isPrime(0) << endl;

        cout << endl;
    }

    // count primes
    {
        int n = 10;
        cout << "count primes: " << countPrimes(n) << endl;

        cout << endl;
    }

    // gcd
    {
        int a = 72, b = 24;
        cout << "GCD: " << gcd(a, b) << endl;

        cout << endl;
    }

    {
        cout << modularExponentiation(2, 10, 10000) << endl;
    }

    return 0;
}