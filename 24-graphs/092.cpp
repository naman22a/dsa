#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using BFS

bool check(int start, int V, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto nei : adj[node])
        {
            // if neighbour node is not colored yet
            // will give the opposite color of the node
            if (color[nei] == -1)
            {
                color[nei] = !color[node];
                q.push(nei);
            }
            // if the neighbour node is having the same color -> not bipartite
            else if (color[nei] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

// TC: O(E + V)
// SC: O(V)
bool isBipartite(int V, vector<int> adj[])
{
    // visited array
    vector<int> color(V, -1);

    // check for multiple components
    // zero index based graph
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (check(i, V, adj, color) == false)
                return false;
        }
    }

    return true;
}

// using DFS

bool dfs(vector<int> adj[], vector<int> &color, int node, int currentColor)
{
    color[node] = currentColor;

    for (auto nei : adj[node])
    {
        if (color[nei] == -1)
        {
            if (dfs(adj, color, nei, !currentColor) == false)
                return false;
        }
        else if (color[nei] == currentColor)
            return false;
    }

    return true;
}

// TC: O(E + V)
// SC: O(V)
bool _isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(adj, color, i, 0) == false)
                return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}