#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Leetcode 1192: Critical Connections in a Network

class Solution
{
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &visited, unordered_map<int, vector<int>> &adj, vector<int> &time, vector<int> &low, vector<vector<int>> &bridges)
    {
        visited[node] = 1;

        time[node] = low[node] = timer;
        timer++;

        for (auto nei : adj[node])
        {
            if (nei == parent)
                continue;

            if (!visited[nei])
            {
                dfs(nei, node, visited, adj, time, low, bridges);
                low[node] = min(low[node], low[nei]);

                if (low[nei] > time[node])
                    bridges.push_back({nei, node});
            }
            else
                low[node] = min(low[node], low[nei]);
        }
    }

public:
    // TC: O(V + 2E)
    // SC: O(V + 2E + 3N)
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, vector<int>> adj;
        for (auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        vector<int> visited(n, 0);
        vector<int> time(n); // time of insertion
        vector<int> low(n);

        vector<vector<int>> bridges;
        dfs(0, -1, visited, adj, time, low, bridges);
        return bridges;
    }
};

int main()
{

    return 0;
}