// https://www.hackerrank.com/challenges/bfsshortreach/problem

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s)
{
    vector<vector<int>> adj(n + 1);

    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int nei : adj[node])
        {
            if (dist[nei] == -1)
            {
                dist[nei] = dist[node] + 6;
                q.push(nei);
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (i != s)
            ans.push_back(dist[i]);
    }

    return ans;
}