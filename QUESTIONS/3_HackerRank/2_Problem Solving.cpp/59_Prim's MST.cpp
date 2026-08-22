// https://www.hackerrank.com/challenges/primsmstsub/problem

int prims(int n, vector<vector<int>> edges, int start)
{
    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(n + 1, false);

    pq.push({0, start});
    int cost = 0;

    while (!pq.empty())
    {
        auto [wt, node] = pq.top();
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = true;
        cost += wt;

        for (auto &[nei, w] : adj[node])
        {
            if (!vis[nei])
            {
                pq.push({w, nei});
            }
        }
    }

    return cost;
}