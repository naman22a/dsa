#include <iostream>
using namespace std;

// Q1:
// Leetcode 208: Implement Trie (Prefix Tree)

struct TrieNode
{
    TrieNode *children[26]; // (0 - 25) maps to (a - z)
    bool endOfWord = false;

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
                cur->put(word[i], new TrieNode());

            // moves to the reference trie
            cur = cur->get(word[i]);
        }

        // mark the end of the word
        cur->endOfWord = true;
    }

    // TC: O(L), L is the length of the word
    bool search(string word)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!cur->containsKey(word[i]))
                return false;

            // moves to the next reference trie
            cur = cur->get(word[i]);
        }

        return cur->endOfWord;
    }

    // TC: O(L), L is the length of the prefix
    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!cur->containsKey(prefix[i]))
                return false;

            // moves to the next reference trie
            cur = cur->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{

    return 0;
}