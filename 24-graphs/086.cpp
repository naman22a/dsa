#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
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

// TC: O(V + 2E) ~ O(E + V)
// SC: O(2V) ~ O(V)
vector<int> bfsOfGraph_alt(int V, vector<int> adj[])
{
    unordered_set<int> visited;
    visited.insert(0);

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
            if (visited.find(neighbour) == visited.end())
            {
                visited.insert(neighbour);
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