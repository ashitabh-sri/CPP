// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1

class Solution
{
    vector<int> parent, rank;
    int find(int e) // find parent of given vertex
    {
        // Base Case
        if (parent[e] == e) // self-loop -> root
        {
            return e; // vertex is parent
        }

        parent[e] = find(parent[e]); // Path Compression

        return parent[e]; // return the parent of vertex
    }
    void unionSet(int u, int v) // connect given two components
    {
        int pu = find(u); // parent vertex
        int pv = find(v); // of this vertex

        if (pu == pv) // same parent vertex -> already connected
        {
            return;
        }

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv; // update the parent vertex of lower rank
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++; // joining two same rank -> bigger component
        }
    }

public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        parent.resize(V); // track parent of vertex
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        rank.assign(V, 0); // track rank of vertex's parent

        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
             {
                 return a[2] < b[2]; // sort by increasing weight of edge
             });

        int sum = 0; // weight of MST
        int cnt = 0; // track no. of edges taken in MST

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (find(u) != find(v))
            {
                sum += wt; // weight of MST
                unionSet(u, v);
                cnt++;
            }

            if (cnt == V - 1) // MST contains V - 1 edges
            {
                break; // early exit
            }
        }

        return sum;
    }
};

// Kruskal's Algorithm - Sorting + DSU (Disjoint Set Union)
// TC = O(E logE) - Sort, DSU ~ O(1)
// SC = O(V), V = vertices in graph, E = edges in graph