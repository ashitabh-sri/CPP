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
    void flatten(TreeNode *root)
    {
        // Pre Order : N L R
        TreeNode *cur = root;
        while (cur) // visit each node
        {
            if (cur->left)
            {
                TreeNode *pre = cur->left;
                while (pre->right)
                {
                    pre = pre->right; // finding predecessor of cur
                }
                pre->right = cur->right; // connect pre to right subtree
                cur->right = cur->left;  // connect right pointer to left subtree
                cur->left = nullptr;     // disconnect left pointer to flatten
            }

            cur = cur->right; // traverse to next node
        }
    }
};

// Pattern : Morris Traversal of Pre Order
// TC = O(n)
// SC = O(1)