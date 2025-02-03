#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1: N meetings in one room

struct Data
{
    int start;
    int end;
    int pos;
};

bool cmp(Data a, Data b)
{
    return a.end < b.end;
}

// TC: O(N.log(N) + 2.N)
// SC: O(3.N + N)
int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();

    vector<Data> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    }

    sort(arr.begin(), arr.end(), cmp);

    int count = 1;
    int freeTime = arr[0].end;
    vector<int> ds;
    ds.push_back(arr[0].pos);

    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i].start > freeTime)
        {
            count++;
            freeTime = arr[i].end;
            ds.push_back(arr[i].pos);
        }
    }

    return count;
}

// Q2:
// Leetcode 55: Jump Game

// TC: O(N)
// SC: O(1)
bool canJump(vector<int> &nums)
{
    int maxIndex = 0;
    for (int i = 0; i <= nums.size() - 1; i++)
    {
        if (i > maxIndex)
            return false;
        maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
}

// Q3:
// Leetcode 45: Jump Game II

// TC: O(N)
// SC: O(1)
int jump(vector<int> &nums)
{
    int n = nums.size();

    int jumps = 0;
    int left = 0;
    int right = 0;

    while (right < n - 1)
    {
        int farthest = 0;

        for (int i = left; i <= right; i++)
            farthest = max(farthest, i + nums[i]);

        left = right + 1;
        right = farthest;
        jumps++;
    }

    return jumps;
}

// Q4: Minimum Platforms

// TC: O(N.log(N) + N.log(N) + 2.N)
// TC: O(2.(N.log(N) + N))
// SC: O(1)
int findPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0;
    int j = 0;

    int count = 0;
    int maxCount = 0;

    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

// Q5: Job Sequencing Problem

struct Job
{
    int id;
    int deadline;
    int profit;
};

// TC: O(N.log(N) + N + N.maxDeadLine)
// SC: O(maxDeadLine)
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit)
{
    int n = id.size();
    vector<Job> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i].id = id[i];
        arr[i].deadline = deadline[i];
        arr[i].profit = profit[i];
    }

    sort(arr.begin(), arr.end(), [](Job a, Job b) -> bool
         { return a.profit > b.profit; });

    int totalProfit = 0;
    int count = 0;

    int maxDeadLine = -1;

    for (int i = 0; i <= n - 1; i++)
        maxDeadLine = max(maxDeadLine, arr[i].deadline);

    vector<int> hash(maxDeadLine + 1, -1);

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = arr[i].deadline - 1; j >= 0; j--)
        {
            if (hash[j] == -1)
            {
                count++;
                hash[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    return {count, totalProfit};
}

// Q6:
// Leetcode 135: Candy

// TC: O(N)
// SC: O(1)
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    int sum = 1;
    int i = 1;

    while (i < n)
    {
        // if it is a flat surface
        if (ratings[i] == ratings[i - 1])
        {
            sum++;
            i++;
            continue;
        }

        // increasing slope
        int peak = 1;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            sum += peak;
            i++;
        }

        // decreasing slope
        int down = 0;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            down++;
            sum += down;
            i++;
        }
        down++;

        if (down > peak)
            sum += down - peak;
    }

    return sum;
}

// Q7: Shortest Job first
// TC: O(N + N.log(N))
// SC: O(1)
long long solve(vector<int> &bt)
{
    int n = bt.size();
    sort(bt.begin(), bt.end());

    int timer = 0, waitTime = 0;

    for (int i = 0; i <= n - 1; i++)
    {
        waitTime += timer;
        timer += bt[i];
    }

    return waitTime / n;
}

// Q8:
// Leetcode 57: Insert Interval
// TC: O(N)
// SC: O(1), did not include the space required for storing the result
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> result;

    int newStart = newInterval[0];
    int newEnd = newInterval[1];

    int n = intervals.size();
    for (int i = 0; i < n; i++)
    {
        // Case 1: Non overlapping interval
        // If new interval is before the current interval
        if (intervals[i][0] > newEnd)
        {
            result.push_back(newInterval);
            copy(intervals.begin() + i, intervals.end(), back_inserter(result));
            return result;
        }
        // If new interval is after the current interval
        else if (intervals[i][1] < newStart)
        {
            result.push_back(intervals[i]);
        }
        // Case 2: Overlapping interval
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }

    // insert the new interval
    result.push_back(newInterval);
    return result;
}

// Q9:
// Leetcode 56: Merge Intervals

// TC: O(N.log(N))
// SC: O(1)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // end value of the most recently added interval, does it overlap ?
        int lastEnd = result[result.size() - 1][1];

        // overlapping
        if (start <= lastEnd)
            result[result.size() - 1][1] = max(lastEnd, end);
        // non overlapping
        else
            result.push_back({start, end});
    }

    return result;
}

// Q10:
// Leetcode 435: Non-overlapping Intervals

// TC: O(N.log(N) + N)
// SC: O(1)
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    // greedy approach

    // sorting
    sort(intervals.begin(), intervals.end()); // sort by start value

    int count = 0;
    int previousEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> interval = intervals[i];
        int start = interval[0];
        int end = interval[1];

        // not overlapping
        if (start >= previousEnd)
        {
            previousEnd = end;
        }
        // overlapping, remove one of the intervals
        else
        {
            count++;
            // no need to actually delete interval in the array
            // just update the previous end value
            previousEnd = min(previousEnd, end);
        }
    }

    return count;
}

int main()
{

    return 0;
}