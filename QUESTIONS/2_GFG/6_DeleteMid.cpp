class Solution
{
    void solve(stack<int> &s, int cnt, int mid)
    {
        // Base Case
        if (cnt == mid)
        {
            s.pop();
            return;
        }

        int tem = s.top();

        s.pop();
        solve(s, cnt + 1, mid);

        s.push(tem);
    }

public:
    void deleteMid(stack<int> &s)
    {
        // code here
        int n = s.size();
        int mid = n / 2 + 1;
        int cnt = 1;

        solve(s, cnt, mid);
    }
};

// https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1