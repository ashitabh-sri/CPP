// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/

class Solution
{
    vector<bool> vis;
    void dfs(int u, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[u] = true;

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                dfs(v, adj, st);
            }
        }

        st.push(u);
    }
    void dfs2(int u, vector<vector<int>> &transpose)
    {
        vis[u] = true;

        for (int v : transpose[u])
        {
            if (!vis[v])
            {
                dfs2(v, transpose);
            }
        }
    }

public:
    int countSCC(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<vector<int>> transpose(V); // graph with reversed edges

        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);       // directed graph
            transpose[v].push_back(u); // reversed edge
        }

        vis.assign(V, false); // track visited vertices
        stack<int> st;        // track order of vertices

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, st); // DFS for filing stack
            }
        }

        fill(vis.begin(), vis.end(), false);
        int scc = 0;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            if (!vis[u])
            {
                dfs2(u, transpose); // visits one SCC at a time
                scc++;              // one SCC traversal completed
            }
        }

        return scc;
    }
};

// Kosaraju's Algorithm
// TC = O(V + E)
// SC = O(V + E), V = vertices in graph, E = edges in graph