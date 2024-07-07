#include <iostream>
#include <vector>
using namespace std;

// Q1:
// Leetcode 46: Permutations
void backtrack(vector<vector<int>> &result, vector<int> nums, int i)
{
    if (i >= nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int j = i; j < nums.size(); j++)
    {
        swap(nums[i], nums[j]);
        backtrack(result, nums, i + 1);

        // cleanup
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;

    backtrack(result, nums, 0);

    return result;
}

int main()
{

    return 0;
}