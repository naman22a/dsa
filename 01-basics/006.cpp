#include <iostream>
#include <cmath>
using namespace std;

// *NOTE
/***************
THIS CODE IN THE FUNCTION BELOW IS CORRECT
BUT IT SOMETIMES DOES NOT WORK, AS IT IS COMPILER DEPENDENT
THE pow FUNCTION FROM cmath CAUSES THE PROBLEM

btw it works on online compiler

The pow function actually uses taylor series inside of it to calculate base raised to the power of exponent.

As taylor series gives use an approximation of the functions actual value
e.g => pow(10, 2)
it should give use 100
but pow function uses taylor series so the answer is 99.99999......
which is type casted into int as it is stored in int after "(bit * pow(10, i)) + ans" this operation
it rounds down to 99
thus resulting in incorrect ouput

to avoid this problem we can use float instead of int
***************/
int decimal_to_binary(int n)
{
    // int ans = 0; // works on online compiler (pow function is compiler dependent)
    float ans = 0;
    int i = 0;

    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    return ans;
}

int binary_to_decimal(int n)
{
    int ans = 0;
    int i = 0;

    while (n != 0)
    {
        int bit = n % 10;

        if (bit)
            ans = ans + pow(2, i);

        n = n / 10;
        i++;
    }

    return ans;
}

int main()
{
    cout << decimal_to_binary(5) << endl;
    cout << binary_to_decimal(101) << endl;

    return 0;
}