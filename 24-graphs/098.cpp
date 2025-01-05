#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

// Q1:
// Leetcode 207: Course Schedule

// TC: O(V + E)
// SC: O(V)
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // build adj list
    unordered_map<int, vector<int>> adj;
    for (auto prereq : prerequisites)
        adj[prereq[1]].push_back(prereq[0]);

    // topo sort
    int V = numCourses;
    vector<int> indegree(V, 0);

    for (int node = 0; node < V; node++)
    {
        for (auto incommingNode : adj[node])
            indegree[incommingNode]++;
    }

    queue<int> q;
    for (int node = 0; node < V; node++)
    {
        if (indegree[node] == 0)
            q.push(node);
    }

    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        count++;

        // node in the topo sort
        // so remove it from the indegree
        for (auto nei : adj[node])
        {
            indegree[nei]--;
            if (indegree[nei] == 0)
                q.push(nei);
        }
    }

    return count == V;
}

// Q2:
// Leetcode 210: Course Schedule II

// TC: O(V + E)
// SC: O(V)
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    // build adj list
    unordered_map<int, vector<int>> adj;
    for (auto prereq : prerequisites)
        adj[prereq[1]].push_back(prereq[0]);

    // topo sort
    int V = numCourses;
    vector<int> indegree(V, 0);

    for (int node = 0; node < V; node++)
    {
        for (auto incommingNode : adj[node])
            indegree[incommingNode]++;
    }

    queue<int> q;
    for (int node = 0; node < V; node++)
    {
        if (indegree[node] == 0)
            q.push(node);
    }

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto nei : adj[node])
        {
            indegree[nei]--;
            if (indegree[nei] == 0)
                q.push(nei);
        }
    }

    // Check for cycles
    if (ans.size() != numCourses)
        return {};

    return ans;
}

// Q3:
// Leetcode 802: Find Eventual Safe States

// TC: O(V + E)
// SC: O(V)
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();

    // reverse all the edges
    vector<vector<int>> adj(V); // reversed
    vector<int> indegree(V, 0);
    for (int node = 0; node < V; node++)
    {
        // node -> nei
        // convert to
        // nei -> node
        for (auto nei : graph[node])
        {
            adj[nei].push_back(node);
            indegree[node]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;

    // topo sort
    for (int node = 0; node < V; node++)
    {
        // terminal node
        // get all the nodes with indegree zero
        if (indegree[node] == 0)
            q.push(node);
    }

    // do a removal of edges on neighbours
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for (auto nei : adj[node])
        {
            indegree[nei]--;
            if (indegree[nei] == 0)
                q.push(nei);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

// Q4:
// Leetcode 296: Alien dictionary
// see this https://youtu.be/6kTZYvNNyps?si=RqsWPEsJAuAgpS7G

class Solution
{
private:
    unordered_map<char, unordered_set<char>> adjList;
    unordered_map<char, bool> visited; // false -> visited, true -> in current path
    string result;

public:
    string foreignDictionary(vector<string> &words)
    {
        // using topological sort
        // applied on DAG -> Directed Aycyclic Graph
        // use DFS or BFS to traverse the graph formed by the letter ordering got from the sorted list of words
        // cycle in graph => no solution
        // if connected components are more than 1, then we have multiple solutions
        // do a post order dfs on a graph to make the alien abcd...xyz
        // reverse the ouput of post order dfs, which is the topological sort

        for (auto word : words)
        {
            for (auto ch : word)
                adjList[ch];
        }

        // words.size() - 1 to get each pair, and hence avoid out of range case
        for (int i = 0; i < words.size() - 1; i++)
        {
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLength = min(w1.size(), w2.size());

            // prefix of the words is same, but the first word is longer than the second word
            if (w1.size() > w2.size() && w1.substr(0, minLength) == w2.substr(0, minLength))
                return "";

            for (int j = 0; j < minLength; j++)
            {
                // first different character
                if (w1[j] != w2[j])
                {
                    adjList[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for (auto &item : adjList)
        {
            char c = item.first;
            // detected a cycle
            if (dfs(c))
                return "";
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool dfs(char c)
    {
        // already in current path, but we visited it again => cycle detected
        if (visited.find(c) != visited.end())
            return visited[c];

        visited[c] = true;

        for (auto nei : adjList[c])
        {
            // cycle detected
            if (dfs(nei))
                return true;
        }

        visited[c] = false;
        result.push_back(c);
        return false;
    }
};

int main()
{

    return 0;
}