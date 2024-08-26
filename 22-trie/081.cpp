#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Q1: Implement a Phone Directory Using Trie
/*
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".
*/

struct TrieNode
{
    TrieNode *children[26];
    bool endOfWord = false;

    bool containsKey(char ch)
    {
        return children[ch - 'a'] != NULL;
    }

    void put(char ch, TrieNode *node)
    {
        children[ch - 'a'] = node;
    }

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

    void insert(string word)
    {
        TrieNode *cur = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (!cur->containsKey(word[i]))
                cur->put(word[i], new TrieNode());

            cur = cur->get(word[i]);
        }

        cur->endOfWord = true;
    }

    void printSuggestions(TrieNode *cur, vector<string> &temp, string prefix)
    {
        if (cur->endOfWord)
            temp.push_back(prefix);

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = cur->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix); // using backtracking
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string query)
    {
        TrieNode *prev = root;
        vector<vector<string>> result;
        string prefix = "";

        for (int i = 0; i < query.length(); i++)
        {
            char last_ch = query[i];
            prefix.push_back(last_ch);

            // check of last ch
            TrieNode *cur = prev->children[last_ch - 'a'];

            // if not found
            if (cur == NULL)
            {
                // for remaining characters in query, there will be no matches
                while (i < query.length())
                {
                    result.push_back({"0"});
                    i++;
                }
                break;
            }

            // if found
            vector<string> temp;
            printSuggestions(cur, temp, prefix);

            result.push_back(temp);
            temp.clear();
            prev = cur;
        }

        return result;
    }
};

// TC: O(len(s) * n * max(contact[i]))
// SC: O(n * max(contact[i]))
vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    Trie *trie = new Trie();

    // insert all contacts
    for (int i = 0; i < n; i++)
    {
        string str = contact[i];
        trie->insert(str);
    }

    return trie->getSuggestions(s);
}

int main()
{

    return 0;
}