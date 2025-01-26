#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        // (n + 1) for 1 index based graph
        parent.resize(n + 1);
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

// Q1:
// Leetcode 1319: Number of Operations to Make Network Connected

// TC: O(E.V)
// SC: O(E.V)
int makeConnected(int n, vector<vector<int>> &connections)
{
    DisjointSet ds(n);
    int extras = 0;

    for (auto connection : connections)
    {
        int u = connection[0];
        int v = connection[1];

        // already connected
        if (ds.findUltimateParent(u) == ds.findUltimateParent(v))
            extras++;
        else
            ds.unionBySize(u, v);
    }

    int connectedComputers = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.parent[i] == i)
            connectedComputers++;
    }

    int cables = connectedComputers - 1;

    if (extras >= cables)
        return cables;
    return -1;
}

// Q2:
// Leetcode 947: Most Stones Removed with Same Row or Column

int removeStones(vector<vector<int>> &stones)
{
    // ans = n - no of connected components
    // a "row" is node(0 to ROWS - 1) in disjoint set in this question
    // a "col" is node(ROWS to ROWS + COLS - 1) in disjoint set in this question

    int n = stones.size();

    int maxRow = 0;
    int maxCol = 0;

    for (auto stone : stones)
    {
        maxRow = max(maxRow, stone[0]);
        maxCol = max(maxCol, stone[1]);
    }

    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes;

    for (auto stone : stones)
    {
        int nodeRow = stone[0];
        int nodeCol = stone[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int count = 0;

    for (auto it : stoneNodes)
    {
        if (ds.findUltimateParent(it.first) == it.first)
            count++;
    }

    return n - count;
}

// Q3:
// Leetcode 721: Accounts Merge
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    unordered_map<string, int> mapMailNode;
    DisjointSet ds(n);

    // connecting nodes
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];

            if (mapMailNode.find(mail) == mapMailNode.end())
                mapMailNode[mail] = i;
            else
                ds.unionBySize(i, mapMailNode[mail]);
        }
    }

    // mergeing mails
    vector<vector<string>> mergedMail(n);
    for (auto it : mapMailNode)
    {
        string mail = it.first;
        int node = ds.findUltimateParent(it.second);

        mergedMail[node].push_back(mail);
    }

    // formatting answer
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergedMail[i].empty())
            continue;

        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);

        for (auto it : mergedMail[i])
            temp.push_back(it);

        ans.push_back(temp);
    }

    return ans;
}

// Q4:
// Leetcode 305: Number of Islands II

vector<int> numIslands2(int m, int n, vector<vector<int>> positions)
{
    DisjointSet ds(n * m);
    // unordered_set<pair<int, int>> visited;
    vector<vector<int>> visited(n, vector<int>(m, 0));

    int count = 0;
    vector<int> ans;

    for (auto position : positions)
    {
        int row = position[0];
        int col = position[1];

        if (visited[row][col])
        {
            ans.push_back(count);
            continue;
        }

        visited[row][col] = 1;
        count++;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int adjRow = row + dr[i];
            int adjCol = col + dc[i];

            if (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m)
            {
                // is an island
                if (visited[adjRow][adjCol] == 1)
                {
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjRow * m + adjCol;
                    if (ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo))
                    {
                        count--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

// Q5:
// Leetcode 827: Making A Large Island

bool isValid(int n, int r, int c)
{
    return r >= 0 && c >= 0 && r < n && c < n;
}

// TC: O(N^2)
// SC: O(N^2)
int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet ds(n * n);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++)
            {
                int new_row = row + dr[i];
                int new_col = col + dc[i];

                if (isValid(n, new_row, new_col) && grid[new_row][new_col] == 1)
                {
                    int nodeNo = row * n + col;
                    int adjNodeNo = new_row * n + new_col;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }

    int maxi = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
                continue;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            unordered_set<int> components;

            for (int i = 0; i < 4; i++)
            {
                int new_row = row + dr[i];
                int new_col = col + dc[i];

                if (isValid(n, new_row, new_col))
                {
                    if (grid[new_row][new_col] == 1)
                        components.insert(ds.findUltimateParent(new_row * n + new_col));
                }
            }

            int size = 0;
            for (auto it : components)
                size += ds.size[it];

            maxi = max(maxi, size + 1);
        }
    }

    // edge case: all cells are 1
    for (int cellNo = 0; cellNo < n * n; cellNo++)
        maxi = max(maxi, ds.size[ds.findUltimateParent(cellNo)]);

    return maxi;
}

// Q6:
// Leetcode 778: Swim in Rising Water

// using Dijkstra's Algorithm (it is a Greedy Algorithm)
// TC: O(N^2 . log(N))
// SC: O(N^2)
int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();

    set<pair<int, int>> visited;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // min heap -> { time/max_height, row, col }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({grid[0][0], 0, 0});
    visited.insert({0, 0});

    while (!pq.empty())
    {
        int time = pq.top()[0];
        int r = pq.top()[1];
        int c = pq.top()[2];
        pq.pop();

        // reached the end(other corner)
        if (r == n - 1 && c == n - 1)
            return time;

        // BFS in all four directions
        for (auto dir : directions)
        {
            int dr = dir[0];
            int dc = dir[1];

            int neiRow = r + dr;
            int neiCol = c + dc;

            // check if out of bounds, then skip
            if (neiRow < 0 || neiCol < 0 || neiRow == n || neiCol == n || visited.find({neiRow, neiCol}) != visited.end())
                continue;

            visited.insert({neiRow, neiCol});
            pq.push({max(time, grid[neiRow][neiCol]), neiRow, neiCol});
        }
    }

    return -1;
}

int main()
{

    return 0;
}