// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Solution
{
    struct Node
    {
        int val;
        int row;
        int col;

        Node(int v, int r, int c)
        {
            val = v;
            row = r;
            col = c;
        }
    };
    struct Compare
    {
        bool operator()(Node a, Node b)
        {
            return a.val > b.val; // return a if a is bigger
        }
    };

public:
    vector<int> mergeArrays(vector<vector<int>> &mat)
    {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<Node, vector<Node>, Compare> mnh; // min heap

        for (int i = 0; i < n; i++)
        {
            mnh.push(Node(mat[i][0], i, 0)); // push first elements from each row
        }

        vector<int> ans;

        while (!mnh.empty())
        {
            Node tem = mnh.top(); // root of min heap
            mnh.pop();

            int val = tem.val;
            int row = tem.row;
            int col = tem.col;

            ans.push_back(val); // store the min element

            if (col + 1 < m)
            {
                mnh.push(Node(mat[row][col + 1], row, col + 1)); // push next element
            }
        }

        return ans;
    }
};

// Min Heap
// TC = O(k*logn), k = m*n
// SC = O(n)