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
    pair<int, int> isBal(TreeNode *root) // {is balanced?, height}
    {
        if (root == nullptr)
        {
            return {true, 0};
        }

        pair<int, int> lef = isBal(root->left);
        pair<int, int> rig = isBal(root->right);

        int lefH = lef.second;
        int rigH = rig.second;
        bool chk = abs(lefH - rigH) <= 1;

        pair<int, int> ans;
        if (lef.first && rig.first && chk)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        ans.second = max(lefH, rigH) + 1;

        return ans;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return isBal(root).first;
    }
};

// TC = O(n), n = no. of nodes
// SC = O(h), h = height of tree