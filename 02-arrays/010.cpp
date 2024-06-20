#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n);
void printArray(vector<int> arr);
void printArray(vector<vector<int>> arr);

// Q1: Swap alternate elements in an array
void swap_alternates(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        // condition to keep element in range
        // (i+1) next element is less than the size of array
        if (i + 1 < n)
            swap(arr[i], arr[i + 1]);
    }
}

// Q2: Find Unique
/*
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
Note:
Unique element is always present in the array/list according to the given condition.

n = 2m+1 => always odd length array
*/

int findUnique(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

// Q3:
// Leetcode 1207: Unique Number of Occurrences
bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    unordered_map<int, int> unique;

    for (auto &item : freq)
    {
        if (unique.find(item.second) != unique.end())
            return false;
        else
            unique[item.second]++;
    }

    return true;
}

// Q4: Duplicate in an array
/*
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.
For example:
Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
Note: A duplicate number is always present in the given array.
*/

int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;

    // xor all elements of the array
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    // xor range from 1 to n-1
    for (int i = 1; i <= n - 1; i++)
    {
        ans = ans ^ i;
    }

    return ans;
}

// Q5:
// Leetcode 442: Find All Duplicates in an Array

// TC: O(N)
// SC: O(1)
vector<int> findDuplicates(vector<int> &nums)
{
    // Trick: use -ve sign to mark a value visited
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        // check if already visited(is already -ve)
        if (nums[abs(nums[i]) - 1] < 0)
            result.push_back(abs(nums[i]));
        else
            nums[abs(nums[i]) - 1] *= -1;
    }

    return result;
}

// TC: O(N)
// SC: O(N)
vector<int> findDuplicates_brute_force(vector<int> &nums)
{
    unordered_map<int, int> freq;
    vector<int> ans;

    // make the frequency map
    for (int i = 0; i < nums.size(); i++)
    {
        // check for items with more than 1 frequency
        if (freq[nums[i]] >= 1)
            ans.push_back(nums[i]);
        else
            freq[nums[i]]++;
    }

    return ans;
}

// Q6: Array Intersection
/*
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.
*/
// - brute force (results in TLE)
// - use sorted order to advantage
// - use two pointers trick for most optimal solution
//      - these two pointers approach are on different arrays

// TC: O(max(n, m))
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
}

// Q7: Pair Sum
/*
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value.
Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.
*/

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    int n = arr.size();
    vector<vector<int>> ans;

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> pair;
                pair.push_back(min(arr[i], arr[j]));
                pair.push_back(max(arr[i], arr[j]));
                ans.push_back(pair);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// Q8: Triplet Sum
vector<vector<int>> triplet_sum(vector<int> arr, int target)
{
    vector<vector<int>> ans;

    int n = arr.size();
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            for (int k = j + 1; k <= n - 1; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    ans.push_back({arr[i], arr[j], arr[k]});
                }
            }
        }
    }

    return ans;
}

// Q9: Sort 0,1
/*
given an array of containing only values 0 and 1
e.g => { 0, 1, 1, 0, 0, 1 }
output => { 0, 0, 0, 1, 1, 1 }

Solutions
- counting with freq map/array ( O(n) )
- using sort ( O(nlog(n)) )
- two pointers ( O(n) )
*/

void sort_0_1(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        while (arr[left] == 0 && left < right)
        {
            left++;
        }

        while (arr[right] == 1 && left < right)
        {
            right--;
        }

        if (arr[left] == 1 && arr[right] == 0 && left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void sort_0_1_alt(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        if (arr[left] == 0)
        {
            left++;
        }
        else if (arr[right] == 1)
        {
            right--;
        }
        else if (arr[left] == 1 && arr[right] == 0)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Q10:
// Leetcode 75: Sort Colors
// TC: O(n)
// SC: O(1)
// single pass
void sortColors(vector<int> &nums)
{
    // using quicksort partition aka Dutch National Flag algorithm
    int left = 0;
    int right = nums.size() - 1;

    int i = 0;

    while (i <= right)
    {
        if (nums[i] == 0)
        {
            swap(nums[left], nums[i]);
            left++;
            i++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[right]);
            right--;
            // i++; // don't increment i, as it puts zero in between 1's
        }
    }
}

// TC: O(n)
// SC: O(1)
// double pass
void sortColors_alt_bucket_sort(vector<int> &nums)
{
    // this question is solved using bucket sort => TC: O(n)
    // there are 3 types of buckets (0, 1, 2)
    vector<int> buckets(3);

    // frequency arrays
    for (auto num : nums)
    {
        buckets[num]++;
    }

    // we cant not create an output array
    // as we have to sort it in-place without using extra memory => SC: O(1)
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        while (buckets[i] > 0)
        {
            nums[j] = i;
            j++;
            buckets[i]--;
        }
    }
}

int main()
{
    // check for both cases
    int even[8] = {5, 2, 9, 4, 7, 6, 1, 0};
    int odd[5] = {11, 33, 9, 76, 43};

    cout << "Even" << endl;
    printArray(even, 8);
    swap_alternates(even, 8);
    printArray(even, 8);
    cout << endl;

    cout << "Odd" << endl;
    printArray(odd, 5);
    swap_alternates(odd, 5);
    printArray(odd, 5);
    cout << endl;

    int find_u[] = {2, 3, 1, 6, 3, 6, 2};

    cout << "Find Unique" << endl;
    printArray(find_u, 7);
    cout << "Unique: " << findUnique(find_u, 7) << endl;
    cout << endl;

    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << "Unique Occurences" << endl;
    cout << "UO: " << uniqueOccurrences(arr) << endl;
    cout << endl;

    arr = {1, 2, 3, 4, 5};
    cout << "Triplet Sum" << endl;
    printArray(triplet_sum(arr, 12));
    cout << endl;

    // arr = {0, 1, 1, 0, 0, 1};
    arr = {1, 1, 0, 0, 0, 0, 1, 0};
    cout << "Sort 0 and 1" << endl;
    sort_0_1(arr);
    printArray(arr);
    cout << endl;

    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printArray(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> row = arr[i];
        for (int j = 0; j < row.size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}