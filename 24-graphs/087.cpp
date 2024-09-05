#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(vector<int> adj[], unordered_set<int> &visited, vector<int> &traversal, int node)
{
    visited.insert(node);
    traversal.push_back(node);

    for (auto nei : adj[node])
    {
        if (visited.find(nei) == visited.end())
            dfs(adj, visited, traversal, nei);
    }
}

// TC: O(V + E)
// SC: O(V)
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> traversal;
    unordered_set<int> visited;
    int start = 0;
    dfs(adj, visited, traversal, start);
    return traversal;
}

int main()
{

    return 0;
}