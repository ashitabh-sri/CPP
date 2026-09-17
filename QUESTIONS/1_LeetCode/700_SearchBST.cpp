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
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *tem = root;
        while (tem)
        {
            if (tem->val == val)
            {
                return tem;
            }

            if (tem->val > val)
            {
                tem = tem->left;
            }
            else
            {
                tem = tem->right;
            }
        }

        return nullptr;
    }
};

// BST Search
// TC = O(h), O(logn) for Balanced BST, O(n) for Skewed BST
// SC = O(1)