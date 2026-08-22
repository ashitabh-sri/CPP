class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        // filter out candidates
        while (st.size() != 1)
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (mat[a][b] == 1) // if a knows b, a can't be celebrity
            {
                st.push(b);
            }
            else // vice-versa
            {
                st.push(a);
            }
        }
        int ans = st.top();

        // O(1) space solution - Two Pointers
        // int a = 0;
        // int b = n - 1;

        // // Find potential celebrity
        // while(a < b) {
        //     if(mat[a][b] == 1) {
        //         // a knows b -> a cannot be celebrity
        //         a++;
        //     }
        //     else {
        //         // a doesn't know b -> b cannot be celebrity
        //         b--;
        //     }
        // }
        // int ans = a;

        // one potential celebrity remains in stack to verify
        int zer = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[ans][i] == 0)
            {
                zer++;
            }
            if (mat[i][ans] == 1)
            {
                one++;
            }
        }

        if (zer == n - 1 && one == n)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1