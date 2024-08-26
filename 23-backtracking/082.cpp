#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// Q1: Rat in a Maze Problem
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

void backtrack(vector<string> &result, vector<vector<int>> m, int n, set<pair<int, int>> &visited, string path, int r, int c)
{
    int ROWS = m.size();
    int COLS = m[0].size();

    // - check if out of bounds
    // - already visited
    // - is a zero
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || visited.find({r, c}) != visited.end() || m[r][c] == 0)
        return;

    // check if reached the dest(end)
    if (r == n - 1 && c == n - 1)
    {
        result.push_back(path);
        return;
    }

    // mark visited
    visited.insert({r, c});

    // recursive calls in lexiographical(sorted) order
    // D L R U

    path.push_back('D');
    backtrack(result, m, n, visited, path, r + 1, c);
    path.pop_back();

    path.push_back('L');
    backtrack(result, m, n, visited, path, r, c - 1);
    path.pop_back();

    path.push_back('R');
    backtrack(result, m, n, visited, path, r, c + 1);
    path.pop_back();

    path.push_back('U');
    backtrack(result, m, n, visited, path, r - 1, c);
    path.pop_back();

    // unmark visited
    visited.erase({r, c});
}

// TC: O(4^(n^2))
// SC: O(n^2)
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> result;
    string path = "";
    pair<int, int> src = {0, 0};
    set<pair<int, int>> visited;

    backtrack(result, m, n, visited, path, src.first, src.second);

    return result;
}

int main()
{

    return 0;
}