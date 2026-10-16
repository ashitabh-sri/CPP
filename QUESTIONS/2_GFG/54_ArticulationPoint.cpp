// https://www.geeksforgeeks.org/problems/articulation-point2616/1

class Solution
{
    int timer = 0;
    vector<int> dis, low;
    void dfs(int u, int parent, vector<vector<int>> &adj, vector<bool> &ap)
    {
        dis[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u])
        {
            if (v == parent)
            {
                continue;
            }

            if (dis[v] == -1)
            {
                children++;

                dfs(v, u, adj, ap);

                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= dis[u])
                {
                    ap[u] = true;
                }
            }
            else
            {
                low[u] = min(low[u], dis[v]);
            }
        }

        if (parent == -1 && children > 1) // special case for root
        {
            ap[u] = true;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (vector<int> &i : edges)
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dis.assign(V, -1);
        low.assign(V, -1);
        vector<bool> ap(V, false);

        for (int i = 0; i < V; i++)
        {
            if (dis[i] == -1)
            {
                dfs(i, -1, adj, ap);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (ap[i]) // true if articulation point
            {
                ans.push_back(i); // add this vertex
            }
        }

        if (ans.empty())
        {
            return {-1};
        }

        return ans;
    }
};

// Tarjan's Algorithm
// TC = O(V + E)
// SC = O(V + E), V = vertices in graph, E = edges in graph