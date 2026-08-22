// https://www.hackerrank.com/challenges/largest-rectangle/problem

long largestRectangle(vector<int> h)
{
    stack<int> st;
    long ans = 0;
    int n = h.size();

    for (int i = 0; i <= n; i++)
    {

        while (!st.empty() && (i == n || h[st.top()] > h[i]))
        {

            long height = h[st.top()];
            st.pop();

            long width;

            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            ans = max(ans, height * width);
        }

        st.push(i);
    }

    return ans;
}