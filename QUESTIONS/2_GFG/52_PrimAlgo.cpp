// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (vector<int> &i : edges)
        {
            int u = i[0];  // vertex
            int v = i[1];  // neighbour vertex
            int wt = i[2]; // weight of edge

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // undirected graph
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnh; // Min Heap
        vector<bool> vis(V, false);
        int sum = 0;

        mnh.push({0, 0}); // weight, vertex
        while (!mnh.empty())
        {
            auto [wt, v] = mnh.top(); // edge by minimum weight
            mnh.pop();

            if (vis[v]) // visited node
            {
                continue; // skip
            }

            vis[v] = true;
            sum += wt; // add the weight of edge

            for (auto [nebrV, nebrWT] : adj[v])
            {
                if (!vis[nebrV]) // if not visited
                {
                    mnh.push({nebrWT, nebrV}); // push the edge
                }
            }
        }

        return sum;
    }
};

// Prim's Algorithm
// TC = O(E logE), E = edges in graph
// SC = O(V + E), V = vertices in graphclass Solution {
public:
int spanningTree(int V, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(V);
    for (vector<int> &i : edges)
    {
        int u = i[0];  // vertex
        int v = i[1];  // neighbour vertex
        int wt = i[2]; // weight of edge

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // undirected graph
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnh; // Min Heap
    vector<bool> vis(V, false);
    int sum = 0;

    mnh.push({0, 0}); // weight, vertex
    while (!mnh.empty())
    {
        auto [wt, v] = mnh.top(); // edge by minimum weight
        mnh.pop();

        if (vis[v]) // visited node
        {
            continue; // skip
        }

        vis[v] = true;
        sum += wt; // add the weight of edge

        for (auto [nebrV, nebrWT] : adj[v])
        {
            if (!vis[nebrV]) // if not visited
            {
                mnh.push({nebrWT, nebrV}); // push the edge
            }
        }
    }

    return sum;
}
}
;

// Prim's Algorithm
// TC = O((V + E) logV) = O(E logV), V = vertices in graph, E = edges in graph
// SC = O(V + E)