#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printVector(vector<int>);

// TC: O(V + E)
// SC: O(2V)
vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int V = adj.size();

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

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        // node in the topo sort
        // so remove it from the indegree
        for (auto nei : adj[node])
        {
            indegree[nei]--;
            if (indegree[nei] == 0)
                q.push(nei);
        }
    }

    return ans;
}

int main()
{
    int V = 6;
    vector<vector<int>> adj = {
        {},     // 0 index
        {},     // 1 index
        {3},    // 2 index
        {1},    // 3 index
        {0, 1}, // 4 index
        {0, 2}, // 5 index
    };

    vector<int> result = topologicalSort(adj);
    printVector(result);

    return 0;
}

void printVector(vector<int> arr)
{
    for (int elem : arr)
        cout << elem << " ";
    cout << endl;
}