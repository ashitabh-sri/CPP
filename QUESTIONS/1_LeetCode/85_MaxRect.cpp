class Solution
{
    vector<int> nextSmall(vector<int> arr, int n)
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
    vector<int> prevSmall(vector<int> arr, int n)
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

    int largestRectangleArea(vector<int> arr, int n)
    {

        vector<int> nxt = nextSmall(arr, n); // gets indices for next smaller element
        vector<int> pre = prevSmall(arr, n); // gets indices for previous smaller element

        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int len = arr[i];

            if (nxt[i] == -1)
            {
                nxt[i] = n; // for correct right boundary
            }

            int wid = nxt[i] - pre[i] - 1; // gives the width of max rectangle

            area = max(area, len * wid); // update for maximum rect area
        }

        return area;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int area = INT_MIN;

        int n = matrix.size();    // rows
        int m = matrix[0].size(); // cols

        vector<int> his(m, 0); // for efficient integer calculations for rect

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1') // if 1, then add with previous rectangle
                {
                    his[j]++;
                }
                else
                {
                    his[j] = 0; // else remove from rectangle
                }
            }

            int cura = largestRectangleArea(his, m); // update histogram area of each row
            area = max(area, cura);                  // maximum area of rectangle
        }

        return area;
    }
};

// TC = O(n*m)
// SC = O(m)