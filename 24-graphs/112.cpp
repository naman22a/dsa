#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Strongly Connected Components
// Only valid on Directed Graphs

void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
{
    visited[node] = 1;

    for (auto nei : adj[node])
    {
        if (!visited[nei])
            dfs(nei, visited, adj, st);
    }

    st.push(node);
}

void dfs2(int node, vector<int> &visited, vector<vector<int>> &adj)
{
    visited[node] = 1;

    for (auto nei : adj[node])
    {
        if (!visited[nei])
            dfs2(nei, visited, adj);
    }
}

// TC: O(V + E)
// SC: O(V + E + 2V)
int kosaraju(vector<vector<int>> &adj)
{
    int V = adj.size();

    // TC: O(V + E)
    // 1. store the graph in the stack
    vector<int> visited(V, 0);
    stack<int> st;
    for (int node = 0; node < V; node++)
    {
        if (!visited[node])
            dfs(node, visited, adj, st);
    }

    // TC: O(V + E)
    // 2. reverse the graph
    vector<vector<int>> adjT(V);

    for (int node = 0; node < V; node++)
    {
        visited[node] = 0; // reuse this for next DFS, mark everything as unvisited
        for (auto nei : adj[node])
        {
            // node -> nei
            // nei -> node
            adjT[nei].push_back(node);
        }
    }

    // TC: O(V + E)
    // 3. find the SCC's by performing DFS
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            scc++;
            dfs2(node, visited, adjT);
        }
    }

    return scc;
}

int main()
{

    return 0;
}