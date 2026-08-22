class Solution
{
public:
    string reverse(const string &S)
    {
        // code here
        stack<char> st;
        string res = "";

        for (char s : S)
        {
            st.push(s);
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

// https://www.geeksforgeeks.org/problems/reverse-a-string-using-stack/1