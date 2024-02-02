#include <iostream>
using namespace std;

int main()
{
    // printing
    cout << "Hello World" << endl;
    cout << "Hello World";
    cout << "Hello World" << '\n';
    cout << "Hello World\n";
    cout << "Hello World";
    cout << '\n'; // or cout << endl;
    cout << endl;

    // data types and their sizes
    cout << sizeof(int) << endl;
    cout << sizeof(bool) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;

    cout << sizeof(short int) << endl;
    cout << sizeof(long double) << endl;
    cout << endl;

    // variables

    // int a;  // declaration
    // a = 45; // assignment

    // short syntax for above
    int a = 123;
    // char a = 'a'; // will throw a compilation error(re declaration of a)
    cout << a << endl;

    char bc = 'v';
    cout << bc << endl;

    bool bl = true;
    // or
    // bool bl = 1;
    // true => 1
    // false => 0
    cout << bl << endl;

    float f = 1.2;
    cout << f << endl;

    double d = 1.23;
    cout << 1.23 << endl;
    cout << endl;

    // size of operator
    int size = sizeof(a);
    cout << "Size of a: " << size << endl;
    cout << endl;

    // unsigned int
    unsigned int a1 = 112;
    unsigned int a2 = -112;

    cout << a1 << endl;
    cout << a2 << endl;
    cout << endl;

    // type casting
    int aa = 'a';
    cout << aa << endl;

    char ch = 98;
    cout << ch << endl;

    char ch2 = 123456;
    cout << ch2 << endl;
    cout << endl;

    // Operators

    // 1. Arthmetic operators
    a = 3;
    int b = 4;
    cout << "The value of a + b is " << a + b << endl;
    cout << "The value of a - b is " << a - b << endl;
    cout << "The value of a * b is " << a * b << endl;
    cout << "The value of a / b is " << a / b << endl; // as we are dividing 2 integers the output will be an integer => 0(roundoff to lower integer like greatest integer function or floor function or box function)
    cout << "The value of a % b is " << a % b << endl; // remainder

    cout << "The value of a++ is " << a++ << endl; // print the value then increment
    cout << "The value of a-- is " << a-- << endl; // print the value then decrement
    cout << "The value of ++a is " << ++a << endl; // increment then print the value
    cout << "The value of --a is " << --a << endl; // decrement then print the value

    // 2. Assignment Operators
    int something = 456; // "=" is a assignment operator
    something = something * 4;
    something *= 4; // "*=" is a augmented assignment operator

    // 3. Comparison operators
    cout << "The value of a == b is " << (a == b) << endl; // equal
    cout << "The value of a != b is " << (a != b) << endl; // not equal
    cout << "The value of a >= b is " << (a >= b) << endl;
    cout << "The value of a <= b is " << (a <= b) << endl;
    cout << "The value of a > b is " << (a > b) << endl;
    cout << "The value of a < b is " << (a < b) << endl;

    // 4. Logical operators

    // and (&&) operator
    cout << (true && false) << endl;
    cout << (false && true) << endl;
    cout << (true && true) << endl;
    cout << (false && false) << endl;

    // or (||) operator
    cout << (true || false) << endl;
    cout << (false || true) << endl;
    cout << (true || true) << endl;
    cout << (false || false) << endl;

    // not (!) operator
    cout << (!true) << endl;
    cout << (!false) << endl;

    return 0;
}