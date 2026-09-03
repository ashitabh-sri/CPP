class Solution
{
public:
    void rearrangeQueue(queue<int> &q)
    {
        // code here
        int n = q.size();

        queue<int> tem;
        for (int i = 0; i < n / 2; i++)
        {
            tem.push(q.front());
            q.pop();
        }

        for (int i = 0; i < n / 2; i++)
        {
            q.push(tem.front());
            tem.pop();

            q.push(q.front());
            q.pop();
        }
    }
};

// TC = O(n/2) = O(n)
// SC = O(n/2) = O(n)

// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1