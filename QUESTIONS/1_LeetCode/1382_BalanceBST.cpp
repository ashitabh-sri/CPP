/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    void inorder(TreeNode *root, vector<TreeNode *> &iot)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left, iot);
        iot.push_back(root);
        inorder(root->right, iot);
    }
    TreeNode *balance(int s, int e, vector<TreeNode *> &iot)
    {
        if (s > e)
        {
            return nullptr;
        }

        int mid = (s + e) / 2;
        TreeNode *root = iot[mid];

        root->left = balance(s, mid - 1, iot);
        root->right = balance(mid + 1, e, iot);

        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<TreeNode *> iot;
        inorder(root, iot);
        int n = iot.size();

        TreeNode *ans = balance(0, n - 1, iot);

        return ans;
    }
};

// BST Inorder -> Sorted Order
// TC = O(n)
// SC = O(n)