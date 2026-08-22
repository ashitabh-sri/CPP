// https://www.hackerrank.com/challenges/dijkstrashortreach/problem

vector<int> shortestReach(int n, vector<vector<int>> edges, int s)
{
    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto &[nei, wt] : adj[node])
        {
            if (dist[nei] > dist[node] + wt)
            {
                dist[nei] = dist[node] + wt;
                pq.push({dist[nei], nei});
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        ans.push_back(dist[i] == INT_MAX ? -1 : dist[i]);
    }

    return ans;
}