#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Q1:
// Leetcode 547: Number of Provinces

void dfs(unordered_map<int, vector<int>> &adj, unordered_set<int> &visited, int node)
{
    visited.insert(node);

    for (auto nei : adj[node])
    {
        // not visited
        if (visited.count(nei) == 0)
            dfs(adj, visited, nei);
    }
}

// TC: O(E + V)
// SC: O(V)
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();

    // convert adj matrix to adj list
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] && i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // run traversal(dfs or bfs) on each component and count them

    int components = 0;
    unordered_set<int> visited;

    // for zero based index
    for (int i = 0; i <= n - 1; i++)
    {
        // not visited
        if (visited.count(i) == 0)
        {
            components++;
            dfs(adj, visited, i);
        }
    }

    return components;
}

// Q2: Number of Islands
// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/0

void bfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int ROWS, int COLS, int r, int c)
{
    visited[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse the neighbours and mark visited if it is a land
        for (int delta_row = -1; delta_row <= 1; delta_row++)
        {
            for (int detla_col = -1; detla_col <= 1; detla_col++)
            {
                int nei_row = row + delta_row;
                int nei_col = col + detla_col;

                // nei_row and nei_col are valid indices
                // is land
                // not already visited
                if (nei_row >= 0 && nei_row < ROWS && nei_col >= 0 && nei_col < COLS && grid[nei_row][nei_col] == '1' && !visited[nei_row][nei_col])
                {
                    visited[nei_row][nei_col] = 1;
                    q.push({nei_row, nei_col});
                }
            }
        }
    }
}

// TC: O(M.N.9)
// SC: O(M.N), visited matrix and queue
int numIslands(vector<vector<char>> &grid)
{
    int ROWS = grid.size();
    int COLS = grid[0].size();

    vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
    int count = 0;

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (!visited[r][c] && grid[r][c] == '1')
            {
                bfs(grid, visited, ROWS, COLS, r, c); // or dfs
                count++;
            }
        }
    }

    return count;
}

// Similar Question to Above
// Leetcode 200: Number of Islands
// Horizontally and Vertically only

void dfs_numIslands(vector<vector<char>> &grid, vector<vector<int>> &visited, int ROWS, int COLS, int r, int c)
{
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0' || visited[r][c] == 1)
        return;

    visited[r][c] = 1;

    // run dfs on neighbours
    dfs_numIslands(grid, visited, ROWS, COLS, r + 1, c);
    dfs_numIslands(grid, visited, ROWS, COLS, r - 1, c);
    dfs_numIslands(grid, visited, ROWS, COLS, r, c + 1);
    dfs_numIslands(grid, visited, ROWS, COLS, r, c - 1);
}

// TC: O(M.N.4)
// SC: O(M.N), visited matrix and recursion
int numIslands(vector<vector<char>> &grid)
{
    int ROWS = grid.size();
    int COLS = grid[0].size();

    vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
    int count = 0;

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (!visited[r][c] && grid[r][c] == '1')
            {
                dfs_numIslands(grid, visited, ROWS, COLS, r, c);
                count++;
            }
        }
    }

    return count;
}

// Q3:
// Leetcode 733: Flood Fill
void dfs_floodFill(vector<vector<int>> &image, vector<vector<int>> &ans, int row, int col, int initial, int newColor)
{
    int ROWS = image.size();
    int COLS = image[0].size();

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || image[row][col] != initial || ans[row][col] == newColor)
        return;

    ans[row][col] = newColor;

    dfs_floodFill(image, ans, row + 1, col, initial, newColor);
    dfs_floodFill(image, ans, row - 1, col, initial, newColor);
    dfs_floodFill(image, ans, row, col + 1, initial, newColor);
    dfs_floodFill(image, ans, row, col - 1, initial, newColor);
}

// TC: O(M.N)
// SC: O(M.N)
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initial = image[sr][sc];
    vector<vector<int>> ans = image;

    dfs_floodFill(image, ans, sr, sc, initial, color);
    return ans;
}

// Q4: Rotten Oranges
// Leetcode 994: Rotting Oranges

// TC: O(M.N)
// SC: O(M.N)

// using a Multi Source BFS

int orangesRotting(vector<vector<int>> &grid)
{
    int ROWS = grid.size(), COLS = grid[0].size();
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int time = 0;
    int fresh = 0;

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            // count the number of fresh oranges
            if (grid[r][c] == 1)
                fresh++;

            // add rotten oranges to the queue
            if (grid[r][c] == 2)
                q.push({r, c});
        }
    }

    while (!q.empty() && fresh > 0)
    {
        // to avoid the loop from changing it's iteration count, we store queue length in a variable as it is mutated in the loop body
        int length = q.size();
        for (int i = 0; i < length; i++)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto dir : directions)
            {
                int dr = dir.first;
                int dc = dir.second;

                int row = dr + r;
                int col = dc + c;

                // if out of bounds and not fresh orange
                if (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] != 1)
                    continue;

                // make fresh orange rotten
                grid[row][col] = 2;
                q.push({row, col});

                // decrease the number of fresh oranges
                fresh--;
            }
        }

        // increment time after one level or layer
        time++;
    }

    return (fresh == 0) ? time : -1;
}
int main()
{

    return 0;
}