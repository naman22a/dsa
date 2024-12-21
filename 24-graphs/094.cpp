#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Q1:
// Leetcode 127: Word Ladder

// TC: O(wordList.length * word.length * 26)
// SC: O(wordList.length)
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    unordered_set<string> wlist(wordList.begin(), wordList.end());
    wlist.erase(beginWord);

    // TC: wordList.length * word.length * 26
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord)
            return steps;

        // TC: word.length * 26
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];

            for (int ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                // exists in the word list
                if (wlist.find(word) != wlist.end())
                {
                    wlist.erase(word); // mark visited
                    q.push({word, steps + 1});
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

// Q2:
// Same as word ladder I
// Leetcode 433: Minimum Genetic Mutation
int minMutation(string startGene, string endGene, vector<string> &bank)
{
    queue<pair<string, int>> q;
    q.push({startGene, 1});

    unordered_set<string> geneBank(bank.begin(), bank.end());
    geneBank.erase(startGene);

    while (!q.empty())
    {
        string gene = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (gene == endGene)
            return steps - 1;

        for (int i = 0; i < gene.size(); i++)
        {
            char original = gene[i];
            string genes = "ACGT";

            for (char ch : genes)
            {
                gene[i] = ch;

                if (geneBank.find(gene) != geneBank.end())
                {
                    geneBank.erase(gene);
                    q.push({gene, steps + 1});
                }
            }

            gene[i] = original;
        }
    }

    return -1;
}

// Q3:
// Leetcode 126: Word Ladder II

// unoptimized
// TC: too complicted
// SC: too complicted

/*
Time Complexity: O(N⋅L+P⋅L)
Space Complexity: O(P⋅L+N)
where:
N: Number of words in the wordList
L: Length of each word
P: Number of valid paths
*/

vector<vector<string>> findLadders_unoptimized(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);

    int level = 0;

    vector<vector<string>> ans;

    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        // erase all the words that has been used in the previous levels to transform
        if (vec.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
                st.erase(it);
            usedOnLevel.clear();
        }

        string word = vec.back();

        // store the answers
        if (word == endWord)
        {
            // first sequence where we reached end
            if (ans.size() == 0)
                ans.push_back(vec);
            else if (ans[0].size() == vec.size())
                ans.push_back(vec);
        }

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word); // mark as visited on the level
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

    return ans;
}

// TC: too complicted
// SC: too complicted

/*
Time Complexity: O(N⋅L+P⋅L),
where:
N: Number of words in the wordList
L: Length of each word
P: Number of valid paths
Space Complexity: O(N+L), where
L accounts for the recursion stack and
N for the auxiliary data structures.
*/

// using BFS + backtracking

void dfs(vector<vector<string>> &ans, unordered_map<string, int> &mpp, string &beignWord, string word, vector<string> &seq)
{
    if (word == beignWord)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }

    int steps = mpp[word];
    int size = word.size();
    for (int i = 0; i < size; i++)
    {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
            {
                seq.push_back(word);
                dfs(ans, mpp, beignWord, word, seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> ans;
    unordered_map<string, int> mpp;
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<string> q;

    q.push(beginWord);
    mpp[beginWord] = 1;
    st.erase(beginWord);

    int size = beginWord.size();
    while (!q.empty())
    {
        string word = q.front();
        int steps = mpp[word];
        q.pop();

        if (word == endWord)
            break;

        for (int i = 0; i < size; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.count(word))
                {
                    q.push(word);
                    st.erase(word);
                    mpp[word] = steps + 1;
                }
            }
            word[i] = original;
        }
    }

    if (mpp.find(endWord) != mpp.end())
    {
        vector<string> seq;
        seq.push_back(endWord);
        dfs(ans, mpp, beginWord, endWord, seq);
    }

    return ans;
}

int main()
{

    return 0;
}