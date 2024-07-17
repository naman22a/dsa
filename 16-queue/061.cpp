#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
using namespace std;

// Q1: Queue Reversal
// TC: O(N)
// SC: O(N)
queue<int> rev(queue<int> q)
{
    stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    return q;
}

void rev_backtrack(queue<int> &q)
{
    // base case
    if (q.size() == 1 || q.size() == 0)
        return;

    // processing 1: store number and remove it from queue
    int num = q.front();
    q.pop();

    // recurrence
    rev_backtrack(q);

    // processing 2: insert the number at end of reversed queue
    q.push(num);
}

// TC: O(N)
// SC: O(N)
queue<int> rev_using_backtracking(queue<int> q)
{
    rev_backtrack(q);
    return q;
}

// Q2: First negative in every window of size k
// TC: O(N)
// SC: O(K)
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long int> result;

    // process 1st window of size k
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            dq.push_back(i);
    }

    // store answer of first k size window
    if (dq.size() > 0)
        result.push_back(A[dq.front()]);
    else
        result.push_back(0);

    // process for remaining windows
    for (int i = K; i < N; i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        // addtion
        if (A[i] < 0)
            dq.push_back(i);

        // store answer
        if (dq.size() > 0)
            result.push_back(A[dq.front()]);
        else
            result.push_back(0);
    }

    return result;
}

// Q3: Reverse First K elements of Queue
// TC: O(N)
// SC: O(K)
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    int n = q.size();

    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n - k; i++)
    {
        int num = q.front();
        q.pop();
        q.push(num);
    }

    return q;
}

// Q4: First non-repeating character in a stream
/*
Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every i you need to consider the string from starting position till ith position.
*/
// TC: O(N), O(26.N)
// SC: O(1), O(26)
string FirstNonRepeating(string A)
{
    unordered_map<char, int> freq;
    queue<char> q;
    string ans;

    for (auto ch : A)
    {
        freq[ch]++;
        q.push(ch);

        while (!q.empty())
        {
            // repeating
            if (freq[q.front()] > 1)
                q.pop();
            // non repeating
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        // no non repeating element found
        if (q.empty())
            ans.push_back('#');
    }

    return ans;
}

// Q5: Circular tour
/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance
*/
struct petrolPump
{
    int petrol;
    int distance;
};

// TC: O(N)
// SC: O(1)
int tour(petrolPump p[], int n)
{
    int deficit = 0;
    int balance = 0;
    int front = 0;

    for (int rear = 0; rear < n; rear++)
    {
        balance += p[rear].petrol - p[rear].distance;

        if (balance < 0)
        {
            deficit += balance;
            front = rear + 1;
            balance = 0; // starting from new index
        }
    }

    if (balance + deficit >= 0)
        return front;

    return -1;
}

// Q6: Interleave the first half of the queue with second half
// TC: O(N)
// SC: O(N)
vector<int> rearrangeQueue(queue<int> &q)
{
    int n = q.size();
    int half = n / 2;

    queue<int> r;

    for (int i = 0; i < half; i++)
    {
        r.push(q.front());
        q.pop();
    }

    while (!r.empty())
    {
        int a = r.front();
        q.push(a);
        r.pop();

        int b = q.front();
        q.push(b);
        q.pop();
    }

    // edge case for odd
    if (q.size() % 2 != 0)
    {
        q.push(q.front());
        q.pop();
    }

    vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front());
        q.pop();
    }

    return result;
}

// Q7: K Queues in an Array

// SC: O(N)
class KQueues_in_an_Array
{
public:
    int k;
    int n;
    int *arr;

    int *front;
    int *rear;
    int *next;
    int freespot;

    KQueues_in_an_Array(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];

        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
            front[i] = -1, rear[i] = -1;

        next = new int[n];
        for (int i = 0; i < n; i++)
            next[i] = i + 1;
        next[n - 1] = -1;

        freespot = 0;
    }

    // TC: O(1)
    // qn is the queue number (q1, q2, ... etc)
    void enqueue(int data, int qn)
    {
        // queue overflow
        if (freespot == -1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        // find first free index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // check whether first element
        // qn - 1 used because arrays made in the constructor follow zero based indexing
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // link new element to the previous element
            next[rear[qn - 1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear (move rear ahead)
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    // TC: O(1)
    int dequeue(int qn)
    {
        // queue underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // find index to pop
        int index = front[qn - 1];

        // move front ahead
        front[qn - 1] = next[index];

        // link next freespot
        next[index] = freespot;

        // manage space for newly deleted spot
        freespot = index;

        return arr[index];
    }
};

// Q8: Sum of minimum and maximum elements of all subarrays of size k.
// TC: O(N)
// SC: O(N)
int sum(int arr[], int n, int k)
{
    // Monotonic Queue
    deque<int> maxi(k); // decreasing
    deque<int> mini(k); // increasing

    // addition of first k size window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = arr[maxi.front()] + arr[mini.front()];

    // process all remaining windows
    for (int i = k; i < n; i++)
    {

        // move to next window
        // 1. removal
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();

        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        // 2. addition
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main()
{
    {
        KQueues_in_an_Array q(10, 3);
        q.enqueue(10, 1);
        q.enqueue(15, 1);
        q.enqueue(20, 2);
        q.enqueue(25, 1);

        cout << q.dequeue(1) << endl;
        cout << q.dequeue(2) << endl;
        cout << q.dequeue(1) << endl;
        cout << q.dequeue(1) << endl;

        cout << q.dequeue(1) << endl;
    }

    {
        int arr[] = {2, 5, -1, 7, -3, -1, -2};
        int n = 7;
        int k = 4;

        cout << sum(arr, n, k) << endl;
    }

    return 0;
}