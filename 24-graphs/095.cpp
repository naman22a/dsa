#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printVector(vector<int>);

void dfs(vector<vector<int>> &adj, vector<int> &visited, stack<int> &st, int node)
{
    visited[node] = 1;

    for (int nei : adj[node])
    {
        if (!visited[nei])
            dfs(adj, visited, st, nei);
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int V = adj.size();

    vector<int> visited(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(adj, visited, st, i);
    }

    vector<int> ans;

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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