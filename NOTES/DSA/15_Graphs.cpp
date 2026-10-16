#include <bits/stdc++.h>
using namespace std;

// Graph : a Non-linear DS consisting of Vertices (Nodes) connected by Edges.

class Graph // using and Adjacency List
{
public:
    // Adjacency List
    vector<vector<int>> adj;

    Graph(int n)
    {
        adj.resize(n); // creates all n vertices (including isolated ones)
    }

    void addEdge(int u, int v, bool dir) // add new edges to graph, dir tells if directed or not
    {
        adj[u].push_back(v);

        if (dir == 0) // for undirected graph
        {
            adj[v].push_back(u); // connect from both sides
        }
    }
    // TC = O(1) ammortized

    void printAdj() // print the adjacency list
    {
        for (int i = 0; i < (int)adj.size(); i++)
        {
            cout << i << " -> ";
            for (int j : adj[i])
            {
                cout << j << " ";
            }
            cout << '\n';
        }
    }
    // TC = O(V + E), V = no. of vertices, E = no. of edges

    // Breadth First Search
    void BFS()
    {
        vector<bool> vis(adj.size(), false); // default value as false

        // Handle disconnected components
        for (int i = 0; i < (int)adj.size(); i++)
        {
            if (!vis[i]) // process only non-visited nodes (prevents repeatition)
            {
                queue<int> q; // for order of nodes

                q.push(i);
                vis[i] = true;

                while (!q.empty())
                {
                    int frnt = q.front();
                    q.pop();

                    cout << frnt << " ";

                    for (int nebr : adj[frnt])
                    {
                        if (!vis[nebr])
                        {
                            vis[nebr] = true; // mark as visited
                            q.push(nebr);     // push into queue
                        }
                    }
                }
            }
        }
    }
    // TC = O(V + E)
    // TC = O(V), excluding adjacency list

    // Depth First Search
    void dfshelper(int cur, vector<bool> &vis)
    {
        vis[cur] = true;    // mark as visited
        cout << cur << " "; // process the node

        for (int nebr : adj[cur]) // iterate neighbour nodes
        {
            if (!vis[nebr]) // if unvisited
            {
                dfshelper(nebr, vis); // recursive call for DFS
            }
        }
    }
    void DFS()
    {
        vector<bool> vis(adj.size(), false);

        for (int i = 0; i < (int)adj.size(); i++) // all components of graph
        {
            if (!vis[i])
            {                      // if node is unvisited
                dfshelper(i, vis); // do DFS for node
            }
        }
    }
    // TC = O(V + E)
    // SC = O(V)
};

// Topological Sort : linear ordering of vertices in a Directed Acyclic Graph (DAG)
// such that for every directed edge u → v, vertex u appears before vertex v in the ordering.
// DFS approach
// BFS approach - Kahn’s Algorithm
// TC = O(V + E) for both
// SC = O(V), excluding adjacency list of O(V + E)
// Done in QUESTIONS/2_GFG/48

// Dijkstra's Algorithm : finds the shortest distance from a source vertex to all other vertices in a weighted graph
// Works only with non-negative edge weights
// Adjacency List + Min-Heap (priority_queue)
// TC = O((V + E) logV)
// SC = O(V), excluding adjacency list of O(V + E)
// Done in QUESTIONS/2_GFG/51

// Prim's Algorithm : finds the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph
// Greedily picks the Minimum-weight edge connecting the MST to an unvisited vertex
// Adjacency List + Min-Heap (priority_queue)
// TC = O((V + E) logV) = O(E logV)
// SC = O(V + E)
// Done in QUESTIONS/2_GFG/52

// Kruskal's Algorithm : finds the MST of a connected, undirected, weighted graph
// Greedily picks edges in Increasing order of weight, avoiding cycles
// Sorting + DSU (Disjoint Set Union / Union-Find)
// TC = O(E logE)
// SC = O(V)
// Done in QUESTIONS/2_GFG/53

// Tarjan's Bridge Algorithm : finds all bridges in an undirected graph
// Uses DFS + discovery time (dis[]) + lowest reachable discovery time (low[])
// If low[v] > dis[u], then edge (u, v) is a bridge
// TC = O(V + E)
// SC = O(V + E) including adjacency list
// Done in QUESTIONS/1_LeetCode/1192

// Kosaraju's Algorithm : finds all Strongly Connected Components (SCCs) in a directed graph
// Uses 2 DFS traversals + stack + reversed graph
// Reverse all edges to create the transpose graph
// TC = O(V + E)
// SC = O(V + E) including adjacency lists, stack, visited array, and recursion stack
// Done in QUESTIONS/2_GFG/55

// Bellman Ford Algorithm : finds shortest paths from a single source, even with negative edge weights
// Relaxes all edges V-1 times to guarantee shortest distances, if no reachable negative-weight cycle exists
// Performs one extra pass to detect a negative-weight cycle reachable from the source
// TC = O(V E)
// SC = O(V) for the distance array, excluding graph storage
// Done in QUESTIONS/2_GFG/56

int main()
{
    int n, m;

    cout << "Enter the no. of Nodes for Graph: ";
    cin >> n;

    cout << "Enter the no. of Edges: ";
    cin >> m;

    Graph g(n);

    cout << "Enter the Edges (0 to n-1): ";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // 0 for undirected graph, 1 for directed graph
    }

    cout << "\nAdjacency List:\n";
    g.printAdj();

    cout << "\nBFS Traversal of Graph:\n";
    g.BFS();

    cout << "\n\nDFS Traversal of Graph:\n";
    g.DFS();

    return 0;
}