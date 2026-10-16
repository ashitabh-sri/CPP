// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution
{
    // bool CycleDFS(int i, vector<bool> &vis, vector<bool> &path, vector<vector<int>> &adj){
    //     vis[i] = true;
    //     path[i] = true;

    //     for(auto nebr : adj[i]){ // neighbours of current vertex
    //         if(!vis[nebr]){ // if not visited vertex
    //             bool chk = CycleDFS(nebr, vis, path, adj);

    //             if(chk){
    //                 return true;
    //             }
    //         }
    //         else if(path[nebr]){ // if visited vertex & visited path
    //             return true;
    //         }
    //     }

    //     path[i] = false; // backtracking in recursive stack

    //     return false;
    // }
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V); // adjacency list
        for (vector<int> &i : edges)
        { // making adjacency list
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v); // for directed graph
        }

        // vector<bool> vis(V, false); // track visited vertices
        // vector<bool> path(V, false); // track visited path

        // for(int i = 0; i < V; i++){
        //     if(!vis[i]){
        //         bool chk = CycleDFS(i, vis, path, adj);

        //         if(chk){
        //             return true;
        //         }
        //     }
        // }

        vector<int> indegree(V, 0);
        for (vector<int> &i : adj)
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

        int cnt = 0; // no. of vertices processed
        int i = 0;
        while (!q.empty())
        {
            int frnt = q.front();
            q.pop();

            cnt++;

            for (int nebr : adj[frnt])
            {
                indegree[nebr]--;

                if (indegree[nebr] == 0)
                {
                    q.push(nebr);
                }
            }
        }

        if (cnt == V)
        {
            return false;
        }
        else
        {                // couldn't process all nodes
            return true; // cycle exists
        }
    }
};

// DFS - Recursive Stack OR Kahn's Algorithm
// TC = O(V + E), V = vertices in graph, E = edges in graph
// SC = O(V + E), adj takes V+E space & others take V space