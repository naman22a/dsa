#include <iostream>
#include <vector>
using namespace std;

// Floyd Warshall Algorithm
// -> Multi Source Shortest Path Algorithm
// tells the shortest path from all nodes to all nodes
// helps to detect negative cycles as well
// min(d[i][k] + d[k][j])
// -> Brute Force Algorithm

// TC: O(N^3)
// SC: O(N^2)
void shortestDistance(vector<vector<int>> &mat)
{
    int n = mat.size();

    // do
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 1e9;
            if (i == j)
                mat[i][j] = 0;
        }
    }

    // Floyd Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }
    }

    // How to detect negative cycles
    /* for (int i = 0; i < n; i++)
    {
        if (mat[i][i] < 0)
            cout << "Negative cycle found" << endl;
    } */

    // undo
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1e9)
                mat[i][j] = -1;
        }
    }
}

int main()
{

    return 0;
}