#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(V + 2E) ~ O(E + V)
// SC: O(2V) ~ O(V)
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // V is the number of nodes
    // same code will work for both directed and undirected graph

    vector<int> visited(V, 0);
    visited[0] = 1;

    vector<int> traversal;
    queue<int> q;
    q.push(0); // add starting node

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        traversal.push_back(node);

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }

    return traversal;
}

int main()
{

    return 0;
}