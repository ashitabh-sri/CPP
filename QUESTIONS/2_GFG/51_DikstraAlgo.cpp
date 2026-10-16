// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(V); // adjacency list
        for (vector<int> &i : edges)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({wt, v}); // next node, weight of edge
            adj[v].push_back({wt, u}); // for undirected graph
        }

        vector<int> dis(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnh; // min heap

        dis[src] = 0;
        mnh.push({0, src});

        while (!mnh.empty())
        {
            int d = mnh.top().first;
            int u = mnh.top().second;
            mnh.pop();

            if (d > dis[u]) // old distance
            {
                continue; // skip to next
            }

            for (auto nebr : adj[u])
            {
                int wt = nebr.first;
                int v = nebr.second;

                if (d + wt < dis[v]) // new min distance
                {
                    dis[v] = d + wt; // update min distance
                    mnh.push({dis[v], v});
                }
            }
        }

        return dis;
    }
};

// Dijkstra's Algorithm
// TC = O((V + E) logV), V = vertices in graph, E = edges in graph
// SC = O(V), excluding adjacency list of O(V + E)