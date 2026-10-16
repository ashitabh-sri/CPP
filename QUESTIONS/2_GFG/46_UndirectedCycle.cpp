// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution
{
    unordered_map<int, list<int>> adj; // adjacecny list

    bool isCycleDFS(int i, int parent, vector<bool> &vis)
    {
        vis[i] = true;

        for (int nebr : adj[i])
        {
            if (!vis[nebr])
            {
                bool chk = isCycleDFS(nebr, i, vis);

                if (chk)
                {
                    return true;
                }
            }
            else if (nebr != parent)
            {
                return true;
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        int n = edges.size();

        for (int i = 0; i < n; i++) // make the adjacency list
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u); // for undirected graph
        }

        vector<bool> vis(V, false); // track the visited nodes

        for (int i = 0; i < V; i++)
        {                // iterate all vertices
            if (!vis[i]) // if unvisited vertex
            {
                if (isCycleDFS(i, -1, vis)) // check for cycle
                {
                    return true;
                }
            }
        }

        return false;
    }
};

// Graph - DFS (or use BFS)
// TC = O(V + E), V = Vertex, E = Edges
// SC = O(V + E)