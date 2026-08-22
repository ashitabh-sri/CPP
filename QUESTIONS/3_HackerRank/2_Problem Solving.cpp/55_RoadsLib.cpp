// https://www.hackerrank.com/challenges/torque-and-development/problem

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

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{

    if (c_road >= c_lib)
        return 1LL * n * c_lib;

    vector<vector<int>> adj(n + 1);

    for (auto &e : cities)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> vis(n + 1, false);
    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            long long sz = dfs(i, adj, vis);
            ans += c_lib + (sz - 1) * 1LL * c_road;
        }
    }

    return ans;
}