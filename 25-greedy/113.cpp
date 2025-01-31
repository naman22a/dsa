#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Q1:
// Leetcode 455: Assign Cookies

// TC: O(N.log(N) + M.log(M) + M)
// SC: O(1)
int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n = g.size();
    int m = s.size();

    sort(s.begin(), s.end());
    sort(g.begin(), g.end());

    int left = 0;
    int right = 0;

    while (left < m && right < n)
    {
        if (g[right] <= s[left])
            right++;
        left++;
    }

    return right;
}

// Q2: Fractional Knapsack
/*
Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary. Return the maximum value as a double, rounded to 6 decimal places.
*/

typedef struct
{
    int value;
    int weight;
} Item;

bool customComparator(Item a, Item b)
{
    return ((double)a.value / a.weight) > ((double)b.value / b.weight);
}

// TC: O(N + N.log(N))
// SC: O(N), could have done without it, could have been O(1)
double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();

    vector<Item> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = {val[i], wt[i]};

    sort(arr.begin(), arr.end(), customComparator);

    double totalValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= capacity)
        {
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        }
        else
        {
            totalValue += (arr[i].value / (double)arr[i].weight) * capacity;
            break;
        }
    }

    return totalValue;
}

// Q3:
// Leetcode 860: Lemonade Change

// TC: O(N)
// SC: O(1)
bool lemonadeChange(vector<int> &bills)
{
    int five = 0;
    int ten = 0;
    // int twenty = 0; // no significance

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
            five++;
        else if (bills[i] == 10)
        {
            if (five)
            {
                five--;
                ten++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (ten && five)
            {
                ten--;
                five--;
            }
            else if (five >= 3)
                five -= 3;
            else
                return false;
        }
    }

    return true;
}

// Q4:
// Leetcode 678: Valid Parenthesis String

// TC: O(N)
// SC: O(1)
bool checkValidString(string s)
{

    int mini = 0, maxi = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            mini++;
            maxi++;
        }
        else if (ch == ')')
        {
            mini--;
            maxi--;
        }
        else
        {
            mini--;
            maxi++;
        }

        if (mini < 0)
            mini = 0;

        // edge case: ")....somthing"
        if (maxi < 0)
            return false;
    }

    return mini == 0;
}

int main()
{

    return 0;
}