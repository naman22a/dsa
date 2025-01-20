#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Prim's Algorithm
// Greedy approach

// TC: O(E.log(E))
// SC: O(E + V)
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> visited(V, 0);

    // { wt, node }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if (visited[node])
            continue;

        visited[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];

            if (!visited[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }

    return sum;
}

int main()
{

    return 0;
}