class SpecialStack
{
    stack<int> st;
    int mn;

public:
    SpecialStack()
    {
        // Define Stack
        mn = INT_MAX;
    }

    void push(int x)
    {
        // Add an element to the top of Stack
        if (st.empty())
        {
            st.push(x);
            mn = x;
        }
        else if (x >= mn)
        {
            st.push(x);
        }
        else
        {
            st.push(2 * x - mn); // Encode previous minimum
            mn = x;              // update new minimum
        }
    }

    void pop()
    {
        // Remove the top element from the Stack
        if (st.empty())
        {
            return;
        }

        int x = st.top();
        st.pop();

        if (x < mn)
        {
            mn = (2 * mn - x); // Decode previous minimum
        }
    }

    int peek()
    {
        // Returns top element of the Stack
        if (st.empty())
        {
            return -1;
        }

        int top = st.top();

        if (top < mn)
        {
            return mn;
        }

        return top;
    }

    bool isEmpty()
    {
        // Check if stack is empty
        return st.empty();
    }

    int getMin()
    {
        // Finds minimum element of Stack
        if (st.empty())
        {
            return -1;
        }

        return mn;
    }
};

// TC = O(1)
// SC = O(1)