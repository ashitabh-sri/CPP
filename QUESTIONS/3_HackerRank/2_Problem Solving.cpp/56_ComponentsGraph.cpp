// https://www.hackerrank.com/challenges/components-in-graph/problem

int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    int cnt = 1;

    for (int nei : adj[node])
    {
        if (!vis[nei])
            cnt += dfs(nei, adj, vis);
    }

    return cnt;
}

vector<int> componentsInGraph(vector<vector<int>> gb)
{
    int maxNode = 0;

    for (auto &e : gb)
        maxNode = max(maxNode, max(e[0], e[1]));

    vector<vector<int>> adj(maxNode + 1);

    for (auto &e : gb)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> vis(maxNode + 1, false);

    int mn = INT_MAX;
    int mx = 0;

    for (int i = 1; i <= maxNode; i++)
    {
        if (!vis[i] && !adj[i].empty())
        {
            int sz = dfs(i, adj, vis);
            mn = min(mn, sz);
            mx = max(mx, sz);
        }
    }

    return {mn, mx};
}