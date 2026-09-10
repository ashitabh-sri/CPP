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
    pair<int, int> diameter(TreeNode *root) // {diameter in edges, height in nodes}
    {
        if (root == nullptr)
        {
            return {0, 0};
        }

        pair<int, int> lef = diameter(root->left);
        pair<int, int> rig = diameter(root->right);

        int lefD = lef.first; // max diameter in left subtree
        int rigD = rig.first; // max diameter in right subtree
        // diameter thorugh node = left subtree height + right subtree
        int D = lef.second + rig.second;

        pair<int, int> ans;
        ans.first = max(max(lefD, rigD), D);          // maximum of left, right, through node's diameters
        ans.second = max(lef.second, rig.second) + 1; // taller subtree + node itself

        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return diameter(root).first;
    }
};

// TC = O(n)
// SC = O(h), h = height of tree