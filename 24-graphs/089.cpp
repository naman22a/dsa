#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Undirected Graph Cycle (GFG)
/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.
*/

// TC: O(V + 2E)
// SC: O(V)
bool detect(int src, vector<int> adj[], unordered_set<int> &visited)
{
    visited.insert(src);
    queue<pair<int, int>> q; // (node, where it came from)
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto nei : adj[node])
        {
            if (visited.find(nei) == visited.end())
            {
                visited.insert(nei);
                q.push({nei, node});
            }
            // If the neighbor is visited and not the parent, it's a cycle
            else if (parent != nei)
                return true;
        }
    }

    return false;
}

// TC: O(V + 2E) + O(V)
// SC: O(V)
bool isCycle(int V, vector<int> adj[])
{
    unordered_set<int> visited;
    for (int i = 0; i < V; i++) // 0 indexed graph
    {
        if (visited.find(i) == visited.end())
        {
            if (detect(i, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}
