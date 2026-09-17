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
    TreeNode *solve(vector<int> &preorder, int &i, int mx) // didn't need mn, because it's preorder of BST
    {
        if (i == preorder.size() || preorder[i] >= mx)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, i, root->val);
        root->right = solve(preorder, i, mx);

        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;

        return solve(preorder, i, 1001); // used the given constraints, otherwise INT_MAX
    }
};

// BST Preorder
// TC = O(n)
// SC = O(h)