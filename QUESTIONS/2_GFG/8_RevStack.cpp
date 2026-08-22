class Solution
{
    // void InsBot(stack<int> &st, int x){
    // if(st.empty()){
    //     st.push(x);
    //     return;
    // }
    // int tem = st.top();
    // st.pop();
    // InsBot(st, x);
    // st.push(tem);
    // }
public:
    void reverseStack(stack<int> &st)
    {
        // code here
        vector<int> vec;

        while (!st.empty())
        {
            vec.push_back(st.top());
            st.pop();
        }

        for (int v : vec)
        {
            st.push(v);
        }

        // if(st.empty()){
        //     return;
        // }
        // int tem = st.top();
        // st.pop();
        // reverseStack(st);
        // InsBot(st, tem);
    }
};

// https://www.geeksforgeeks.org/problems/reverse-a-stack/1