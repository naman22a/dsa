#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 1. Adjacency Matrix

// TC: O(M)
// SC: O(N^2)
void adj_matrix()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    // using VLAs
    // i know it is a bad practice
    int adj[n + 1][n + 1]; // 1 based graph

    for (int i = 0; i < m; i++)
    {
        int u;
        cout << "Enter u: ";
        cin >> u;

        int v;
        cout << "Enter v: ";
        cin >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

// 2. Adjacency List

// TC: O(N + M)
// SC: O(2.E)
void adj_matrix_using_frequency_array()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<int> adj[n + 1]; // O(N)

    // O(M)
    for (int i = 0; i < m; i++)
    {
        int u;
        cout << "Enter u: ";
        cin >> u;

        int v;
        cout << "Enter v: ";
        cin >> v;

        // for undirected graph, SC: O(2.E)
        adj[u].push_back(v);
        adj[v].push_back(u);

        // for directed graph, SC: O(E)
        // adj[u].push_back(v);
    }
}

// TC: O(N + M)
// SC: O(2.E)
void adj_matrix_using_frequency_array()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < m; i++)
    {
        int u;
        cout << "Enter u: ";
        cin >> u;

        int v;
        cout << "Enter v: ";
        cin >> v;

        // for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

        // for directed graph
        // adj[u].push_back(v);
    }
}

int main()
{

    return 0;
}