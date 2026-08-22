class Solution
{
public:
    bool checkRedundancy(string &s)
    {
        // code here
        stack<char> st;

        for (char c : s)
        {
            if (c == '(')
            {
                st.push(c);
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                if (st.top() == '(')
                {
                    return true;
                }
                else
                {
                    while (st.top() != '(')
                    {
                        st.pop();
                    }
                    st.pop();
                }
            }
        }

        return false;
    }
};

// https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1