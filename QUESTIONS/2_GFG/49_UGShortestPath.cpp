// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution
{
public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
    {
        if (src == dest)
        {
            return 0;
        }

        vector<vector<int>> adj(V);
        for (vector<int> &i : edges)
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u); // for undirected graph
        }

        vector<int> dis(V, -1);
        queue<int> q;
        q.push(src);
        dis[src] = 0;

        while (!q.empty())
        {
            int frnt = q.front();
            q.pop();

            for (int nebr : adj[frnt])
            {
                if (dis[nebr] == -1)
                {
                    dis[nebr] = dis[frnt] + 1;
                    q.push(nebr);

                    if (nebr == dest)
                    {
                        return dis[nebr];
                    }
                }
            }
        }

        return -1;
    }
};

// BFS
// TC = O(V + E), V = vertices in graph, E = edges in graph
// SC = O(V), excluding adjacency list of O(V + E)