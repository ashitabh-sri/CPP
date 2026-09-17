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
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *cur = root;
        int ans = -1;

        while (cur)
        {
            if (cur->left == nullptr)
            {
                k--;
                if (k == 0)
                {
                    ans = cur->val;
                }

                cur = cur->right;
            }
            else
            {
                TreeNode *pre = cur->left;
                while (pre->right != nullptr && pre->right != cur)
                {
                    pre = pre->right;
                }

                if (pre->right == nullptr) // first time visiting
                {
                    pre->right = cur; // make temporary link to cur
                    cur = cur->left;  // start traversin left subtree
                }
                else // second time visiting
                {
                    pre->right = nullptr;

                    k--;
                    if (k == 0)
                    {
                        ans = cur->val;
                    }

                    cur = cur->right; // go to next node
                }
            }
        }

        return ans;
    }
};

// Morris Traversal Inorder
// TC = O(n)
// SC = O(1)