#include <iostream>
using namespace std;

// Patterns

// Q1:
/*
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
*/
void p1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

// Q2:
/*
3 2 1
3 2 1
3 2 1
*/

void p2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // alternative solution in comments
        for (int j = 1; j <= n; j++)
        // for (int j = n; j >= 1; j--)
        {
            cout << n - j + 1 << " ";
            // cout << j << " ";
        }
        cout << endl;
    }
}

// Q3:
/*
for n = 3
1 2 3
4 5 6
7 8 9
*/
void p3(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << count << " ";
            count += 1;
        }
        cout << endl;
    }
}

// Q4:
/*
 *
 * *
 * * *
 * * * *
 * * * * *
 */

void p4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// Q5:
/*
1
2 2
3 3 3
4 4 4 4
*/
void p5(int n)
{
    for (int rows = 1; rows <= n; rows++)
    {
        for (int cols = 1; cols <= rows; cols++)
        {
            // here rows represent the count
            cout << rows << " ";
        }
        cout << endl;
    }
}

// Q6:
/*
1
2 3
4 5 6
7 8 9 10
*/
void p6(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

// Q7:
/*
1
2 3
3 4 5
4 5 6 7
*/
void p7(int n)
{
    for (int rows = 1; rows <= n; rows++)
    {
        int count = rows;
        for (int cols = 1; cols <= rows; cols++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

// Q8:
/*
1
2 1
3 2 1
4 3 2 1
*/

void p8(int n)
{
    for (int rows = 1; rows <= n; rows++)
    {
        for (int cols = 1; cols <= rows; cols++)
        {
            cout << rows - cols + 1 << " ";
        }
        cout << endl;
    }
}

// Q9:
/*
A A A
B B B
C C C
*/

void p9(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = 'A' + i - 1;
            cout << ch << " ";
            // or
            // cout << (char)(i - 1 + 65) << " ";
        }
        cout << endl;
    }
}

// Q10:
/*
A B C
A B C
A B C
*/

void p10(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = 'A' + j - 1;
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Q11:
/*
A B C
D E F
G H I
*/

void p11(int n)
{
    int counter = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = 'A' + counter - 1;
            cout << ch << " ";
            counter++;
        }
        cout << endl;
    }
}

// Q12:
/*
A B C
B C D
C D E
*/
void p12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // (i + j - 1) => position of character in alphabetical order (A => 1, B => 2, etc etc)
            char ch = 'A' + (i + j - 1) - 1;
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Q13:
/*
A
B B
C C C
*/

void p13(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char ch = 'A' + i - 1;
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Q14:
/*
A
B C
D E F
G H I J
*/

void p14(int n)
{
    int counter = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char ch = 'A' + counter - 1;
            cout << ch << " ";
            counter++;
        }
        cout << endl;
    }
}

// Q15:
/*
A
B C
C D E
D E F G
*/

void p15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char ch = 'A' + (i + j - 1) - 1;
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Q16:
/*
D
C D
B C D
A B C D
*/

void p16(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int starting_character = 'A' + n - i;
        for (int j = 1; j <= i; j++)
        {
            cout << char(starting_character) << " ";
            starting_character++;
        }
        cout << endl;
    }
}

// Q17:
/*

   *
  **
 ***
****

*/

void p17(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // loop for printing spaces
        int spaces = n - i;
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // loop for printing stars
        int stars = i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

// Q18:
/*
****
***
**
*
*/

void p18(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int stars = n - i + 1;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// Q19:
/*

****
 ***
  **
   *

*/

void p19(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // loop for printing spaces
        int spaces = i - 1;
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // loop for printing stars
        int stars = n - i + 1;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

// Q20:
/*
   1
  121
 12321
1234321
*/

void p20(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // loop for printing spaces
        int spaces = n - i;
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // loop for printing numbers in first triangle
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // loop for printing numbers in second triangle
        for (int j = i - 1; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }
}

int main()
{
    int n = 4;

    p1(n);
    cout << endl;

    p2(n);
    cout << endl;

    p3(n);
    cout << endl;

    p4(n);
    cout << endl;

    p5(n);
    cout << endl;

    p6(n);
    cout << endl;

    p7(n);
    cout << endl;

    p8(n);
    cout << endl;

    p9(n);
    cout << endl;

    p10(n);
    cout << endl;

    p11(n);
    cout << endl;

    p12(n);
    cout << endl;

    p13(n);
    cout << endl;

    p14(n);
    cout << endl;

    p15(n);
    cout << endl;

    p16(n);
    cout << endl;

    p17(n);
    cout << endl;

    p18(n);
    cout << endl;

    p19(n);
    cout << endl;

    p20(n);
    cout << endl;

    return 0;
}