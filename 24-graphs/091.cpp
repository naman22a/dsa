#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Q1:
// Leetcode 542: 01 Matrix

// TC: O(M.N)
// SC: O(M.N)
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int ROWS = mat.size();
    int COLS = mat[0].size();
    queue<pair<pair<int, int>, int>> q;

    vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
    vector<vector<int>> distances(ROWS, vector<int>(COLS, 0));

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (mat[r][c] == 0)
            {
                q.push({{r, c}, 0});
                visited[r][c] = 1;
            }
            else
            {
                visited[r][c] = 0;
            }
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        distances[row][col] = steps;

        for (int i = 0; i < 4; i++)
        {
            int nei_row = row + dr[i];
            int nei_col = col + dc[i];

            // check if position is valid
            // not already visited
            if (nei_row >= 0 && nei_row < ROWS && nei_col >= 0 && nei_col < COLS && visited[nei_row][nei_col] == 0)
            {
                visited[nei_row][nei_col] = 1;
                q.push({{nei_row, nei_col}, steps + 1});
            }
        }
    }

    return distances;
}

// Q2:
// Leetcode 130: Surrounded Regions

void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int ROWS, int COLS, int r, int c)
{
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || visited[r][c] || board[r][c] == 'X')
        return;

    visited[r][c] = 1;

    dfs(board, visited, ROWS, COLS, r + 1, c);
    dfs(board, visited, ROWS, COLS, r - 1, c);
    dfs(board, visited, ROWS, COLS, r, c + 1);
    dfs(board, visited, ROWS, COLS, r, c - 1);
}

// TC: O(M.N)
// SC: O(M.N)
void solve(vector<vector<char>> &board)
{
    int ROWS = board.size();
    int COLS = board[0].size();

    vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));

    // traverse first row and last row
    for (int c = 0; c < COLS; c++)
    {
        // first row
        if (!visited[0][c] && board[0][c] == 'O')
            dfs(board, visited, ROWS, COLS, 0, c);

        // last row
        if (!visited[ROWS - 1][c] && board[ROWS - 1][c] == 'O')
            dfs(board, visited, ROWS, COLS, ROWS - 1, c);
    }

    // traverse first col and last col
    for (int r = 0; r < ROWS; r++)
    {
        // first col
        if (!visited[r][0] && board[r][0] == 'O')
            dfs(board, visited, ROWS, COLS, r, 0);

        // last col
        if (!visited[r][COLS - 1] && board[r][COLS - 1] == 'O')
            dfs(board, visited, ROWS, COLS, r, COLS - 1);
    }

    // mark unvisited O as X
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (!visited[r][c] && board[r][c] == 'O')
                board[r][c] = 'X';
        }
    }
}

// Q3:
// Leetcode 1020: Number of Enclaves

// TC: O(M.N)
// SC: O(M.N)
// can solve this with DFS or BFS (Multi Source)
int numEnclaves(vector<vector<int>> &grid)
{
    int ROWS = grid.size();
    int COLS = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));

    // boundary traversal
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            // first row, first col, last row, last col
            if (r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1)
            {
                if (grid[r][c] == 1)
                {
                    q.push({r, c});
                    visited[r][c] = 1;
                }
            }
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nei_row = row + dr[i];
            int nei_col = col + dc[i];

            if (nei_row >= 0 && nei_row < ROWS && nei_col >= 0 && nei_col < COLS && visited[nei_row][nei_col] == 0 && grid[nei_row][nei_col] == 1)
            {
                q.push({nei_row, nei_col});
                visited[nei_row][nei_col] = 1;
            }
        }
    }

    int count = 0;
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (!visited[r][c] && grid[r][c] == 1)
                count++;
        }
    }

    return count;
}

// Q4:
// Leetcode 694: Number of Distinct Islands

void dfs_(vector<vector<int>> &grid, vector<vector<int>> &visited, int ROWS, int COLS, int r, int c, vector<pair<int, int>> &shape, int r0, int c0)
{
    visited[r][c] = 1;
    shape.push_back({r - r0, c - c0});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nei_row = r + dr[i];
        int nei_col = c + dc[i];

        if (nei_row >= 0 && nei_row < ROWS && nei_col >= 0 && nei_col < COLS && !visited[nei_row][nei_col] && grid[nei_row][nei_col] == 1)
        {
            dfs_(grid, visited, ROWS, COLS, nei_row, nei_col, shape, r0, c0);
        }
    }
}

// TC: O(M.N)
// SC: O(M.N.log(M.N) + M.N.4)
int numDistinctIslands(vector<vector<int>> &grid)
{
    int ROWS = grid.size();
    int COLS = grid[0].size();

    vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
    set<vector<pair<int, int>>> unique; // unique islands

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (!visited[r][c] && grid[r][c] == 1)
            {
                vector<pair<int, int>> shape;
                dfs_(grid, visited, ROWS, COLS, r, c, shape, r, c);
                unique.insert(shape);
            }
        }
    }

    return unique.size();
}

int main()
{

    return 0;
}