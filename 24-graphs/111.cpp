#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int timer = 0;

    void dfs(int node, int parent, vector<int> &visited, vector<int> &tin, vector<int> &low, vector<int> &markPoints, vector<int> adj[])
    {
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child = 0;

        for (auto nei : adj[node])
        {
            if (nei == parent)
                continue;

            if (!visited[nei])
            {
                dfs(nei, node, visited, tin, low, markPoints, adj);
                low[node] = min(low[node], low[nei]);

                if (low[nei] >= tin[node] && parent != -1)
                    markPoints[node] = 1;
                child++;
            }
            else
                low[node] = min(low[node], tin[nei]);
        }

        if (child > 1 && parent == -1)
            markPoints[node] = 1;
    }

public:
    // TC: O(V + 2E + V) -> O(V + E)
    // SC: O(V + 2E + 3V) -> O(V + E)
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> tin(V); // time of insertion
        vector<int> low(V);

        vector<int> markPoints(V, 0);

        for (int node = 0; node < V; node++)
        {
            if (!visited[node])
            {
                dfs(node, -1, visited, tin, low, markPoints, adj);
            }
        }

        vector<int> points;

        for (int node = 0; node < V; node++)
        {
            if (markPoints[node] == 1)
                points.push_back(node);
        }

        if (points.size() == 0)
            return {-1};

        return points;
    }
};

int main()
{

    return 0;
}