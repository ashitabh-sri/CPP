// https://www.hackerrank.com/challenges/poisonous-plants/problem

int poisonousPlants(vector<int> p)
{
    stack<pair<int, int>> st; // {pesticide, day to die}
    int ans = 0;

    for (int x : p)
    {
        int days = 0;

        while (!st.empty() && x <= st.top().first)
        {
            days = max(days, st.top().second);
            st.pop();
        }

        if (st.empty())
            days = 0;
        else
            days++;

        ans = max(ans, days);
        st.push({x, days});
    }

    return ans;
}