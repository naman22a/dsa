#include <iostream>
using namespace std;

int main()
{
    // Static Memory Allocation of 2D Arrays
    if (0)
    {
        // int arr[rows][cols]
        int arr[5][5];

        int ROWS, COLS;
        cin >> ROWS >> COLS;

        // int m[ROWS][COLS]; // bad practice
    }

    // Dynamic Memory Allocation of 2D Arrays
    {
        int ROWS, COLS;
        cout << "ROWS: ";
        cin >> ROWS;

        cout << "COLS: ";
        cin >> COLS;

        // create 2d array
        int **matrix = new int *[ROWS]; // allocate an array of integer pointers
        for (int i = 0; i < ROWS; i++)
            matrix[i] = new int[COLS];

        // input
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
                cin >> matrix[r][c];
            cout << endl;
        }

        // display
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
                cout << matrix[r][c] << " ";
            cout << endl;
        }

        // release memory in 2d array

        // free memory of rows
        for (int i = 0; i < ROWS; i++)
            delete[] matrix[i];

        // free memory of integer pointers array
        delete[] matrix;
    }

    return 0;
}