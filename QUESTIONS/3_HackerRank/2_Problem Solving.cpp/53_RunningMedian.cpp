// https://www.hackerrank.com/challenges/find-the-running-median/problem

vector<double> runningMedian(vector<int> a)
{
    priority_queue<int> left;                             // Max Heap
    priority_queue<int, vector<int>, greater<int>> right; // Min Heap

    vector<double> ans;

    for (int x : a)
    {

        if (left.empty() || x <= left.top())
            left.push(x);
        else
            right.push(x);

        // Balance the heaps
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }

        // Calculate median
        if (left.size() == right.size())
            ans.push_back((left.top() + right.top()) / 2.0);
        else
            ans.push_back(left.top());
    }

    return ans;
}