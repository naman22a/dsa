#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Q1:
// Leetcode 1091: Shortest Path in Binary Matrix

// use Dijkstra using Queue ===> BFS
// as edge weights are 1

// TC: O(N^2)
// SC: O(N^2)
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();

    // edge case
    if (grid[0][0] == grid[n - 1][n - 1] && grid[0][0] == 1 &&
        grid[0].size() == 1)
        return -1;

    // edge case
    if (grid[0][0] == grid[n - 1][n - 1] && grid[0].size() == 1)
        return 1;

    pair<int, int> src = {0, 0};
    pair<int, int> dest = {n - 1, n - 1};

    queue<pair<int, pair<int, int>>> q;
    q.push({0, src});

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[src.first][src.second] = 0;

    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for (auto &[dr, dc] : directions)
        {
            int newr = r + dr;
            int newc = c + dc;

            if (newr >= 0 && newr <= n - 1 && newc >= 0 && newc <= n - 1 && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc])
            {
                dist[newr][newc] = dis + 1;
                if (newr == dest.first && newc == dest.second)
                    return dis + 1 + 1;
                q.push({dis + 1, {newr, newc}});
            }
        }
    }
    return -1;
}

// Q2:
// Leetcode 1631: Path With Minimum Effort

// same as Dijkstra
// TC: O(E.log(V))
// TC: O(N.M.log(N.M))
// SC: O(M.N)
int minimumEffortPath(vector<vector<int>> &heights)
{
    int ROWS = heights.size();
    int COLS = heights[0].size();

    vector<vector<int>> dist(ROWS, vector<int>(COLS, INT_MAX));
    dist[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // { diff, { r, c } }
    pq.push({0, {0, 0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == ROWS - 1 && col == COLS - 1)
            return diff;

        for (int i = 0; i < 4; i++)
        {
            int newr = row + dr[i];
            int newc = col + dc[i];

            if (newr >= 0 && newr <= ROWS - 1 && newc >= 0 && newc <= COLS - 1)
            {
                int currentEffort = abs(heights[row][col] - heights[newr][newc]);
                int newEffort = max(currentEffort, diff);
                if (newEffort < dist[newr][newc])
                {
                    dist[newr][newc] = newEffort;
                    pq.push({newEffort, {newr, newc}});
                }
            }
        }
    }

    // not reachable
    return -1;
}

// Q3:
// Leetcode 787: Cheapest Flights Within K Stops

// TC: O(E), E = flights.size()
// SC: O(V)
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto flight : flights)
        adj[flight[0]].push_back({flight[1], flight[2]});

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}}); // { stops, node, distance }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > k)
            continue;

        for (auto nei : adj[node])
        {
            int adjNode = nei.first;
            int wt = nei.second;

            if (cost + wt < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = cost + wt;
                q.push({stops + 1, {adjNode, cost + wt}});
            }
        }
    }

    if (dist[dst] == INT_MAX)
        return -1;

    return dist[dst];
}

// Q4:
// Leetcode 743: Network Delay Time

// TC: O(E.log(V))
// SC: O(V^2)
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto time : times)
        adj[time[0]].push_back({time[1], time[2]});

    // min heap { cost/distance, node }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    unordered_set<int> visited;
    int t = 0;

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited.count(node))
            continue;

        visited.insert(node);
        t = max(t, wt);

        for (auto nei : adj[node])
        {
            int adjNode = nei.first;
            int adjWt = nei.second;

            if (!visited.count(adjNode))
                pq.push({adjWt + wt, adjNode});
        }
    }

    return visited.size() == n ? t : -1;
}

// Q5:
// Leetcode 1976: Number of Ways to Arrive at Destination

// TC: O(E.log(V))
// SC: O(V^2)
int countPaths(int n, vector<vector<int>> &roads)
{
    unordered_map<long long, vector<pair<long long, long long>>> adj;
    for (auto road : roads)
    {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }

    // min heap of { dist, node }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    vector<long long> dist(n, LLONG_MAX);
    vector<long long> ways(n, 0);

    dist[0] = 0;
    ways[0] = 1;

    pq.push({0, 0});

    int mod = 1e9 + 7;

    while (!pq.empty())
    {
        long long dis = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        for (auto nei : adj[node])
        {
            long long adjNode = nei.first;
            long long adjWt = nei.second;

            // This is the first time i am comming
            // with this short distance
            if (dis + adjWt < dist[adjNode])
            {
                dist[adjNode] = dis + adjWt;
                pq.push({dis + adjWt, adjNode});
                ways[adjNode] = ways[node];
            }
            // same path as the shortest path
            else if (dis + adjWt == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}

// Q6: Minimum Multiplications to reach End

// TC: O(100000 * N)
int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // edge case
    if (start == end)
        return 0;

    queue<pair<int, int>> q;
    q.push({start, 0});

    vector<int> dist(100000, INT_MAX);
    dist[start] = 0;

    int mod = 100000;

    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr)
        {
            int num = (it * node) % mod;

            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;

                if (num == end)
                    return steps + 1;

                q.push({num, steps + 1});
            }
        }
    }

    return -1;
}

int main()
{

    return 0;
}