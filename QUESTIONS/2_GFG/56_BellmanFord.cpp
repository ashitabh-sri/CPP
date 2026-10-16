// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dis(V, 1e8);
        dis[src] = 0;

        for (int i = 0; i < V - 1; i++) // max V - 1 edges -> iterations needed
        {
            for (vector<int> &i : edges)
            {
                int u = i[0];
                int v = i[1];
                int wt = i[2];

                if (dis[u] != 1e8 && dis[u] + wt < dis[v]) // new min path
                {
                    dis[v] = dis[u] + wt; // update min distance from src
                }
            }
        }

        for (vector<int> &i : edges) // one extra iteration
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            if (dis[u] != 1e8 && dis[u] + wt < dis[v]) // if found new min path
            {
                return {-1}; // negative weight cycle is present
            }
        }

        return dis;
    }
};

// Bellman Ford Algorithm
// TC = O(V E), V = vertices in graph, E = edges in graph
// SC = O(V)