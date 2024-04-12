#include <iostream>
#include <climits>
using namespace std;

// Leetcode 7: Reverse Integer
int reverse_integer(int x)
{
    int reverse = 0;
    while (x != 0)
    {
        int digit = x % 10;

        // "reverse > (INT_MAX / 10)"  is equivalent to "reverse * 10 > INT_MAX"
        if ((reverse > (INT_MAX / 10)) || (reverse < (INT_MIN / 10)))
            return 0;
        else
            reverse = reverse * 10 + digit;

        x = x / 10;
    }
    return reverse;
}

// Leetcode 1009: Complement of Base 10 Integer
int bitwiseComplement(int n)
{
    // edge case
    if (n == 0)
        return 1;

    int temp = n;
    int mask = 0;

    while (temp != 0)
    {
        mask = (mask << 1) | 1;
        temp = temp >> 1;
    }

    return (~n) & mask;
}

// Leetcode 231: Power of Two
// TC: O(1)
// SC: O(1)
bool isPowerOfTwo_using_bit_manipulation(int n)
{
    // edge case
    if (n <= 0)
        return false; // -ve numbers can't be power of 2 and zero(0) is not a power of 2
    // for -ve numbers can't be possible in this case, see the graph of a^x as the graph is always above the x axis so it is always +ve

    return (n & (n - 1)) == 0;
    // or
    // return !(n & (n - 1));
}

// TC: O(1)
// SC: O(1)
bool isPowerOfTwo_using_integer_range(int n)
{
    for (int i = 0; i <= 30; i++)
    {
        if (n == pow(2, i))
        {
            return true;
        }
    }

    return false;
}

// TC: O(1) , as 32-bit integer so only loops over 32 times
// SC: O(1)
bool isPowerOfTwo_using_hamming_weight(int n)
{
    // edge case
    if (n == 0)
        return false;

    int hw = 0; // hamming weight
    while (n != 0)
    {
        if (n & 1)
            hw += 1;

        if (hw > 1)
            return false;

        n = n >> 1;
    }

    return true;
}

int main()
{
    int n = 1238566666;
    cout << "Reverse Integer: " << reverse_integer(n) << endl;
    cout << "Complement of base 10 Integer: " << bitwiseComplement(10) << endl;

    return 0;
}