#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Q1:
// Leetcode 1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution
{
public:
    // using Floyd Warshall Algorithm
    // can also be solved using Dijkstra
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // n => no of nodes
        int m = edges.size(); // no of edges

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (auto edge : edges)
        {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int countCity = n;
        int cityNo = -1;

        for (int city = 0; city < n; city++)
        {
            int count = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                    count++;
            }

            if (count <= countCity)
            {
                countCity = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

int main()
{

    return 0;
}