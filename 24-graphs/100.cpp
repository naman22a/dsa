#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

// Dijkstra Algorithm => BFS + priority queue
// reason for priority queue -> Greedy approach (minimum path cost)
// a queue can also be used but it will result in a brute force solution, exploring all paths
// it does not work when
// -> negative weight -> results in infinite loop
// -> negative cycle

// TC: O(E.log(V))
// SC: O(V + E) = O(V + V^2) = O(V^2) // E = V^2
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int V = adj.size();
    vector<int> dist(V, INT_MAX);

    // min heap of (dist, node) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int wt = it.second;
            int nei = it.first;

            if (dis + wt < dist[nei])
            {
                dist[nei] = dis + wt;
                pq.push({dist[nei], nei});
            }
        }
    }

    return dist;
}

// Dijkstra Algorithm using Set
// set stores unique values
// set stores everything in sorted order

// TC: O(E.log(V))
// SC: O(V + E) = O(V + V^2) = O(V^2) // E = V^2
vector<int> dijkstra_using_set(vector<vector<pair<int, int>>> &adj, int src)
{
    int V = adj.size();
    set<pair<int, int>> st; // { distance, node }
    vector<int> dist(V, INT_MAX);

    st.insert({0, src});
    dist[src] = 0;

    while (!st.empty())
    {
        auto p = *(st.begin());
        int node = p.second;
        int distance = p.first;
        st.erase(p);

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (distance + edgeWeight < dist[adjNode])
            {
                // erase if existed
                if (dist[adjNode] != INT_MAX)
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode] = distance + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

// Print the shortest path

// TC: O(E.log(V) + V)
// SC: O(V + E)
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    int V = n;
    int E = m;

    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto edge : edges)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    // Min Heap -> {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    vector<int> dist(V + 1, INT_MAX);
    dist[1] = 0;

    vector<int> parent(n + 1);
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    while (!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for (auto nei : adj[node])
        {
            int adjNode = nei.first;
            int wt = nei.second;

            if (dis + wt < dist[adjNode])
            {
                dist[adjNode] = dis + wt;
                pq.push({dis + wt, adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if (dist[V] == INT_MAX)
    {
        return {-1};
    }

    // TC: O(V)
    vector<int> path;
    int node = n;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    return path;
}

int main()
{

    return 0;
}