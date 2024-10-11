#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Undirected Graph Cycle (GFG)
/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.
*/

bool dfs(vector<int> adj[], unordered_set<int> &visited, int node, int parent)
{
    visited.insert(node);
    for (auto nei : adj[node])
    {
        if (visited.find(nei) == visited.end())
        {
            if (dfs(adj, visited, nei, node))
                return true;
        }
        // visited and a not parent -> previously visited in path
        else if (nei != parent)
            return true;
    }

    return false;
}

// TC: O(V + 2E)
// SC: O(V)
bool isCycle(int V, vector<int> adj[])
{
    unordered_set<int> visited;

    for (int i = 0; i < V; i++)
    {
        if (visited.find(i) == visited.end())
        {
            if (dfs(adj, visited, i, -1))
                return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}