#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// Q1: Length of string
int getLength(char s[])
{
    int length = 0;

    while (s[length] != '\0')
        length++;

    return length;
}

// Q2: Reverse a String
void reverseString(char s[])
{
    int left = 0;
    int right = getLength(s) - 1;

    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// Q3: Check if a string is a palindrome
/*
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.
String 'S' is NOT case sensitive.
*/

// TC: O(n)
// SC: O(1)
bool checkPalindrome(char s[])
{
    int left = 0;
    int right = strlen(s);

    while (left < right)
    {
        // while we not reach an alphanumeric character keep incrementing the start pointer
        while (!isalnum(s[left]) && left < right)
            left++;

        // while we not reach an alphanumeric character keep decrementing the end pointer
        while (!isalnum(s[right]) && left < right)
            right--;

        // if even a single pair is not equal return false
        if (tolower(s[left]) != tolower(s[right]) && left < right)
            return false;

        left++;
        right--;
    }

    return true;
}

// Q4:
// Leetcode 125: Valid Palindrome

// Q5:
// Leetcode 186: Reverse Words in a String II
// i/p -> My name is Naman
// o/p -> Naman is name My

// helper function
void reverse(string &s, int left, int right)
{
    while (left <= right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// TC: O(N)
// SC: O(1)
void reverseWords(string &s)
{
    reverse(s, 0, s.size() - 1);

    int left = 0;
    int right = 0;
    int index = 0; // to reset the right pointer when it gets lost while reversing the string

    while (right < s.size())
    {
        if (s[right] != ' ')
        {
            right++;
        }
        else
        {
            index = right;
            right--;

            reverse(s, left, right);

            // reset (move to next word)
            right = index + 1;
            left = right;
        }
    }

    // handle edge case for last word
    right--;
    reverse(s, left, right);
}

// Q6: Maximum Occuring Character in a String
// TC: O(26.N) -> O(N)
// SC: O(26) -> O(1)
char max_char_in_string(string str)
{
    int freq[26] = {0}; // initialize all with zero

    // build frequency array
    for (auto ch : str)
    {
        // assume only lowercase are given in input
        int index = ch - 'a';
        freq[index]++;
    }

    int maxi = -1;
    int ans = -1;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < freq[i])
        {
            ans = i;
            maxi = freq[i];
        }
    }

    char ch = ans + 'a';
    return ch;
}

// Q: Replace spaces
// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.

void replaceSpaces(string &s)
{
    string temp = "";

    for (auto ch : s)
    {
        if (ch == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
            temp.push_back(ch);
    }

    s = temp;
}

// Q7:
// Leetcode 1910: Remove All Occurrences of a Substring
// TC: O(N)
// SC: O(1)
string removeOccurrences(string s, string part)
{
    // s.find(part) -> finds substring and return's it's starting index
    while (s.length() != 0 && s.find(part) < s.length())
        s.erase(s.find(part), part.length());

    return s;
}

// Q:
// Leetcode 567: Permutation in String
// this question uses "Sliding Window" Algorithm
// TC: O(26) + O(n) => O(n)
// SC: O(26) + O(26) => O(1)
bool checkInclusion(string s1, string s2)
{
    // edge case
    if (s1.size() > s2.size())
        return false;

    vector<int> s1_freq(26, 0);
    vector<int> s2_freq(26, 0);

    // create frequency of both strings in arrays
    for (int i = 0; i < s1.size(); i++)
    {
        s1_freq[s1[i] - 'a']++;
        s2_freq[s2[i] - 'a']++;
    }

    // check if the first window is already a match
    int matches = 0;
    for (int i = 0; i < 26; i++)
    {
        if (s1_freq[i] == s2_freq[i])
            matches++;
    }

    int left = 0;
    for (int right = s1.size(); right < s2.size(); right++)
    {
        // frequency of both arrays match
        // (it is also the condition for the first window match case above)
        // (no need to re write this statement above)
        if (matches == 26)
            return true;

        // for adding character in the window
        int index = s2[right] - 'a';
        s2_freq[index]++;

        if (s1_freq[index] == s2_freq[index])
            matches++;

        else if (s1_freq[index] + 1 == s2_freq[index])
            matches--;

        // for removing the a character
        index = s2[left] - 'a';
        s2_freq[index]--;

        if (s1_freq[index] == s2_freq[index])
            matches++;

        else if (s1_freq[index] - 1 == s2_freq[index])
            matches--;

        left++;
    }

    return matches == 26;
}

// Q8:
// Leetcode 1047: Remove All Adjacent Duplicates In String
// TC: O(N)
// SC: O(N)
string removeDuplicates(string s)
{
    stack<char> st;

    for (auto ch : s)
    {
        if (st.empty())
            st.push(ch);
        else
        {
            if (ch == st.top())
                st.pop();
            else
                st.push(ch);
        }
    }

    string output;

    while (!st.empty())
    {
        char ch = st.top();
        st.pop();
        output = ch + output;
    }

    return output;
}

// Q9:
// Leetcode 443: String Compression
int compress(vector<char> &chars)
{
    int i = 0;
    int ans = 0;
    int n = chars.size();

    while (i < n)
    {
        int j = i + 1;

        while (j < n && chars[i] == chars[j])
            j++;

        // store old character
        chars[ans] = chars[i];
        ans++;
        int count = j - i;
        if (count > 1)
        {
            // converting count into single digit
            string cnt = to_string(count);
            for (char digit : cnt)
            {
                chars[ans] = digit;
                ans++;
            }
        }
        // new or different character encountered
        i = j;
    }

    return ans;
}

int main()
{
    if (0)
    {
        char name[20];

        cout << "Enter name: ";
        cin >> name;

        // will only print characters before \0, cout terminates the string output at \0
        name[2] = '\0';
        cout << "Hello, " << name << endl;
    }

    {
        char name[] = "Naman";
        cout << "Length: " << getLength(name) << endl;

        cout << endl;
    }

    {
        char s[] = "abcd";

        cout << "Original: " << s << endl;
        reverseString(s);
        cout << "Reverse: " << s << endl;

        cout << endl;
    }

    {
        char s[] = "c1 O$d@eeD o1c";
        cout << "Palindrome: " << checkPalindrome(s) << endl;

        cout << endl;
    }

    {
        string s = "My name is Naman";

        cout << s << endl;
        reverseWords(s);
        cout << s << endl;

        cout << endl;
    }

    {
        string s = "test";
        cout << "String: " << s << endl;
        cout << "Max Occur: " << max_char_in_string(s) << endl;

        cout << endl;
    }

    // cin getline cin.getline(str, len) -> used to opt out of the default behaviour of cin
    // input strings with space
    if (0)
    {
        // formatted input -> cin
        // unformatted input -> cin.getline

        cout << "Enter full name: ";
        string name;
        // cin.getline(cin, name);
        getline(cin, name);
        cout << "Hello, " << name << endl;
    }

    {
        string s = "Hello world";
        cout << "Original: " << s << endl;
        replaceSpaces(s);
        cout << "Replace Spaces: " << s << endl;
    }

    {
        string s = "abbaca";
        cout << "Output: " << removeDuplicates(s) << endl;

        cout << endl;
    }

    return 0;
}