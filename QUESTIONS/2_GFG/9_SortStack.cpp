class Solution
{
    void InsVal(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        if (x > st.top())
        {
            st.push(x);
            return;
        }

        int tem = st.top();
        st.pop();

        InsVal(st, x);

        st.push(tem);
    }

public:
    void sortStack(stack<int> &st)
    {
        // code here
        if (st.empty())
        {

            return;
        }

        int tem = st.top();
        st.pop();

        sortStack(st);

        InsVal(st, tem);
    }
};

// https://www.geeksforgeeks.org/problems/sort-a-stack/1