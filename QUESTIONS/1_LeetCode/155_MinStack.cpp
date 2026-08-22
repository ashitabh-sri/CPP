class MinStack
{
    stack<long long> st;
    long long mn;

public:
    MinStack()
    {
        mn = LLONG_MAX;
    }

    void push(int value)
    {
        if (st.empty())
        {
            st.push(value);
            mn = value;
        }
        else if (mn > value) // need to change min
        {
            long long enc = 2LL * value - mn; // encode old min and pushed value together
            st.push(enc);                     // push encoded value
            mn = value;                       // update to new min
        }
        else
        {
            st.push(value);
        }
    }

    void pop()
    {
        long long value = st.top();

        if (mn > value) // encoded value
        {
            long long dec = 2 * mn - value; // decode the value for old min
            mn = dec;                       // update to old min
        }

        st.pop();
    }

    int top()
    {
        if (st.top() < mn) // top is encoded value
        {
            return mn; // the top element is the current min
        }
        else
        {
            return st.top();
        }
    }

    int getMin()
    {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */