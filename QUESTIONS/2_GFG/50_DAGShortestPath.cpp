// https://www.geeksforgeeks.org/problems/shortest-path-in-directed-acyclic-graph/1

class Solution
{
    void topoSort(int i, vector<bool> &vis, vector<vector<pair<int, int>>> &adj, stack<int> &st)
    {
        vis[i] = true;

        for (pair<int, int> &nebr : adj[i])
        {
            if (!vis[nebr.first])
            {
                topoSort(nebr.first, vis, adj, st);
            }
        }

        st.push(i);
    }

public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V); // adjacency list for each vertex
        for (vector<int> &i : edges)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2]; // weight of edge

            adj[u].push_back({v, wt});
        }

        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                topoSort(i, vis, adj, st); // Topological Sort
            }
        }

        vector<int> dis(V, INT_MAX);
        dis[0] = 0;
        while (!st.empty())
        {
            int i = st.top();
            st.pop();

            if (dis[i] != INT_MAX) // for reachable vertices
            {
                for (pair<int, int> nebr : adj[i])
                {
                    int u = nebr.first;                // nebr vertex
                    int wt = nebr.second;              // nebr distance from i
                    dis[u] = min(dis[u], dis[i] + wt); // update min distance from 0
                }
            }
        }
        for (int &i : dis)
        {
            if (i == INT_MAX) // update unreachable vertex's distance
            {
                i = -1;
            }
        }

        return dis;
    }
};

// Topological Sort + Min Distance
// TC = O(V + E), V = vertices in graph, E = edges in graph
// SC = O(V), exclduing adjacency list of O(V + E)