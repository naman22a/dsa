#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

// Arrays
// - collection of homogenous(same data type) elements
// - contiguous block of memory

// passing array into function
void printArray(int arr[], int size)
// void printArray(int arr[10], int size) // it is possible to provide a size to the array, so it will only work for 10 elements wali array, but it is considered a bad practice
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// #include <climits> for INT_MIN and INT_MAX

int array_max(int arr[], int size)
{
    int max = INT_MIN; // or arr[0]
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int array_min(int arr[], int size)
{
    int min = INT_MAX; // or arr[0]
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

void update_array(int arr[], int size)
{
    arr[0] = 120;

    cout << "Inside the function: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sum(int arr[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }

    return total;
}

int linear_search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1; // means not found, as -ve indices do not exist in c++
}

void reverse_array(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        // alternatively
        // swap(arr[left], arr[right]);

        left++;
        right--;
    }
}

int main()
{

    // declare an array
    int arr[10];
    // declaration of an array of 10 block of integers(with garbage values)
    // arr -> location of first memory address
    // range from (0 to n - 1)

    // accessing value in an array
    cout << "The value at index 0: " << arr[0] << endl;
    cout << "The value at index 2: " << arr[2] << endl;
    cout << "The value at index 9: " << arr[9] << endl;

    // garbage value(should have been an error or warning idk why it is giving garbage value)
    cout << "The value at index 10: " << arr[10] << endl;
    cout << "The value at index 20: " << arr[20] << endl;
    cout << endl;

    // initialisation of an array with values
    int second[3] = {5, 7, 11};

    // accessing an element
    cout << "The value at index 2: " << second[2] << endl;
    cout << endl;

    // partial initialisation of an array (rest of the values are set to be at zero)
    int third[10] = {2, 7};

    // print the array (using for loop)
    // as the range of array is (0 to n-1)
    printArray(third, 10);
    cout << endl;

    int fourth[10] = {0}; // initialising the rest of the values to be null (cannot be done with any other number)

    printArray(fourth, 10);
    cout << endl;

    // to initialise an array with a particular element as the default value we use
    // int fifth[10] = {1}; // will rest in 1 0 0 0 0 0 0 0 0 0
    int fifth[10];

    fill_n(fifth, 10, 1); // imported from #include <algorithm>
    // alternatively use a for loop to set the default values in an array

    printArray(fifth, 10);
    cout << endl;

    // find length of an array (total_size / capacity)
    // used_size => it is impossible to find the used size of an array 😭

    int length = sizeof(arr) / sizeof(arr[0]);
    // alternatively
    // int length = sizeof(arr) / sizeof(int);

    cout << "The length of the fifth array: " << length << endl;
    cout << endl;

    // character arrays (similarly arrays of double, float etc etc are also possible)
    char ch_arr[] = {'a', 'b', 'c', 'd', 'e'};
    // equivalent to
    // char ch_arr[5] = {'a', 'b', 'c', 'd', 'e'};

    // accessing
    cout << "The value of ch_arr[3]: " << ch_arr[3] << endl;
    cout << endl;

    // Q: max and min element in an array
    int some_arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    // input an array
    /*
    int some_arr[100]; // maximum 100 values can be stored in an array in this case
    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> some_arr[i];
    }
    */

    printArray(some_arr, n);

    cout << "Max: " << array_max(some_arr, n) << endl;
    cout << "Min: " << array_min(some_arr, n) << endl;
    cout << endl;

    // Scope of an array
    int arr_scope[] = {1, 2, 3, 4};

    cout << "Before:                ";
    printArray(arr_scope, 4);

    // update the array
    update_array(arr_scope, 4);

    // the change in the value of arr[0] is reflected in the original array
    // as in "int arr[]" "arr" represents the memory address of first block
    // hence memory address is passed into the function
    // so it call by reference, not call by value
    // thus the value changes

    cout << "After:               ";
    printArray(arr_scope, 4);

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << arr_scope[i] << " ";
    // }
    // cout << endl;

    // Q: sum of array

    int cool_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArray(cool_arr, 10);
    cout << "Sum: " << sum(cool_arr, 10) << endl;
    cout << endl;

    // Linear search
    int target = 6;
    cout << "The target is present at index: " << linear_search(cool_arr, 10, target) << endl;
    cout << endl;

    // Reverse an array
    printArray(cool_arr, 10);
    reverse_array(cool_arr, 10);
    printArray(cool_arr, 10);

    return 0;
}