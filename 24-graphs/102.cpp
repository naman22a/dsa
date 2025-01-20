#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Bellman Ford Algorithm
// helps us to detect negative cycles
// only works on directed graph
// if given undirected graph then convert it into a directed graph
// relax all the edges (n-1) times sequentially
/*
relaxation of edges

if(dist[u] + wt < dist[v])
    dist[v] = dist[u] + wt
*/

// TC: O(V*E)
// SC: O(V)
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // TC: O(V*E)
    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    // Nth relaxation to check negative cycle
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            return {-1};
    }

    return dist;
}

int main()
{

    return 0;
}