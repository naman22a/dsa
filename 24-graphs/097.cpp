#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(V + E)
// SC: O(2.V)
bool isCyclic(int V, vector<vector<int>> adj)
{
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

    // vector<int> topoSort;
    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // topoSort.push_back(node);
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

    // return topoSort.size() != V;
    return count != V;
}

int main()
{

    return 0;
}