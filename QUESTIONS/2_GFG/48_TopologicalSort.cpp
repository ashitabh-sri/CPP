class Solution
{
    // void topoDFS(int i, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj){
    //     vis[i] = true;

    //     for(int nebr : adj[i]){
    //         if(!vis[nebr]){
    //             topoDFS(nebr, vis, st, adj);
    //         }
    //     }

    //     st.push(i); // pushing when no further link exists
    // }
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (vector<int> i : edges)
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v); // for directed graph
        }

        vector<int> ans(V, -1);

        // vector<bool> vis(V);
        // stack<int> st; // for vertex sorted order

        // for(int i = 0; i < V; i++){
        //     if(!vis[i]){
        //         topoDFS(i, vis, st, adj);
        //     }
        // }

        // int i = 0;
        // while(!st.empty()){
        //     ans[i++] = st.top();
        //     st.pop();
        // }

        vector<int> indegree(V, 0);
        for (vector<int> i : adj)
        {
            for (int j : i)
            {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int i = 0;
        while (!q.empty())
        {
            int frnt = q.front();
            q.pop();

            ans[i++] = frnt;

            for (int nebr : adj[frnt])
            {
                indegree[nebr]--;

                if (indegree[nebr] == 0)
                {
                    q.push(nebr);
                }
            }
        }

        return ans;
    }
};

// DFS + Stack OR Kahn's Algorithm
// TC = O(V + E), V = vertices in graph, E = edges in graph
// SC = O(V), excluding O(V + E) of adjacency list