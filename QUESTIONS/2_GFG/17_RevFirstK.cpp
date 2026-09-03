class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        // code here
        int n = q.size();
        if (k > n)
        {
            return q;
        }

        stack<int> s;

        for (int i = 0; i < k; i++) // first k elements in stack
        {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty()) // take from stack into q to reverse order
        {
            q.push(s.top());
            s.pop();
        }

        for (int i = 0; i < n - k; i++) // shift the unchanged elements from front to back
        {
            q.push(q.front()); // add the front element to back
            q.pop();           // remove the front element
        }

        return q;
    }
};

// TC = O(n)
// SC = O(k)

// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1