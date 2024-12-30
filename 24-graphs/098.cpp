#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
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

vector<int> topologicalSort(unordered_map<int, vector<int>> &adj);

string findOrder(vector<string> dict, int k)
{
    int n = dict.size();

    // create the graph
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());

        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topologicalSort(adj);
    string ans = "";
    for (auto it : topo)
        ans = ans + char(it + 'a');
    return ans;
}

vector<int> topologicalSort(unordered_map<int, vector<int>> &adj)
{
    int V = adj.size();

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

        // node in the topo sort
        // so remove it from the indegree
        for (auto nei : adj[node])
        {
            indegree[nei]--;
            if (indegree[nei] == 0)
                q.push(nei);
        }
    }

    return ans;
}

int main()
{

    return 0;
}