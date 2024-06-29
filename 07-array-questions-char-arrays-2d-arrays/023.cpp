#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// int arr[][] => result in error 💀
// column size should always be specified in the function parameters
// reason is given below
// https://stackoverflow.com/questions/12813494/why-do-we-need-to-specify-the-column-size-when-passing-a-2d-array-as-a-parameter
// TC: O(M.N), M -> rows, N -> cols
pair<int, int> linear_search(int arr[][4], int ROWS, int COLS, int target)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (arr[row][col] == target)
                return {row, col};
        }
    }

    return {-1, -1};
}

vector<int> rowWiseSum(int arr[][4], int ROWS, int COLS)
{
    vector<int> ans;
    for (int r = 0; r < ROWS; r++)
    {
        int total = 0;
        for (int c = 0; c < COLS; c++)
        {
            total += arr[r][c];
        }
        ans.push_back(total);
    }
    return ans;
}

vector<int> colWiseSum(int arr[][4], int ROWS, int COLS)
{
    vector<int> ans;
    for (int c = 0; c < COLS; c++)
    {
        int total = 0;
        for (int r = 0; r < ROWS; r++)
        {
            total += arr[r][c];
        }
        ans.push_back(total);
    }
    return ans;
}

int LargestRowWiseSum(int arr[][4], int ROWS, int COLS)
{
    int maxSum = INT_MIN;
    int index = -1; // row index
    for (int r = 0; r < ROWS; r++)
    {
        int total = 0;
        for (int c = 0; c < COLS; c++)
        {
            total += arr[r][c];
        }
        if (total > maxSum)
        {
            maxSum = total;
            index = r;
        }
    }

    return index;
}

// Q1: Wave Pattern
/*
For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.
For eg:-
The sine wave for the matrix:-
1 2
3 4
will be [1, 3, 4, 2].
*/
// TC: O(M.N), we are visiting each element once -> O(total no of elements)
// SC: O(1), output is not considered as extra space in the problem, as we are returning it
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> output;
    for (int c = 0; c < mCols; c++)
    {
        // even: top to bottom
        if (c % 2 == 0)
        {
            for (int r = 0; r < nRows; r++)
                output.push_back(arr[r][c]);
        }
        // odd: bottom to top
        else
        {
            for (int r = nRows - 1; r >= 0; r--)
                output.push_back(arr[r][c]);
        }
    }
    return output;
}

// Q2:
// Leetcode 54: Spiral Matrix
// TC: O(M.N)
// SC: O(1)
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int ROWS = matrix.size();
    int COLS = matrix[0].size();

    int top = 0;
    int left = 0;
    int right = COLS - 1;
    int bottom = ROWS - 1;

    // print right -> bottom -> left -> top (movement)
    vector<int> output;

    while (left <= right && top <= bottom)
    {
        // print right
        // left <= right is already checked inside the loop
        for (int i = left; i <= right; i++)
            output.push_back(matrix[top][i]);
        top++;

        // print bottom
        for (int i = top; i <= bottom; i++)
            output.push_back(matrix[i][right]);
        right--;

        // to check that pointers do not cross each other(inside the loop, while mai toh check kar he raha hu)
        if (top <= bottom)
        {
            // print left
            for (int i = right; i >= left; i--)
                output.push_back(matrix[bottom][i]);
            bottom--;
        }

        // to check that pointers do not cross each other(inside the loop, while mai toh check kar he raha hu)
        if (left <= right)
        {
            // print top
            for (int i = bottom; i >= top; i--)
                output.push_back(matrix[i][left]);
            left++;
        }
    }

    return output;
}

// Q3:
// Leetcode 48: Rotate Image
// TC: O(N^2), N -> order of square matrix
// SC: O(1)
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        // iterate over enitire top row, except the last element
        for (int i = 0; i < right - left; i++)
        {
            int top = left, bottom = right;

            // save the top left value
            int topLeft = matrix[top][left + i];

            // move the bottom left into the top left
            matrix[top][left + i] = matrix[bottom - i][left];

            // move the bottom right into bottom left
            matrix[bottom - i][left] = matrix[bottom][right - i];

            // move top right into bottom right
            matrix[bottom][right - i] = matrix[top + i][right];

            // move topLeft to into right
            matrix[top + i][right] = topLeft;
        }
        left++;
        right--;
    }
}

// Q4:
// Leetcode 74: Search a 2D Matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int ROWS = matrix.size();
    int COLS = matrix[0].size();

    int left = 0;
    int right = ROWS * COLS - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int value = matrix[mid / COLS][mid % COLS]; // mid value

        if (value == target)
            return true;
        else if (value < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

// Q5:
// Leetcode 240: Search a 2D Matrix II
// TC: O(m + n)
// SC: O(1)
bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int ROWS = matrix.size();
    int COLS = matrix[0].size();

    // starting from top right
    int rowIndex = 0;        // first row
    int colIndex = COLS - 1; // last column

    while (rowIndex < ROWS && colIndex >= 0)
    {
        int value = matrix[rowIndex][colIndex];
        if (value == target)
            return true;
        else if (value < target)
            rowIndex++;
        else
            colIndex--;
    }

    return false;
}

int main()
{
    // Initialize, Input, Output
    {

        // declare 2d array
        // int arr[3][4];
        // int rows = 3;
        // int cols = 4;

        // input 2d array (row wise input)
        /*
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
            cout << endl;
        }
        */

        // input 2d array (column wise input)
        /*
        for (int j = 0; j < cols; j++)
        {
            for (int i = 0; i < rows; i++)
            {
                cin >> arr[i][j];
            }
            cout << endl;
        }
        */

        // input 2d array (initialize)

        // row wise
        // int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

        // subarray wise
        int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

        int rows = 3;
        int cols = 4;

        // output the 2d array
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    // Linear Search
    {
        int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        int ROWS = 3;
        int COLS = 4;

        int target = 8;

        pair<int, int> value = linear_search(arr, ROWS, COLS, target);
        int row = value.first;
        int col = value.second;

        cout << "Element found at indices" << endl;
        cout << "Row: " << row << endl;
        cout << "Col: " << col << endl;

        cout << endl;
    }

    // Row wise sum
    {
        int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        int ROWS = 3;
        int COLS = 4;

        vector<int> sums = rowWiseSum(arr, ROWS, COLS);
        for (int sum : sums)
        {
            cout << sum << " ";
        }
        cout << endl;

        cout << endl;
    }

    // Largest row sum
    // return the index of the row
    {
        int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        int ROWS = 3;
        int COLS = 4;

        cout << "Largest row wise sum(row index): " << LargestRowWiseSum(arr, ROWS, COLS) << endl;
    }

    // Wave pattern
    {
        vector<vector<int>> arr = {{1, 2}, {3, 4}};
        vector<int> output = wavePrint(arr, 2, 2);
        for (int num : output)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}