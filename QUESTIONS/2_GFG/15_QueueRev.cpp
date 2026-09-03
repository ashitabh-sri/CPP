class Solution
{
public:
    void reverseQueue(queue<int> &q)
    {
        // Recursive Solution
        // if(q.empty())
        // {
        //     return;
        // }

        // int f = q.front();
        // q.pop();

        // reverseQueue(q);

        // q.push(f);

        // Iterative Solution
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
    }
};

// TC = O(n) - Same in both Solutions
// SC = O(n) - Recursive Call Stack, DS Stack

// https://www.geeksforgeeks.org/problems/queue-reversal/1