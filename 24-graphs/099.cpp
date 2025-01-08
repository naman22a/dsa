#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <climits>
using namespace std;

// Q1:
/*
Shortest Path in Undirected Graph with Unit Weights

Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
Output: 0 1 2 1 2 3 3 4 4

You are given an adjacency matrix, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
*/

// TC: O(V + 2E)
// SC: O(V)
// similar to BFS
vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int n = adj.size(); // Number of vertices
    vector<int> dist(n, -1);

    // BFS
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // Traverse all neighbors of the current node
        for (int nei : adj[node])
        {
            // If not visited
            if (dist[nei] == -1)
            {
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }

    return dist;
}

// Q2:
/*
Shortest path in Directed Acyclic Graph

Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
*/

void dfs(unordered_map<int, vector<pair<int, int>>> &adj, unordered_set<int> &visited, stack<int> &st, int node);

// TC: O(V + 2E)
// SC: O(V)

// Logic: topo sort + relaxation of edges

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    // step 0: create the graph
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    // step 1: do a topo sort on the graph(DAG)
    stack<int> st;
    unordered_set<int> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited.count(i))
        {
            dfs(adj, visited, st, i);
        }
    }

    // step 2: take out of nodes one by one from the stack and relax the edges
    vector<int> dist(V, INT_MAX);

    // mark source node as zero
    dist[0] = 0; // if src is given then "dist[src] = 0"

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // If the node is unreachable, skip relaxation
        if (dist[node] != INT_MAX)
        {

            for (auto nei : adj[node])
            {
                int v = nei.first;
                int wt = nei.second;

                if (dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
            }
        }
    }

    // Replace INT_MAX with -1 for unreachable nodes
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }

    return dist;
}

void dfs(unordered_map<int, vector<pair<int, int>>> &adj, unordered_set<int> &visited, stack<int> &st, int node)
{
    visited.insert(node);

    for (auto nei : adj[node])
    {
        int v = nei.first;
        if (!visited.count(v))
            dfs(adj, visited, st, v);
    }

    st.push(node);
}

int main()
{

    return 0;
}