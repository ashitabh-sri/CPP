/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
    bool solve(Node *root, int &k, int node, int &ans)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->data == node) // found the target node
        {
            return true;
        }

        bool fnd = solve(root->left, k, node, ans) || solve(root->right, k, node, ans);

        if (fnd)
        {
            k--; // decrement for kth ancestor

            if (k == 0) // found the ans node
            {
                ans = root->data;
                return false;
            }

            return true;
        }
        else
        {
            return false;
        }
    }

public:
    int kthAncestor(Node *root, int k, int node)
    {
        // code here
        int ans = -1;

        solve(root, k, node, ans);

        return ans;
    }
};

// TC = O(n)
// SC = O(h) = O(n)

// https://www.geeksforgeeks.org/problems/k-sum-paths/1