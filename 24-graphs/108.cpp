#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet;

// TC: O(V + E + E.log(E) + E x ((4 x Alpha)x2))
// TC: O(V + E)
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;

    // TC: O(V + E)
    for (int i = 0; i < V; i++)
    {
        for (auto nei : adj[i])
        {
            int adjNode = nei[0];
            int wt = nei[1];
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }

    // TC: E.log(E)
    sort(edges.begin(), edges.end());
    int weight = 0;
    DisjointSet ds(V);

    // E x ((4 x Alpha)x2)
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // if they do not belong to the same component
        if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
        {
            weight += wt;
            ds.unionBySize(u, v);
        }
    }

    return weight;
}

int main()
{

    return 0;
}

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        // (n + 1) for 1 index based graph
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // TC: O(4.alpha) ~ O(1), as alpha is close to 1
    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    // TC: O(4.alpha) ~ O(1), as alpha is close to 1
    void unionByRank(int u, int v)
    {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        // belongs to the same component
        if (up_u == up_v)
            return;

        // smaller gets attached to larger one, thus no change in rank
        if (rank[up_u] < rank[up_v])
            parent[up_u] = up_v;
        else if (rank[up_v] < rank[up_u])
            parent[up_v] = up_u;
        else
        {
            parent[up_v] = up_u;
            rank[up_u]++; // larger one will grow in size
        }
    }

    // TC: O(4.alpha) ~ O(1), as alpha is close to 1
    void unionBySize(int u, int v)
    {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        // belongs to the same component
        if (up_u == up_v)
            return;

        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};
