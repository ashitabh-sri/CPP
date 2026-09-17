/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution
{
    // private by default
    struct info
    {
        // public by default
        bool isBST;
        int mn;
        int mx;
        int size;
    };
    info solve(Node *root, int &mxs)
    {
        info cur;

        // Base Condition
        if (root == nullptr)
        {
            cur.isBST = true;
            cur.mn = INT_MAX;
            cur.mx = INT_MIN;
            cur.size = 0;

            return cur;
        }

        info lefT = solve(root->left, mxs);
        info rigT = solve(root->right, mxs);

        if (lefT.isBST && rigT.isBST && root->data > lefT.mx && root->data < rigT.mn)
        {
            cur.isBST = true;
            cur.mx = max(root->data, rigT.mx);
            cur.mn = min(root->data, lefT.mn);
        }
        else
        {
            cur.isBST = false;
            cur.mn = INT_MAX;
            cur.mx = INT_MIN;
            cur.size = 0;
        }

        if (cur.isBST)
        {
            cur.size = lefT.size + rigT.size + 1;
            mxs = max(mxs, cur.size);
        }

        return cur;
    }

public:
    int largestBst(Node *root)
    {
        // code here
        int mxs = 0;

        solve(root, mxs);

        return mxs;
    }
};

// Postorder Tree DP (Bottom-Up DFS with Subtree Information)
// TC = O(n)
// SC = O(h)