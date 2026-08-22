class Solution
{
    void solve(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int tem = st.top();
        st.pop();

        solve(st, x);

        st.push(tem);
    }

public:
    stack<int> insertAtBottom(stack<int> &st, int x)
    {
        // code here
        solve(st, x);

        return st;
    }
};

// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1