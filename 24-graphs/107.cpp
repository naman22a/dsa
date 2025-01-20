#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        // (n + 1) for 1 index based graph
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // TC: O(4.alpha) ~ O(1), as alpha is close to 1
    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    // TC: O(4.alpha) ~ O(1), as alpha is close to 1
    void unionByRank(int u, int v)
    {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        // belongs to the same component
        if (up_u == up_v)
            return;

        // smaller gets attached to larger one, thus no change in rank
        if (rank[up_u] < rank[up_v])
            parent[up_u] = up_v;
        else if (rank[up_v] < rank[up_u])
            parent[up_v] = up_u;
        else
        {
            parent[up_v] = up_u;
            rank[up_u]++; // larger one will grow in size
        }
    }

    // TC: O(4.alpha) ~ O(1), as alpha is close to 1
    void unionBySize(int u, int v)
    {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        // belongs to the same component
        if (up_u == up_v)
            return;

        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

int main()
{
    {
        DisjointSet ds(7);
        ds.unionByRank(1, 2);
        ds.unionByRank(2, 3);
        ds.unionByRank(4, 5);
        ds.unionByRank(6, 7);
        ds.unionByRank(5, 6);

        if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
            cout << "Same" << endl;
        else
            cout << "Not same" << endl;

        ds.unionByRank(3, 7);

        if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
            cout << "Same" << endl;
        else
            cout << "Not same" << endl;
    }

    {
        DisjointSet ds(7);
        ds.unionBySize(1, 2);
        ds.unionBySize(2, 3);
        ds.unionBySize(4, 5);
        ds.unionBySize(6, 7);
        ds.unionBySize(5, 6);

        if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
            cout << "Same" << endl;
        else
            cout << "Not same" << endl;

        ds.unionBySize(3, 7);

        if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
            cout << "Same" << endl;
        else
            cout << "Not same" << endl;
    }

    return 0;
}