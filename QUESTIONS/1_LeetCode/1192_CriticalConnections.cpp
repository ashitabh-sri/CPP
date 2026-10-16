class Solution
{
    vector<int> dis; // discovery time
    vector<int> low; // lowest discovery time reachable
    int timer = 0;   // track the time
    void dfs(int u, int parent, vector<vector<int>> &adj, vector<vector<int>> &ans)
    {
        dis[u] = low[u] = timer++; // initial assign & increase timer

        for (int v : adj[u])
        {
            if (v == parent) // path we came from
            {
                continue; // skip
            }

            if (dis[v] == -1)
            {
                dfs(v, u, adj, ans);

                low[u] = min(low[u], low[v]); // subtree vertices may found the back edge & lower time

                if (low[v] > dis[u]) // no alternate path -> bridge
                {
                    ans.push_back({u, v});
                }
            }
            else
            {                                 // visited vertex in forward path
                low[u] = min(low[u], dis[v]); // Back Edge found, update low[u]
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (vector<int> &i : connections)
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u); // undirected edge
        }

        dis.assign(n, -1);
        low.assign(n, -1);
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (dis[i] == -1)
            {
                dfs(i, -1, adj, ans);
            }
        }

        return ans;
    }
};

// Tarjan's Algorithm
// TC = O(V + E), V = vertices in graph, E = edges in graph
// SC = O(V + E), including adjacency list