class Solution
{
    vector<int> nextSmall(vector<int> &arr, int n)
    {
        vector<int> ans(n);

        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> prevSmall(vector<int> &arr, int n)
    {
        vector<int> ans(n);

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> nxt = nextSmall(heights, n); // gets indices for next smaller element
        vector<int> pre = prevSmall(heights, n); // gets indices for previous smaller element

        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int len = heights[i];

            if (nxt[i] == -1)
            {
                nxt[i] = n; // for correct right boundary
            }

            int wid = nxt[i] - pre[i] - 1; // gives the width of max rectangle

            area = max(area, len * wid); // update for maximum rect area
        }

        return area;
    }
};

// TC = O(n)
// SC = O(n)