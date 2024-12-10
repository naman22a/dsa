#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, int node)
{
    visited[node] = 1;
    pathVisited[node] = 1;

    for (auto nei : adj[node])
    {
        // when the node is not visited
        if (!visited[nei])
        {
            if (dfs(adj, visited, pathVisited, nei) == true)
                return true;
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if (pathVisited[nei])
            return true;
    }

    pathVisited[node] = 0;
    return false;
}

// TC: O(V + E)
// SC: O(2V)
bool isCyclic(int V, vector<vector<int>> adj)
{
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, visited, pathVisited, i) == true)
                return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}