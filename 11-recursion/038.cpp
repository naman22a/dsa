#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Q1:
// Leetcode 17: Letter Combinations of a Phone Number
// solve using backtracking

unordered_map<char, string> charToDigits = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

void backtrack(vector<string> &result, string digits, string combination, int i)
{
    if (i >= digits.size())
    {
        result.push_back(combination);
        return;
    }

    for (char ch : charToDigits[digits[i]])
    {
        combination.push_back(ch);
        backtrack(result, digits, combination, i + 1);

        // cleanup: for when we go back to move onto the next character
        combination.pop_back();
    }
}

// TC: O(N.pow(4, N))
// SC: O(N)
vector<string> letterCombinations(string digits)
{

    // edge case
    if (digits.empty())
        return {};

    vector<string> result;
    string combination;

    backtrack(result, digits, combination, 0);

    return result;
}

void print(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    string digits = "23";
    cout << "digits: " << digits << endl;
    cout << "output: ";
    print(letterCombinations(digits));

    return 0;
}