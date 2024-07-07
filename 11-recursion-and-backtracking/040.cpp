#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
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
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visited.find({r, c}) != visited.end() || m[r][c] == 0)
        return;

    // check if reached end
    if ((r == n - 1) && (c == n - 1))
    {
        result.push_back(path);
        return;
    }

    // mark visited
    visited.insert({r, c});

    path.push_back('U');
    backtrack(result, m, n, visited, path, r - 1, c);
    path.pop_back();

    path.push_back('D');
    backtrack(result, m, n, visited, path, r + 1, c);
    path.pop_back();

    path.push_back('R');
    backtrack(result, m, n, visited, path, r, c + 1);
    path.pop_back();

    path.push_back('L');
    backtrack(result, m, n, visited, path, r, c - 1);
    path.pop_back();

    // unmark visited
    visited.erase({r, c});
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> result;
    string path = "";
    pair<int, int> src = {0, 0};
    set<pair<int, int>> visited;

    backtrack(result, m, n, visited, path, src.first, src.second);
    sort(result.begin(), result.end());

    return result;
}

void print(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    print(findPath(m, n));

    return 0;
}