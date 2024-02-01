#include <iostream>
using namespace std;

void sum_two_numbers()
{
    int a, b;

    cout << "Enter the value of first number: ";
    cin >> a;
    cout << "Enter the value of second number: ";
    cin >> b;

    int sum = a + b;

    cout << "The value of sum is " << sum << endl;
}

void simple_interest()
{
    int p, r, t;

    cout << "Principle: ";
    cin >> p;
    cout << "Rate: ";
    cin >> r;
    cout << "Time(in years): ";
    cin >> t;

    int interest = (p * r * t) / 100;

    cout << "Interest: " << interest << endl;
}

void avg_three_numbers()
{
    int a, b, c;
    cin >> a >> b >> c;

    int avg = (a + b + c) / 3;

    cout << "Avg: " << avg << endl;
}

void less_than()
{
    int a, b;
    cin >> a >> b;

    if (a < b)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

void is_even_or_odd()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
        cout << "even" << endl;
    else
        cout << "odd" << endl;
}

void signum()
{
    int n;
    cin >> n;

    if (n > 0)
        cout << "+ve" << endl;
    else if (n < 0)
        cout << "-ve" << endl;
    else
        cout << "zero" << endl;
}

void valid_triangle()
{
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b > c) && (b + c > a) && (c + a > b))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

void print_1_to_n()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

void print_1_to_n_only_even()
{
    int n;
    cin >> n;

    for (int i = 2; i < n; i = i + 2)
    {
        cout << i << " ";
    }
    cout << endl;
}

void print_1_to_n_only_odd_inclusive()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i = i + 2)
    {
        cout << i << " ";
    }
    cout << endl;
}

// inclusive
void sum_from_1_to_n()
{
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    cout << "Sum: " << sum << endl;
}

void factorial()
{
    int n;
    cin >> n;

    int ans = 1;
    // starting loop from 2 as 1 multiplied will have no effect as it is the multiplication identity
    for (int i = 2; i <= n; i++)
    {
        ans = ans * i;
    }
    cout << "Factorial: " << ans << endl;
}

void is_prime()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            cout << "Nope" << endl;
            return;
        }
    }

    cout << "Yup" << endl;
}

int main()
{
    // sum_two_numbers();
    // simple_interest();
    // avg_three_numbers();
    // less_than();
    // is_even_or_odd();
    // signum();
    // valid_triangle();
    // print_1_to_n();
    // print_1_to_n_only_even();
    // print_1_to_n_only_odd_inclusive();
    // sum_from_1_to_n();
    // factorial();
    is_prime();

    return 0;
}