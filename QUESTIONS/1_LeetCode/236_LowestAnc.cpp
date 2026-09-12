/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *lefAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rigAns = lowestCommonAncestor(root->right, p, q);

        if (lefAns != nullptr && rigAns != nullptr)
        {
            return root;
        }
        if (lefAns != nullptr && rigAns == nullptr)
        {
            return lefAns;
        }
        if (lefAns == nullptr && rigAns != nullptr)
        {
            return rigAns;
        }

        return nullptr;
    }
};

// TC = O(n)
// SC = O(h)