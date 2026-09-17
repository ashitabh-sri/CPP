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
    bool chkBST(TreeNode *root, long long mn, long long mx)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val > mn && root->val < mx)
        {
            bool lef = chkBST(root->left, mn, root->val);
            bool rig = chkBST(root->right, root->val, mx);

            return lef && rig;
        }
        else
        {
            return false;
        }
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return chkBST(root, LLONG_MIN, LLONG_MAX);
    }
};

// TC = O(n)
// SC = O(h)