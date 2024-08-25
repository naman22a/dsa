#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1:
// Leetcode 14: Longest Common Prefix

// M is length of string, N is number of strings
// TC: O(M.N)
// SC: O(1)
string longestCommonPrefix_using_brute_force(vector<string> &strs)
{
    // take the first string and compare it with remaining string to find the common prefix
    string result = "";
    for (int i = 0; i < strs[0].length(); i++)
    {
        bool match = true;
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j].size() < i || strs[0][i] != strs[j][i])
            {
                match = false;
                break;
            }
        }

        if (!match)
            break;
        else
            result.push_back(strs[0][i]);
    }
    return result;
}

class TrieNode
{
public:
    TrieNode *children[26] = {0};
    bool endOfWord = false;
    int count = 0; // count of children

    bool containsKey(char ch)
    {
        return children[ch - 'a'] != NULL;
    }

    // points to new trie
    void put(char ch, TrieNode *node)
    {
        children[ch - 'a'] = node;
    }

    // get next node
    TrieNode *get(char ch)
    {
        return children[ch - 'a'];
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}

    // TC: O(L), L is the length of the word
    void insert(string word)
    {
        TrieNode *cur = root;

        for (int i = 0; i < word.length(); i++)
        {
            // if cur node does not contains the letter and create a new trie and put the letter in it
            if (!cur->containsKey(word[i]))
            {
                cur->count++;
                cur->put(word[i], new TrieNode());
            }

            // moves to the reference trie
            cur = cur->get(word[i]);
        }

        // mark the end of the word
        cur->endOfWord = true;
    }

    void lcp(string str, string &ans)
    {
        TrieNode *cur = root;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            // continue
            if (cur->count == 1)
            {
                ans.push_back(ch);
                cur = cur->get(ch); // move to next node
            }
            // if a break is seen in the trie, then stop
            else
                break;

            // if end of word character
            if (cur->endOfWord)
                break;
        }
    }
};

// it is a worse solution then simple brute force approach
// TC: O(M.N)
// SC: O(M.N)
string longestCommonPrefix_using_trie(vector<string> &strs)
{
    Trie *trie = new Trie();

    // insert all strings in trie
    for (auto str : strs)
    {
        if (str.empty())
            return "";
        trie->insert(str);
    }

    string first = strs[0];
    string ans;
    trie->lcp(first, ans);

    return ans;
}

string longestCommonPrefix(vector<string> &strs)
{
    return longestCommonPrefix_using_trie(strs);
}

int main()
{

    return 0;
}
